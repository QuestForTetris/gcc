/* Target code for NVPTX.
   Copyright (C) 2014-2015 Free Software Foundation, Inc.
   Contributed by Bernd Schmidt <bernds@codesourcery.com>

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#include "config.h"
#include <sstream>
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "cfghooks.h"
#include "tree.h"
#include "rtl.h"
#include "df.h"
#include "alias.h"
#include "insn-flags.h"
#include "output.h"
#include "insn-attr.h"
#include "insn-codes.h"
#include "flags.h"
#include "insn-config.h"
#include "expmed.h"
#include "dojump.h"
#include "explow.h"
#include "calls.h"
#include "emit-rtl.h"
#include "varasm.h"
#include "stmt.h"
#include "expr.h"
#include "regs.h"
#include "optabs.h"
#include "recog.h"
#include "timevar.h"
#include "tm_p.h"
#include "tm-preds.h"
#include "tm-constrs.h"
#include "langhooks.h"
#include "dbxout.h"
#include "target.h"
#include "diagnostic.h"
#include "cfgrtl.h"
#include "cfghooks.h"
#include "cfgloop.h"
#include "stor-layout.h"
#include "dumpfile.h"
#include "builtins.h"
#include "dominance.h"
#include "cfg.h"
#include "tree-cfg.h"
#include "omp-low.h"
#include "fold-const.h"
#include "stringpool.h"
#include "internal-fn.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimple-ssa.h"
#include "gimplify.h"
#include "tree-phinodes.h"
#include "ssa-iterators.h"
#include "tree-ssanames.h"
#include "tree-into-ssa.h"
#include "gomp-constants.h"
#include "gimple.h"

/* This file should be included last.  */
#include "target-def.h"

#define SHUFFLE_UP 0
#define SHUFFLE_DOWN 1
#define SHUFFLE_BFLY 2
#define SHUFFLE_IDX 3

/* Memory barrier levels.  */
#define BARRIER_SHARED 0
#define BARRIER_GLOBAL 1
#define BARRIER_SYS 2

/* Record the function decls we've written, and the libfuncs and function
   decls corresponding to them.  */
static std::stringstream func_decls;

struct declared_libfunc_hasher : ggc_cache_ptr_hash<rtx_def>
{
  static hashval_t hash (rtx x) { return htab_hash_pointer (x); }
  static bool equal (rtx a, rtx b) { return a == b; }
};

static GTY((cache))
  hash_table<declared_libfunc_hasher> *declared_libfuncs_htab;

struct tree_hasher : ggc_cache_ptr_hash<tree_node>
{
  static hashval_t hash (tree t) { return htab_hash_pointer (t); }
  static bool equal (tree a, tree b) { return a == b; }
};

static GTY((cache)) hash_table<tree_hasher> *declared_fndecls_htab;
static GTY((cache)) hash_table<tree_hasher> *needed_fndecls_htab;

/* Size of buffer needed to broadcast across workers.  This is used
   for both worker-neutering and worker broadcasting.   It is shared
   by all functions emitted.  The buffer is placed in shared memory.
   It'd be nice if PTX supported common blocks, because then this
   could be shared across TUs (taking the largest size).  */
static unsigned worker_bcast_hwm;
static unsigned worker_bcast_align;
#define worker_bcast_name "__worker_bcast"
static GTY(()) rtx worker_bcast_sym;

/* Global and shared lock variables.  Allocated at end of compilation,
   if used.  Again, PTX lacks common blocks, so we can't share across
   compilations.  */
#define LOCK_GLOBAL 0
#define LOCK_SHARED 1
#define LOCK_MAX    2
static const char *const lock_names[] = {"__global_lock", "__shared_lock"};
static const unsigned lock_space[] = {ADDR_SPACE_GLOBAL, ADDR_SPACE_SHARED};
static const unsigned lock_level[] = {BARRIER_GLOBAL, BARRIER_SHARED};
static GTY(()) rtx lock_syms[LOCK_MAX];
static bool lock_used[LOCK_MAX];

/* FIXME: Temporary workaround for worker locks.  */
static bool force_global_locks = true;

/* Size of buffer needed for worker reductions.  This has to be
   disjoing from the worker broadcast array, as both may be live
   concurrently.  */
static unsigned worker_red_hwm;
static unsigned worker_red_align;
#define worker_red_name "__worker_red"
static GTY(()) rtx worker_red_sym;

/* To process worker-level reductions we need a buffer in CTA local
   (.shared) memory.  As the number of loops per function and number
   of reductions per loop are likely to be small numbers, we use
   simple unsorted vectors to hold the mappings.  */

/* Mapping from a reduction to an offset within the worker reduction
   array.  */
typedef std::pair<unsigned, unsigned> var_red_t;

/* Mapping from loops within a function to lists of reductions on that
   loop.  */
struct loop_red
{
  unsigned id;  /* Loop ID.  */
  unsigned hwm;  /* Allocated worker buffer for this loop.  */
  auto_vec<var_red_t> vars;   /* Reduction variables of the loop.  */

  loop_red (unsigned id_)
  :id (id_), hwm (0) 
  {
  }
};

/* It would be nice to put this intp machine_function, but auto_vec
   pulls in too much other stuff.   */
static auto_vec<loop_red> loop_reds;

/* Allocate a new, cleared machine_function structure.  */

static struct machine_function *
nvptx_init_machine_status (void)
{
  struct machine_function *p = ggc_cleared_alloc<machine_function> ();
  p->ret_reg_mode = VOIDmode;
  return p;
}

/* Implement TARGET_OPTION_OVERRIDE.  */

static void
nvptx_option_override (void)
{
  init_machine_status = nvptx_init_machine_status;
  /* Gives us a predictable order, which we need especially for variables.  */
  flag_toplevel_reorder = 1;
  /* Assumes that it will see only hard registers.  */
  flag_var_tracking = 0;
  write_symbols = NO_DEBUG;
  debug_info_level = DINFO_LEVEL_NONE;

  if (nvptx_optimize < 0)
    nvptx_optimize = optimize > 0;

  declared_fndecls_htab = hash_table<tree_hasher>::create_ggc (17);
  needed_fndecls_htab = hash_table<tree_hasher>::create_ggc (17);
  declared_libfuncs_htab
    = hash_table<declared_libfunc_hasher>::create_ggc (17);

  worker_bcast_sym = gen_rtx_SYMBOL_REF (Pmode, worker_bcast_name);
  worker_bcast_align = GET_MODE_ALIGNMENT (SImode) / BITS_PER_UNIT;

  worker_red_sym = gen_rtx_SYMBOL_REF (Pmode, worker_red_name);
  worker_red_align = GET_MODE_ALIGNMENT (SImode) / BITS_PER_UNIT;

  for (unsigned ix = LOCK_MAX; ix--;)
    lock_syms[ix] = gen_rtx_SYMBOL_REF (Pmode, lock_names[ix]);
}

/* Return the mode to be used when declaring a ptx object for OBJ.
   For objects with subparts such as complex modes this is the mode
   of the subpart.  */

machine_mode
nvptx_underlying_object_mode (rtx obj)
{
  if (GET_CODE (obj) == SUBREG)
    obj = SUBREG_REG (obj);
  machine_mode mode = GET_MODE (obj);
  if (mode == TImode)
    return DImode;
  if (COMPLEX_MODE_P (mode))
    return GET_MODE_INNER (mode);
  return mode;
}

/* Return a ptx type for MODE.  If PROMOTE, then use .u32 for QImode to
   deal with ptx ideosyncracies.  */

const char *
nvptx_ptx_type_from_mode (machine_mode mode, bool promote)
{
  switch (mode)
    {
    case BLKmode:
      return ".b8";
    case BImode:
      return ".pred";
    case QImode:
      if (promote)
	return ".u32";
      else
	return ".u8";
    case HImode:
      return ".u16";
    case SImode:
      return ".u32";
    case DImode:
      return ".u64";

    case SFmode:
      return ".f32";
    case DFmode:
      return ".f64";

    default:
      gcc_unreachable ();
    }
}

/* Return the number of pieces to use when dealing with a pseudo of *PMODE.
   Alter *PMODE if we return a number greater than one.  */

static int
maybe_split_mode (machine_mode *pmode)
{
  machine_mode mode = *pmode;

  if (COMPLEX_MODE_P (mode))
    {
      *pmode = GET_MODE_INNER (mode);
      return 2;
    }
  else if (mode == TImode)
    {
      *pmode = DImode;
      return 2;
    }
  return 1;
}

/* Like maybe_split_mode, but only return whether or not the mode
   needs to be split.  */
static bool
nvptx_split_reg_p (machine_mode mode)
{
  if (COMPLEX_MODE_P (mode))
    return true;
  if (mode == TImode)
    return true;
  return false;
}

/* Emit forking instructions for MASK.  */

static void
nvptx_emit_forking (unsigned mask, bool is_call)
{
  mask &= (GOMP_DIM_MASK (GOMP_DIM_WORKER)
	   | GOMP_DIM_MASK (GOMP_DIM_VECTOR));
  if (mask)
    {
      rtx op = GEN_INT (mask | (is_call << GOMP_DIM_MAX));
      
      /* Emit fork for worker level.  */
      if (!is_call && mask & GOMP_DIM_MASK (GOMP_DIM_WORKER))
	emit_insn (gen_nvptx_fork (op));
      emit_insn (gen_nvptx_forked (op));
    }
}

/* Emit joining instructions for MASK.  */

static void
nvptx_emit_joining (unsigned mask, bool is_call)
{
  mask &= (GOMP_DIM_MASK (GOMP_DIM_WORKER)
	   | GOMP_DIM_MASK (GOMP_DIM_VECTOR));
  if (mask)
    {
      rtx op = GEN_INT (mask | (is_call << GOMP_DIM_MAX));

      /* Emit joining for all non-call pars to ensure there's a single
	 predecessor for the block the join insn ends up in.  This is
	 needed for skipping entire loops.  */
      if (!is_call)
	emit_insn (gen_nvptx_joining (op));
      emit_insn (gen_nvptx_join (op));
    }
}

#define PASS_IN_REG_P(MODE, TYPE)				\
  ((GET_MODE_CLASS (MODE) == MODE_INT				\
    || GET_MODE_CLASS (MODE) == MODE_FLOAT			\
    || ((GET_MODE_CLASS (MODE) == MODE_COMPLEX_INT		\
	 || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)	\
	&& !AGGREGATE_TYPE_P (TYPE)))				\
   && (MODE) != TImode)

#define RETURN_IN_REG_P(MODE)			\
  ((GET_MODE_CLASS (MODE) == MODE_INT		\
    || GET_MODE_CLASS (MODE) == MODE_FLOAT)	\
   && GET_MODE_SIZE (MODE) <= 8)

/* Perform a mode promotion for a function argument with MODE.  Return
   the promoted mode.  */

static machine_mode
arg_promotion (machine_mode mode)
{
  if (mode == QImode || mode == HImode)
    return SImode;
  return mode;
}

/* Write the declaration of a function arg of TYPE to S.  I is the index
   of the argument, MODE its mode.  NO_ARG_TYPES is true if this is for
   a decl with zero TYPE_ARG_TYPES, i.e. an old-style C decl.  */

static int
write_one_arg (std::stringstream &s, tree type, int i, machine_mode mode,
	       bool no_arg_types)
{
  if (!PASS_IN_REG_P (mode, type))
    mode = Pmode;

  int count = maybe_split_mode (&mode);

  if (count == 2)
    {
      write_one_arg (s, NULL_TREE, i, mode, false);
      write_one_arg (s, NULL_TREE, i + 1, mode, false);
      return i + 1;
    }

  if (no_arg_types && !AGGREGATE_TYPE_P (type))
    {
      if (mode == SFmode)
	mode = DFmode;
      mode = arg_promotion (mode);
    }

  if (i > 0)
    s << ", ";
  s << ".param" << nvptx_ptx_type_from_mode (mode, false) << " %in_ar"
    << (i + 1) << (mode == QImode || mode == HImode ? "[1]" : "");
  if (mode == BLKmode)
    s << "[" << int_size_in_bytes (type) << "]";
  return i;
}

/* Look for attributes in ATTRS that would indicate we must write a function
   as a .entry kernel rather than a .func.  Return true if one is found.  */

static bool
write_as_kernel (tree attrs)
{
  return (lookup_attribute ("kernel", attrs) != NULL_TREE
	  || lookup_attribute ("omp target entrypoint", attrs) != NULL_TREE);
}

/* Write a function decl for DECL to S, where NAME is the name to be used.
   This includes ptx .visible or .extern specifiers, .func or .kernel, and
   argument and return types.  */

static void
nvptx_write_function_decl (std::stringstream &s, const char *name, const_tree decl)
{
  tree fntype = TREE_TYPE (decl);
  tree result_type = TREE_TYPE (fntype);
  tree args = TYPE_ARG_TYPES (fntype);
  tree attrs = DECL_ATTRIBUTES (decl);
  bool kernel = write_as_kernel (attrs);
  bool is_main = strcmp (name, "main") == 0;
  bool args_from_decl = false;

  /* We get:
     NULL in TYPE_ARG_TYPES, for old-style functions
     NULL in DECL_ARGUMENTS, for builtin functions without another
       declaration.
     So we have to pick the best one we have.  */
  if (args == 0)
    {
      args = DECL_ARGUMENTS (decl);
      args_from_decl = true;
    }

  if (DECL_EXTERNAL (decl))
    s << ".extern ";
  else if (TREE_PUBLIC (decl))
    s << ".visible ";

  if (kernel)
    s << ".entry ";
  else
    s << ".func ";

  /* Declare the result.  */
  bool return_in_mem = false;
  if (TYPE_MODE (result_type) != VOIDmode)
    {
      machine_mode mode = TYPE_MODE (result_type);
      if (!RETURN_IN_REG_P (mode))
	return_in_mem = true;
      else
	{
	  mode = arg_promotion (mode);
	  s << "(.param" << nvptx_ptx_type_from_mode (mode, false)
	    << " %out_retval)";
	}
    }

  if (name[0] == '*')
    s << (name + 1);
  else
    s << name;

  /* Declare argument types.  */
  if ((args != NULL_TREE
       && !(TREE_CODE (args) == TREE_LIST
	    && TREE_VALUE (args) == void_type_node))
      || is_main
      || return_in_mem
      || DECL_STATIC_CHAIN (decl))
    {
      s << "(";
      int i = 0;
      bool any_args = false;
      if (return_in_mem)
	{
	  s << ".param.u" << GET_MODE_BITSIZE (Pmode) << " %in_ar1";
	  i++;
	}
      while (args != NULL_TREE)
	{
	  tree type = args_from_decl ? TREE_TYPE (args) : TREE_VALUE (args);
	  machine_mode mode = TYPE_MODE (type);

	  if (mode != VOIDmode)
	    {
	      i = write_one_arg (s, type, i, mode,
				 TYPE_ARG_TYPES (fntype) == 0);
	      any_args = true;
	      i++;
	    }
	  args = TREE_CHAIN (args);
	}
      if (stdarg_p (fntype))
	{
	  gcc_assert (i > 0);
	  s << ", .param.u" << GET_MODE_BITSIZE (Pmode) << " %in_argp";
	}
      if (DECL_STATIC_CHAIN (decl))
	{
	  if (i > 0)
	    s << ", ";
	  s << ".reg.u" << GET_MODE_BITSIZE (Pmode)
	    << reg_names [STATIC_CHAIN_REGNUM];
	}
      if (!any_args && is_main)
	s << ".param.u32 %argc, .param.u" << GET_MODE_BITSIZE (Pmode)
	  << " %argv";
      s << ")";
    }
}

/* Walk either ARGTYPES or ARGS if the former is null, and write out part of
   the function header to FILE.  If WRITE_COPY is false, write reg
   declarations, otherwise write the copy from the incoming argument to that
   reg.  RETURN_IN_MEM indicates whether to start counting arg numbers at 1
   instead of 0.  */

static void
walk_args_for_param (FILE *file, tree argtypes, tree args, bool write_copy,
		     bool return_in_mem)
{
  int i;

  bool args_from_decl = false;
  if (argtypes == 0)
    args_from_decl = true;
  else
    args = argtypes;

  for (i = return_in_mem ? 1 : 0; args != NULL_TREE; args = TREE_CHAIN (args))
    {
      tree type = args_from_decl ? TREE_TYPE (args) : TREE_VALUE (args);
      machine_mode mode = TYPE_MODE (type);

      if (mode == VOIDmode)
	break;

      if (!PASS_IN_REG_P (mode, type))
	mode = Pmode;

      int count = maybe_split_mode (&mode);
      if (count == 1)
	{
	  if (argtypes == NULL && !AGGREGATE_TYPE_P (type))
	    {
	      if (mode == SFmode)
		mode = DFmode;

	    }
	}
      mode = arg_promotion (mode);
      while (count-- > 0)
	{
	  i++;
	  if (write_copy)
	    fprintf (file, "\tld.param%s %%ar%d, [%%in_ar%d];\n",
		     nvptx_ptx_type_from_mode (mode, false), i, i);
	  else
	    fprintf (file, "\t.reg%s %%ar%d;\n",
		     nvptx_ptx_type_from_mode (mode, false), i);
	}
    }
}

/* Write a .func or .kernel declaration (not a definition) along with
   a helper comment for use by ld.  S is the stream to write to, DECL
   the decl for the function with name NAME.  */

static void
write_function_decl_and_comment (std::stringstream &s, const char *name, const_tree decl)
{
  s << "// BEGIN";
  if (TREE_PUBLIC (decl))
    s << " GLOBAL";
  s << " FUNCTION DECL: ";
  if (name[0] == '*')
    s << (name + 1);
  else
    s << name;
  s << "\n";
  nvptx_write_function_decl (s, name, decl);
  s << ";\n";
}

/* Check NAME for special function names and redirect them by returning a
   replacement.  This applies to malloc, free and realloc, for which we
   want to use libgcc wrappers, and call, which triggers a bug in ptxas.  */

static const char *
nvptx_name_replacement (const char *name)
{
  if (strcmp (name, "call") == 0)
    return "__nvptx_call";
  if (strcmp (name, "malloc") == 0)
    return "__nvptx_malloc";
  if (strcmp (name, "free") == 0)
    return "__nvptx_free";
  if (strcmp (name, "realloc") == 0)
    return "__nvptx_realloc";
  return name;
}

/* If DECL is a FUNCTION_DECL, check the hash table to see if we
   already encountered it, and if not, insert it and write a ptx
   declarations that will be output at the end of compilation.  */

static bool
nvptx_record_fndecl (tree decl, bool force = false)
{
  if (decl == NULL_TREE || TREE_CODE (decl) != FUNCTION_DECL
      || !DECL_EXTERNAL (decl))
    return true;

  if (!force && TYPE_ARG_TYPES (TREE_TYPE (decl)) == NULL_TREE)
    return false;

  tree *slot = declared_fndecls_htab->find_slot (decl, INSERT);
  if (*slot == NULL)
    {
      *slot = decl;
      const char *name = get_fnname_from_decl (decl);
      name = nvptx_name_replacement (name);
      write_function_decl_and_comment (func_decls, name, decl);
    }
  return true;
}

/* Record that we need to emit a ptx decl for DECL.  Either do it now, or
   record it for later in case we have no argument information at this
   point.  */

void
nvptx_record_needed_fndecl (tree decl)
{
  if (nvptx_record_fndecl (decl))
    return;

  tree *slot = needed_fndecls_htab->find_slot (decl, INSERT);
  if (*slot == NULL)
    *slot = decl;
}

/* Emit code to initialize the REGNO predicate register to indicate
   whether we are not lane zero on the NAME axis.  */

static void
nvptx_init_axis_predicate (FILE *file, int regno, const char *name)
{
  fprintf (file, "\t{\n");
      
  fprintf (file, "\t.reg.u32\t%%%s;\n", name);
  fprintf (file, "\t\tmov.u32\t%%%s, %%tid.%s;\n", name, name);
  fprintf (file, "\t\tsetp.ne.u32\t%%r%d, %%%s, 0;\n", regno, name);
  fprintf (file, "\t}\n");
}

/* Implement ASM_DECLARE_FUNCTION_NAME.  Writes the start of a ptx
   function, including local var decls and copies from the arguments to
   local regs.  */

void
nvptx_declare_function_name (FILE *file, const char *name, const_tree decl)
{
  tree fntype = TREE_TYPE (decl);
  tree result_type = TREE_TYPE (fntype);

  name = nvptx_name_replacement (name);

  std::stringstream s;
  write_function_decl_and_comment (s, name, decl);
  s << "// BEGIN";
  if (TREE_PUBLIC (decl))
    s << " GLOBAL";
  s << " FUNCTION DEF: ";

  if (name[0] == '*')
    s << (name + 1);
  else
    s << name;
  s << "\n";

  nvptx_write_function_decl (s, name, decl);
  fprintf (file, "%s", s.str().c_str());

  bool return_in_mem = false;
  if (TYPE_MODE (result_type) != VOIDmode)
    {
      machine_mode mode = TYPE_MODE (result_type);
      if (!RETURN_IN_REG_P (mode))
	return_in_mem = true;
    }

  fprintf (file, "\n{\n");

  /* Ensure all arguments that should live in a register have one
     declared.  We'll emit the copies below.  */
  walk_args_for_param (file, TYPE_ARG_TYPES (fntype), DECL_ARGUMENTS (decl),
		       false, return_in_mem);
  if (return_in_mem)
    fprintf (file, "\t.reg.u%d %%ar1;\n", GET_MODE_BITSIZE (Pmode));
  else if (TYPE_MODE (result_type) != VOIDmode)
    {
      machine_mode mode = arg_promotion (TYPE_MODE (result_type));
      fprintf (file, "\t.reg%s %%retval;\n",
	       nvptx_ptx_type_from_mode (mode, false));
    }

  if (stdarg_p (fntype))
    fprintf (file, "\t.reg.u%d %%argp;\n", GET_MODE_BITSIZE (Pmode));

  fprintf (file, "\t.reg.u%d %s;\n", GET_MODE_BITSIZE (Pmode),
	   reg_names[OUTGOING_STATIC_CHAIN_REGNUM]);

  /* Declare the pseudos we have as ptx registers.  */
  int maxregs = max_reg_num ();
  for (int i = LAST_VIRTUAL_REGISTER + 1; i < maxregs; i++)
    {
      if (regno_reg_rtx[i] != const0_rtx)
	{
	  machine_mode mode = PSEUDO_REGNO_MODE (i);
	  int count = maybe_split_mode (&mode);
	  if (count > 1)
	    {
	      while (count-- > 0)
		fprintf (file, "\t.reg%s %%r%d$%d;\n",
			 nvptx_ptx_type_from_mode (mode, true),
			 i, count);
	    }
	  else
	    fprintf (file, "\t.reg%s %%r%d;\n",
		     nvptx_ptx_type_from_mode (mode, true),
		     i);
	}
    }

  /* The only reason we might be using outgoing args is if we call a stdargs
     function.  Allocate the space for this.  If we called varargs functions
     without passing any variadic arguments, we'll see a reference to outargs
     even with a zero outgoing_args_size.  */
  HOST_WIDE_INT sz = crtl->outgoing_args_size;
  if (sz == 0)
    sz = 1;
  if (cfun->machine->has_call_with_varargs)
    fprintf (file, "\t.reg.u%d %%outargs;\n"
	     "\t.local.align 8 .b8 %%outargs_ar[" HOST_WIDE_INT_PRINT_DEC"];\n",
	     BITS_PER_WORD, sz);
  if (cfun->machine->punning_buffer_size > 0)
    fprintf (file, "\t.reg.u%d %%punbuffer;\n"
	     "\t.local.align 8 .b8 %%punbuffer_ar[%d];\n",
	     BITS_PER_WORD, cfun->machine->punning_buffer_size);

  /* Declare a local variable for the frame.  */
  sz = get_frame_size ();
  if (sz > 0 || cfun->machine->has_call_with_sc)
    {
      int alignment = crtl->stack_alignment_needed / BITS_PER_UNIT;

      fprintf (file, "\t.reg.u%d %%frame;\n"
	       "\t.local.align %d .b8 %%farray[" HOST_WIDE_INT_PRINT_DEC"];\n",
	       BITS_PER_WORD, alignment, sz == 0 ? 1 : sz);
      fprintf (file, "\tcvta.local.u%d %%frame, %%farray;\n",
	       BITS_PER_WORD);
    }

  if (cfun->machine->has_call_with_varargs)
      fprintf (file, "\tcvta.local.u%d %%outargs, %%outargs_ar;\n",
	       BITS_PER_WORD);
  if (cfun->machine->punning_buffer_size > 0)
      fprintf (file, "\tcvta.local.u%d %%punbuffer, %%punbuffer_ar;\n",
	       BITS_PER_WORD);

  /* Now emit any copies necessary for arguments.  */
  walk_args_for_param (file, TYPE_ARG_TYPES (fntype), DECL_ARGUMENTS (decl),
		       true, return_in_mem);
  if (return_in_mem)
    fprintf (file, "\tld.param.u%d %%ar1, [%%in_ar1];\n",
	     GET_MODE_BITSIZE (Pmode));
  if (stdarg_p (fntype))
    fprintf (file, "\tld.param.u%d %%argp, [%%in_argp];\n",
	     GET_MODE_BITSIZE (Pmode));

  /* Emit axis predicates. */
  if (cfun->machine->axis_predicate[0])
    nvptx_init_axis_predicate (file,
			       REGNO (cfun->machine->axis_predicate[0]), "y");
  if (cfun->machine->axis_predicate[1])
    nvptx_init_axis_predicate (file,
			       REGNO (cfun->machine->axis_predicate[1]), "x");
}

/* Output a return instruction.  Also copy the return value to its outgoing
   location.  */

const char *
nvptx_output_return (void)
{
  tree fntype = TREE_TYPE (current_function_decl);
  tree result_type = TREE_TYPE (fntype);
  if (TYPE_MODE (result_type) != VOIDmode)
    {
      machine_mode mode = TYPE_MODE (result_type);
      if (RETURN_IN_REG_P (mode))
	{
	  mode = arg_promotion (mode);
	  fprintf (asm_out_file, "\tst.param%s\t[%%out_retval], %%retval;\n",
		   nvptx_ptx_type_from_mode (mode, false));
	}
    }

  return "ret;";
}

/* Construct a function declaration from a call insn.  This can be
   necessary for two reasons - either we have an indirect call which
   requires a .callprototype declaration, or we have a libcall
   generated by emit_library_call for which no decl exists.  */

static void
write_func_decl_from_insn (std::stringstream &s, rtx result, rtx pat,
			   rtx callee)
{
  bool callprototype = register_operand (callee, Pmode);
  const char *name = "_";
  if (!callprototype)
    {
      name = XSTR (callee, 0);
      name = nvptx_name_replacement (name);
      s << "// BEGIN GLOBAL FUNCTION DECL: " << name << "\n";
    }
  s << (callprototype ? "\t.callprototype\t" : "\t.extern .func ");

  if (result != NULL_RTX)
    {
      s << "(.param";
      s << nvptx_ptx_type_from_mode (arg_promotion (GET_MODE (result)),
				     false);
      s << " ";
      if (callprototype)
	s << "_";
      else
	s << "%out_retval";
      s << ")";
    }

  s << name;

  int arg_end = XVECLEN (pat, 0);
      
  if (1 < arg_end)
    {
      const char *comma = "";
      s << " (";
      for (int i = 1; i < arg_end; i++)
	{
	  rtx t = XEXP (XVECEXP (pat, 0, i), 0);
	  machine_mode mode = GET_MODE (t);
	  int count = maybe_split_mode (&mode);

	  while (count--)
	    {
	      s << comma << ".param";
	      s << nvptx_ptx_type_from_mode (mode, false);
	      s << " ";
	      if (callprototype)
		s << "_";
	      else
		s << "%arg" << i - 1;
	      if (mode == QImode || mode == HImode)
		s << "[1]";
	      comma = ", ";
	    }
	}
      s << ")";
    }
  s << ";\n";
}

/* Terminate a function by writing a closing brace to FILE.  */

void
nvptx_function_end (FILE *file)
{
  fprintf (file, "\t}\n");
}

/* Decide whether we can make a sibling call to a function.  For ptx, we
   can't.  */

static bool
nvptx_function_ok_for_sibcall (tree, tree)
{
  return false;
}

/* Return Dynamic ReAlignment Pointer RTX.  For PTX there isn't any.  */

static rtx
nvptx_get_drap_rtx (void)
{
  return NULL_RTX;
}

/* Implement the TARGET_CALL_ARGS hook.  Record information about one
   argument to the next call.  */

static void
nvptx_call_args (rtx arg, tree funtype)
{
  if (cfun->machine->start_call == NULL_RTX)
    {
      cfun->machine->call_args = NULL;
      cfun->machine->funtype = funtype;
      cfun->machine->start_call = const0_rtx;
    }
  if (arg == pc_rtx)
    return;

  rtx_expr_list *args_so_far = cfun->machine->call_args;
  if (REG_P (arg))
    cfun->machine->call_args = alloc_EXPR_LIST (VOIDmode, arg, args_so_far);
}

/* Implement the corresponding END_CALL_ARGS hook.  Clear and free the
   information we recorded.  */

static void
nvptx_end_call_args (void)
{
  cfun->machine->start_call = NULL_RTX;
  free_EXPR_LIST_list (&cfun->machine->call_args);
}

/* Emit the sequence for a call to ADDRESS, setting RETVAL.  Keep
   track of whether calls involving static chains or varargs were seen
   in the current function.
   For libcalls, maintain a hash table of decls we have seen, and
   record a function decl for later when encountering a new one.  */

void
nvptx_expand_call (rtx retval, rtx address)
{
  int nargs = 0;
  rtx callee = XEXP (address, 0);
  rtx pat, t;
  rtvec vec;
  bool external_decl = false;
  rtx varargs = NULL_RTX;
  tree decl_type = NULL_TREE;
  unsigned parallel = 0;

  for (t = cfun->machine->call_args; t; t = XEXP (t, 1))
    nargs++;

  if (!call_insn_operand (callee, Pmode))
    {
      callee = force_reg (Pmode, callee);
      address = change_address (address, QImode, callee);
    }

  if (GET_CODE (callee) == SYMBOL_REF)
    {
      tree decl = SYMBOL_REF_DECL (callee);
      if (decl != NULL_TREE)
	{
	  decl_type = TREE_TYPE (decl);
	  if (DECL_STATIC_CHAIN (decl))
	    cfun->machine->has_call_with_sc = true;
	  if (DECL_EXTERNAL (decl))
	    external_decl = true;
	  tree attr = get_oacc_fn_attrib (decl);
	  if (attr)
	    {
	      tree dims = TREE_VALUE (attr);

	      parallel = GOMP_DIM_MASK (GOMP_DIM_MAX) - 1;
	      for (int ix = 0; ix != GOMP_DIM_MAX; ix++)
		{
		  if (TREE_PURPOSE (dims)
		      && !integer_zerop (TREE_PURPOSE (dims)))
		    break;
		  /* Not on this axis.  */
		  parallel ^= GOMP_DIM_MASK (ix);
		  dims = TREE_CHAIN (dims);
		}
	    }
	}
    }

  if (cfun->machine->funtype
      /* It's possible to construct testcases where we call a variable.
	 See compile/20020129-1.c.  stdarg_p will crash so avoid calling it
	 in such a case.  */
      && (TREE_CODE (cfun->machine->funtype) == FUNCTION_TYPE
	  || TREE_CODE (cfun->machine->funtype) == METHOD_TYPE)
      && stdarg_p (cfun->machine->funtype))
    {
      varargs = gen_reg_rtx (Pmode);
      if (Pmode == DImode)
	emit_move_insn (varargs, stack_pointer_rtx);
      else
	emit_move_insn (varargs, stack_pointer_rtx);
      cfun->machine->has_call_with_varargs = true;
    }
  vec = rtvec_alloc (nargs + 1 + (varargs ? 1 : 0));
  pat = gen_rtx_PARALLEL (VOIDmode, vec);

  int vec_pos = 0;
  
  rtx tmp_retval = retval;
  t = gen_rtx_CALL (VOIDmode, address, const0_rtx);
  if (retval != NULL_RTX)
    {
      if (!nvptx_register_operand (retval, GET_MODE (retval)))
	tmp_retval = gen_reg_rtx (GET_MODE (retval));
      t = gen_rtx_SET (tmp_retval, t);
    }
  XVECEXP (pat, 0, vec_pos++) = t;

  /* Construct the call insn, including a USE for each argument pseudo
     register.  These will be used when printing the insn.  */
  for (rtx arg = cfun->machine->call_args; arg; arg = XEXP (arg, 1))
    {
      rtx this_arg = XEXP (arg, 0);
      XVECEXP (pat, 0, vec_pos++) = gen_rtx_USE (VOIDmode, this_arg);
    }

  if (varargs)
      XVECEXP (pat, 0, vec_pos++) = gen_rtx_USE (VOIDmode, varargs);

  gcc_assert (vec_pos = XVECLEN (pat, 0));

  /* If this is a libcall, decl_type is NULL. For a call to a non-libcall
     undeclared function, we'll have an external decl without arg types.
     In either case we have to try to construct a ptx declaration from one of
     the calls to the function.  */
  if (!REG_P (callee)
      && (decl_type == NULL_TREE
	  || (external_decl && TYPE_ARG_TYPES (decl_type) == NULL_TREE)))
    {
      rtx *slot = declared_libfuncs_htab->find_slot (callee, INSERT);
      if (*slot == NULL)
	{
	  *slot = callee;
	  write_func_decl_from_insn (func_decls, retval, pat, callee);
	}
    }
  nvptx_emit_forking (parallel, true);
  emit_call_insn (pat);
  nvptx_emit_joining (parallel, true);

  if (tmp_retval != retval)
    emit_move_insn (retval, tmp_retval);
}

/* Implement TARGET_FUNCTION_ARG.  */

static rtx
nvptx_function_arg (cumulative_args_t, machine_mode mode,
		    const_tree, bool named)
{
  if (mode == VOIDmode)
    return NULL_RTX;

  if (named)
    return gen_reg_rtx (mode);
  return NULL_RTX;
}

/* Implement TARGET_FUNCTION_INCOMING_ARG.  */

static rtx
nvptx_function_incoming_arg (cumulative_args_t cum_v, machine_mode mode,
			     const_tree, bool named)
{
  CUMULATIVE_ARGS *cum = get_cumulative_args (cum_v);
  if (mode == VOIDmode)
    return NULL_RTX;

  if (!named)
    return NULL_RTX;

  /* No need to deal with split modes here, the only case that can
     happen is complex modes and those are dealt with by
     TARGET_SPLIT_COMPLEX_ARG.  */
  return gen_rtx_UNSPEC (mode,
			 gen_rtvec (1, GEN_INT (1 + cum->count)),
			 UNSPEC_ARG_REG);
}

/* Implement TARGET_FUNCTION_ARG_ADVANCE.  */

static void
nvptx_function_arg_advance (cumulative_args_t cum_v, machine_mode mode,
			    const_tree type ATTRIBUTE_UNUSED,
			    bool named ATTRIBUTE_UNUSED)
{
  CUMULATIVE_ARGS *cum = get_cumulative_args (cum_v);
  if (mode == TImode)
    cum->count += 2;
  else
    cum->count++;
}

/* Handle the TARGET_STRICT_ARGUMENT_NAMING target hook.

   For nvptx, we know how to handle functions declared as stdarg: by
   passing an extra pointer to the unnamed arguments.  However, the
   Fortran frontend can produce a different situation, where a
   function pointer is declared with no arguments, but the actual
   function and calls to it take more arguments.  In that case, we
   want to ensure the call matches the definition of the function.  */

static bool
nvptx_strict_argument_naming (cumulative_args_t cum_v)
{
  CUMULATIVE_ARGS *cum = get_cumulative_args (cum_v);
  return cum->fntype == NULL_TREE || stdarg_p (cum->fntype);
}

/* Implement TARGET_FUNCTION_ARG_BOUNDARY.  */

static unsigned int
nvptx_function_arg_boundary (machine_mode mode, const_tree type)
{
  unsigned int boundary = type ? TYPE_ALIGN (type) : GET_MODE_BITSIZE (mode);

  if (boundary > BITS_PER_WORD)
    return 2 * BITS_PER_WORD;

  if (mode == BLKmode)
    {
      HOST_WIDE_INT size = int_size_in_bytes (type);
      if (size > 4)
        return 2 * BITS_PER_WORD;
      if (boundary < BITS_PER_WORD)
        {
          if (size >= 3)
            return BITS_PER_WORD;
          if (size >= 2)
            return 2 * BITS_PER_UNIT;
        }
    }
  return boundary;
}

/* TARGET_FUNCTION_VALUE implementation.  Returns an RTX representing the place
   where function FUNC returns or receives a value of data type TYPE.  */

static rtx
nvptx_function_value (const_tree type, const_tree func ATTRIBUTE_UNUSED,
		      bool outgoing)
{
  int unsignedp = TYPE_UNSIGNED (type);
  machine_mode orig_mode = TYPE_MODE (type);
  machine_mode mode = promote_function_mode (type, orig_mode,
					     &unsignedp, NULL_TREE, 1);
  if (outgoing)
    return gen_rtx_REG (mode, NVPTX_RETURN_REGNUM);
  if (cfun->machine->start_call == NULL_RTX)
    /* Pretend to return in a hard reg for early uses before pseudos can be
       generated.  */
    return gen_rtx_REG (mode, NVPTX_RETURN_REGNUM);
  return gen_reg_rtx (mode);
}

/* Implement TARGET_LIBCALL_VALUE.  */

static rtx
nvptx_libcall_value (machine_mode mode, const_rtx)
{
  if (cfun->machine->start_call == NULL_RTX)
    /* Pretend to return in a hard reg for early uses before pseudos can be
       generated.  */
    return gen_rtx_REG (mode, NVPTX_RETURN_REGNUM);
  return gen_reg_rtx (mode);
}

/* Implement TARGET_FUNCTION_VALUE_REGNO_P.  */

static bool
nvptx_function_value_regno_p (const unsigned int regno)
{
  return regno == NVPTX_RETURN_REGNUM;
}

/* Types with a mode other than those supported by the machine are passed by
   reference in memory.  */

static bool
nvptx_pass_by_reference (cumulative_args_t, machine_mode mode,
			 const_tree type, bool)
{
  return !PASS_IN_REG_P (mode, type);
}

/* Implement TARGET_RETURN_IN_MEMORY.  */

static bool
nvptx_return_in_memory (const_tree type, const_tree)
{
  machine_mode mode = TYPE_MODE (type);
  if (!RETURN_IN_REG_P (mode))
    return true;
  return false;
}

/* Implement TARGET_PROMOTE_FUNCTION_MODE.  */

static machine_mode
nvptx_promote_function_mode (const_tree type, machine_mode mode,
			     int *punsignedp,
			     const_tree funtype, int for_return)
{
  if (type == NULL_TREE)
    return mode;
  if (for_return)
    return promote_mode (type, mode, punsignedp);
  /* For K&R-style functions, try to match the language promotion rules to
     minimize type mismatches at assembly time.  */
  if (TYPE_ARG_TYPES (funtype) == NULL_TREE
      && type != NULL_TREE
      && !AGGREGATE_TYPE_P (type))
    {
      if (mode == SFmode)
	mode = DFmode;
      mode = arg_promotion (mode);
    }

  return mode;
}

/* Implement TARGET_STATIC_CHAIN.  */

static rtx
nvptx_static_chain (const_tree fndecl, bool incoming_p)
{
  if (!DECL_STATIC_CHAIN (fndecl))
    return NULL;

  if (incoming_p)
    return gen_rtx_REG (Pmode, STATIC_CHAIN_REGNUM);
  else
    return gen_rtx_REG (Pmode, OUTGOING_STATIC_CHAIN_REGNUM);
}

/* Emit a comparison COMPARE, and return the new test to be used in the
   jump.  */

rtx
nvptx_expand_compare (rtx compare)
{
  rtx pred = gen_reg_rtx (BImode);
  rtx cmp = gen_rtx_fmt_ee (GET_CODE (compare), BImode,
			    XEXP (compare, 0), XEXP (compare, 1));
  emit_insn (gen_rtx_SET (pred, cmp));
  return gen_rtx_NE (BImode, pred, const0_rtx);
}

/* Expand the oacc fork & join primitive into ptx-required unspecs.  */

void
nvptx_expand_oacc_fork (unsigned mode)
{
  nvptx_emit_forking (GOMP_DIM_MASK (mode), false);
}

void
nvptx_expand_oacc_join (unsigned mode)
{
  nvptx_emit_joining (GOMP_DIM_MASK (mode), false);
}

/* Expander for reduction locking and unlocking.  We expect SRC to be
   gang or worker level.  */

void
nvptx_expand_oacc_lock (rtx src, int direction)
{
  unsigned HOST_WIDE_INT kind;
  rtx pat;
  
  kind = INTVAL (src) == GOMP_DIM_GANG ? LOCK_GLOBAL : LOCK_SHARED;
  kind = force_global_locks ? LOCK_GLOBAL : kind;
  lock_used[kind] = true;

  rtx mem = gen_rtx_MEM (SImode, lock_syms[kind]);
  rtx space = GEN_INT (lock_space[kind]);
  rtx barrier = NULL_RTX;
  rtx tmp = gen_reg_rtx (SImode);

  if (direction >= 0)
    barrier = gen_nvptx_membar (GEN_INT (lock_level[kind]));

  if (direction > 0)
    emit_insn (barrier);
  if (!direction)
    {
      rtx_code_label *label = gen_label_rtx ();

      LABEL_NUSES (label)++;
      pat = gen_nvptx_spin_lock (mem, space, tmp, gen_reg_rtx (BImode), label);
    }
  else
    /* We can use reset for both unlock and initialization.  */
    pat = gen_nvptx_spin_reset (mem, space, tmp);
  emit_insn (pat);
  if (!direction)
    emit_insn (barrier);
}

/* Generate instruction(s) to unpack a 64 bit object into 2 32 bit
   objects.  */

static rtx
nvptx_gen_unpack (rtx dst0, rtx dst1, rtx src)
{
  rtx res;
  
  switch (GET_MODE (src))
    {
    case DImode:
      res = gen_unpackdisi2 (dst0, dst1, src);
      break;
    case DFmode:
      res = gen_unpackdfsi2 (dst0, dst1, src);
      break;
    default: gcc_unreachable ();
    }
  return res;
}

/* Generate instruction(s) to pack 2 32 bit objects into a 64 bit
   object.  */

static rtx
nvptx_gen_pack (rtx dst, rtx src0, rtx src1)
{
  rtx res;
  
  switch (GET_MODE (dst))
    {
    case DImode:
      res = gen_packsidi2 (dst, src0, src1);
      break;
    case DFmode:
      res = gen_packsidf2 (dst, src0, src1);
      break;
    default: gcc_unreachable ();
    }
  return res;
}

/* Generate an instruction or sequence to broadcast register REG
   across the vectors of a single warp.  */

static rtx
nvptx_gen_shuffle (rtx dst, rtx src, rtx idx, unsigned kind)
{
  rtx res;

  switch (GET_MODE (dst))
    {
    case SImode:
      res = gen_nvptx_shufflesi (dst, src, idx, GEN_INT (kind));
      break;
    case SFmode:
      res = gen_nvptx_shufflesf (dst, src, idx, GEN_INT (kind));
      break;
    case DImode:
    case DFmode:
      {
	rtx tmp0 = gen_reg_rtx (SImode);
	rtx tmp1 = gen_reg_rtx (SImode);

	start_sequence ();
	emit_insn (nvptx_gen_unpack (tmp0, tmp1, src));
	emit_insn (nvptx_gen_shuffle (tmp0, tmp0, idx, kind));
	emit_insn (nvptx_gen_shuffle (tmp1, tmp1, idx, kind));
	emit_insn (nvptx_gen_pack (dst, tmp0, tmp1));
	res = get_insns ();
	end_sequence ();
      }
      break;
    case BImode:
      {
	rtx tmp = gen_reg_rtx (SImode);
	
	start_sequence ();
	emit_insn (gen_sel_truesi (tmp, src, GEN_INT (1), const0_rtx));
	emit_insn (nvptx_gen_shuffle (tmp, tmp, idx, kind));
	emit_insn (gen_rtx_SET (dst, gen_rtx_NE (BImode, tmp, const0_rtx)));
	res = get_insns ();
	end_sequence ();
      }
      break;
      
    default:
      gcc_unreachable ();
    }
  return res;
}

/* Generate an instruction or sequence to broadcast register REG
   across the vectors of a single warp.  */

static rtx
nvptx_gen_vcast (rtx reg)
{
  return nvptx_gen_shuffle (reg, reg, const0_rtx, SHUFFLE_IDX);
}

/* Structure used when generating a worker-level spill or fill.  */

struct wcast_data_t
{
  rtx base;
  rtx ptr;
  unsigned offset;
};

/* Direction of the spill/fill and looping setup/teardown indicator.  */

enum propagate_mask
  {
    PM_read = 1 << 0,
    PM_write = 1 << 1,
    PM_loop_begin = 1 << 2,
    PM_loop_end = 1 << 3,

    PM_read_write = PM_read | PM_write
  };

/* Generate instruction(s) to spill or fill register REG to/from the
   worker broadcast array.  PM indicates what is to be done, REP
   how many loop iterations will be executed (0 for not a loop).  */
   
static rtx
nvptx_gen_wcast (rtx reg, propagate_mask pm, unsigned rep, wcast_data_t *data)
{
  rtx  res;
  machine_mode mode = GET_MODE (reg);

  switch (mode)
    {
    case BImode:
      {
	rtx tmp = gen_reg_rtx (SImode);
	
	start_sequence ();
	if (pm & PM_read)
	  emit_insn (gen_sel_truesi (tmp, reg, GEN_INT (1), const0_rtx));
	emit_insn (nvptx_gen_wcast (tmp, pm, rep, data));
	if (pm & PM_write)
	  emit_insn (gen_rtx_SET (reg, gen_rtx_NE (BImode, tmp, const0_rtx)));
	res = get_insns ();
	end_sequence ();
      }
      break;

    default:
      {
	rtx addr = data->ptr;

	if (!addr)
	  {
	    unsigned align = GET_MODE_ALIGNMENT (mode) / BITS_PER_UNIT;

	    if (align > worker_bcast_align)
	      worker_bcast_align = align;
	    data->offset = (data->offset + align - 1) & ~(align - 1);
	    addr = data->base;
	    if (data->offset)
	      addr = gen_rtx_PLUS (Pmode, addr, GEN_INT (data->offset));
	  }
	
	addr = gen_rtx_MEM (mode, addr);
	addr = gen_rtx_UNSPEC (mode, gen_rtvec (1, addr), UNSPEC_SHARED_DATA);
	if (pm == PM_read)
	  res = gen_rtx_SET (addr, reg);
	else if (pm == PM_write)
	  res = gen_rtx_SET (reg, addr);
	else
	  gcc_unreachable ();

	if (data->ptr)
	  {
	    /* We're using a ptr, increment it.  */
	    start_sequence ();
	    
	    emit_insn (res);
	    emit_insn (gen_adddi3 (data->ptr, data->ptr,
				   GEN_INT (GET_MODE_SIZE (GET_MODE (reg)))));
	    res = get_insns ();
	    end_sequence ();
	  }
	else
	  rep = 1;
	data->offset += rep * GET_MODE_SIZE (GET_MODE (reg));
      }
      break;
    }
  return res;
}

/* When loading an operand ORIG_OP, verify whether an address space
   conversion to generic is required, and if so, perform it.  Also
   check for SYMBOL_REFs for function decls and call
   nvptx_record_needed_fndecl as needed.
   Return either the original operand, or the converted one.  */

rtx
nvptx_maybe_convert_symbolic_operand (rtx orig_op)
{
  if (GET_MODE (orig_op) != Pmode)
    return orig_op;

  rtx op = orig_op;
  while (GET_CODE (op) == PLUS || GET_CODE (op) == CONST)
    op = XEXP (op, 0);
  if (GET_CODE (op) != SYMBOL_REF)
    return orig_op;

  tree decl = SYMBOL_REF_DECL (op);
  if (decl && TREE_CODE (decl) == FUNCTION_DECL)
    {
      nvptx_record_needed_fndecl (decl);
      return orig_op;
    }

  addr_space_t as = nvptx_addr_space_from_address (op);
  if (as == ADDR_SPACE_GENERIC)
    return orig_op;

  enum unspec code;
  code = (as == ADDR_SPACE_GLOBAL ? UNSPEC_FROM_GLOBAL
	  : as == ADDR_SPACE_LOCAL ? UNSPEC_FROM_LOCAL
	  : as == ADDR_SPACE_SHARED ? UNSPEC_FROM_SHARED
	  : as == ADDR_SPACE_CONST ? UNSPEC_FROM_CONST
	  : UNSPEC_FROM_PARAM);
  rtx dest = gen_reg_rtx (Pmode);
  emit_insn (gen_rtx_SET (dest, gen_rtx_UNSPEC (Pmode, gen_rtvec (1, orig_op),
						code)));
  return dest;
}

/* Returns true if X is a valid address for use in a memory reference.  */

static bool
nvptx_legitimate_address_p (machine_mode, rtx x, bool)
{
  enum rtx_code code = GET_CODE (x);

  switch (code)
    {
    case REG:
      return true;

    case PLUS:
      if (REG_P (XEXP (x, 0)) && CONST_INT_P (XEXP (x, 1)))
	return true;
      return false;

    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      return true;

    default:
      return false;
    }
}

/* Implement HARD_REGNO_MODE_OK.  We barely use hard regs, but we want
   to ensure that the return register's mode isn't changed.  */

bool
nvptx_hard_regno_mode_ok (int regno, machine_mode mode)
{
  if (regno != NVPTX_RETURN_REGNUM
      || cfun == NULL || cfun->machine->ret_reg_mode == VOIDmode)
    return true;
  return mode == cfun->machine->ret_reg_mode;
}

/* Convert an address space AS to the corresponding ptx string.  */

const char *
nvptx_section_from_addr_space (addr_space_t as)
{
  switch (as)
    {
    case ADDR_SPACE_CONST:
      return ".const";

    case ADDR_SPACE_GLOBAL:
      return ".global";

    case ADDR_SPACE_SHARED:
      return ".shared";

    case ADDR_SPACE_GENERIC:
      return "";

    default:
      gcc_unreachable ();
    }
}

/* Determine whether DECL goes into .const or .global.  */

const char *
nvptx_section_for_decl (const_tree decl)
{
  bool is_const = (CONSTANT_CLASS_P (decl)
		   || TREE_CODE (decl) == CONST_DECL
		   || TREE_READONLY (decl));
  if (is_const)
    return ".const";

  return ".global";
}

/* Look for a SYMBOL_REF in ADDR and return the address space to be used
   for the insn referencing this address.  */

addr_space_t
nvptx_addr_space_from_address (rtx addr)
{
  while (GET_CODE (addr) == PLUS || GET_CODE (addr) == CONST)
    addr = XEXP (addr, 0);
  if (GET_CODE (addr) != SYMBOL_REF)
    return ADDR_SPACE_GENERIC;

  tree decl = SYMBOL_REF_DECL (addr);
  if (decl == NULL_TREE || TREE_CODE (decl) == FUNCTION_DECL)
    return ADDR_SPACE_GENERIC;

  bool is_const = (CONSTANT_CLASS_P (decl)
		   || TREE_CODE (decl) == CONST_DECL
		   || TREE_READONLY (decl));
  if (is_const)
    return ADDR_SPACE_CONST;

  return ADDR_SPACE_GLOBAL;
}

/* Machinery to output constant initializers.  When beginning an initializer,
   we decide on a chunk size (which is visible in ptx in the type used), and
   then all initializer data is buffered until a chunk is filled and ready to
   be written out.  */

/* Used when assembling integers to ensure data is emitted in
   pieces whose size matches the declaration we printed.  */
static unsigned int decl_chunk_size;
static machine_mode decl_chunk_mode;
/* Used in the same situation, to keep track of the byte offset
   into the initializer.  */
static unsigned HOST_WIDE_INT decl_offset;
/* The initializer part we are currently processing.  */
static HOST_WIDE_INT init_part;
/* The total size of the object.  */
static unsigned HOST_WIDE_INT object_size;
/* True if we found a skip extending to the end of the object.  Used to
   assert that no data follows.  */
static bool object_finished;

/* Write the necessary separator string to begin a new initializer value.  */

static void
begin_decl_field (void)
{
  /* We never see decl_offset at zero by the time we get here.  */
  if (decl_offset == decl_chunk_size)
    fprintf (asm_out_file, " = { ");
  else
    fprintf (asm_out_file, ", ");
}

/* Output the currently stored chunk as an initializer value.  */

static void
output_decl_chunk (void)
{
  begin_decl_field ();
  output_address (gen_int_mode (init_part, decl_chunk_mode));
  init_part = 0;
}

/* Add value VAL sized SIZE to the data we're emitting, and keep writing
   out chunks as they fill up.  */

static void
nvptx_assemble_value (HOST_WIDE_INT val, unsigned int size)
{
  unsigned HOST_WIDE_INT chunk_offset = decl_offset % decl_chunk_size;
  gcc_assert (!object_finished);
  while (size > 0)
    {
      int this_part = size;
      if (chunk_offset + this_part > decl_chunk_size)
	this_part = decl_chunk_size - chunk_offset;
      HOST_WIDE_INT val_part;
      HOST_WIDE_INT mask = 2;
      mask <<= this_part * BITS_PER_UNIT - 1;
      val_part = val & (mask - 1);
      init_part |= val_part << (BITS_PER_UNIT * chunk_offset);
      val >>= BITS_PER_UNIT * this_part;
      size -= this_part;
      decl_offset += this_part;
      if (decl_offset % decl_chunk_size == 0)
	output_decl_chunk ();

      chunk_offset = 0;
    }
}

/* Target hook for assembling integer object X of size SIZE.  */

static bool
nvptx_assemble_integer (rtx x, unsigned int size, int ARG_UNUSED (aligned_p))
{
  if (GET_CODE (x) == SYMBOL_REF || GET_CODE (x) == CONST)
    {
      gcc_assert (size = decl_chunk_size);
      if (decl_offset % decl_chunk_size != 0)
	sorry ("cannot emit unaligned pointers in ptx assembly");
      decl_offset += size;
      begin_decl_field ();

      HOST_WIDE_INT off = 0;
      if (GET_CODE (x) == CONST)
	x = XEXP (x, 0);
      if (GET_CODE (x) == PLUS)
	{
	  off = INTVAL (XEXP (x, 1));
	  x = XEXP (x, 0);
	}
      if (GET_CODE (x) == SYMBOL_REF)
	{
	  nvptx_record_needed_fndecl (SYMBOL_REF_DECL (x));
	  fprintf (asm_out_file, "generic(");
	  output_address (x);
	  fprintf (asm_out_file, ")");
	}
      if (off != 0)
	fprintf (asm_out_file, " + " HOST_WIDE_INT_PRINT_DEC, off);
      return true;
    }

  HOST_WIDE_INT val;
  switch (GET_CODE (x))
    {
    case CONST_INT:
      val = INTVAL (x);
      break;
    case CONST_DOUBLE:
      gcc_unreachable ();
      break;
    default:
      gcc_unreachable ();
    }

  nvptx_assemble_value (val, size);
  return true;
}

/* Output SIZE zero bytes.  We ignore the FILE argument since the
   functions we're calling to perform the output just use
   asm_out_file.  */

void
nvptx_output_skip (FILE *, unsigned HOST_WIDE_INT size)
{
  if (decl_offset + size >= object_size)
    {
      if (decl_offset % decl_chunk_size != 0)
	nvptx_assemble_value (0, decl_chunk_size);
      object_finished = true;
      return;
    }

  while (size > decl_chunk_size)
    {
      nvptx_assemble_value (0, decl_chunk_size);
      size -= decl_chunk_size;
    }
  while (size-- > 0)
    nvptx_assemble_value (0, 1);
}

/* Output a string STR with length SIZE.  As in nvptx_output_skip we
   ignore the FILE arg.  */

void
nvptx_output_ascii (FILE *, const char *str, unsigned HOST_WIDE_INT size)
{
  for (unsigned HOST_WIDE_INT i = 0; i < size; i++)
    nvptx_assemble_value (str[i], 1);
}

/* Called when the initializer for a decl has been completely output through
   combinations of the three functions above.  */

static void
nvptx_assemble_decl_end (void)
{
  if (decl_offset != 0)
    {
      if (!object_finished && decl_offset % decl_chunk_size != 0)
	nvptx_assemble_value (0, decl_chunk_size);

      fprintf (asm_out_file, " }");
    }
  fprintf (asm_out_file, ";\n");
}

/* Start a declaration of a variable of TYPE with NAME to
   FILE.  IS_PUBLIC says whether this will be externally visible.
   Here we just write the linker hint and decide on the chunk size
   to use.  */

static void
init_output_initializer (FILE *file, const char *name, const_tree type,
			 bool is_public)
{
  fprintf (file, "// BEGIN%s VAR DEF: ", is_public ? " GLOBAL" : "");
  assemble_name_raw (file, name);
  fputc ('\n', file);

  if (TREE_CODE (type) == ARRAY_TYPE)
    type = TREE_TYPE (type);
  int sz = int_size_in_bytes (type);
  if ((TREE_CODE (type) != INTEGER_TYPE
       && TREE_CODE (type) != ENUMERAL_TYPE
       && TREE_CODE (type) != REAL_TYPE)
      || sz < 0
      || sz > HOST_BITS_PER_WIDE_INT)
    type = ptr_type_node;
  decl_chunk_size = int_size_in_bytes (type);
  decl_chunk_mode = int_mode_for_mode (TYPE_MODE (type));
  decl_offset = 0;
  init_part = 0;
  object_finished = false;
}

/* Implement TARGET_ASM_DECLARE_CONSTANT_NAME.  Begin the process of
   writing a constant variable EXP with NAME and SIZE and its
   initializer to FILE.  */

static void
nvptx_asm_declare_constant_name (FILE *file, const char *name,
				 const_tree exp, HOST_WIDE_INT size)
{
  tree type = TREE_TYPE (exp);
  init_output_initializer (file, name, type, false);
  fprintf (file, "\t.const .align %d .u%d ",
	   TYPE_ALIGN (TREE_TYPE (exp)) / BITS_PER_UNIT,
	   decl_chunk_size * BITS_PER_UNIT);
  assemble_name (file, name);
  fprintf (file, "[" HOST_WIDE_INT_PRINT_DEC "]",
	   (size + decl_chunk_size - 1) / decl_chunk_size);
  object_size = size;
}

/* Implement the ASM_DECLARE_OBJECT_NAME macro.  Used to start writing
   a variable DECL with NAME to FILE.  */

void
nvptx_declare_object_name (FILE *file, const char *name, const_tree decl)
{
  if (decl && DECL_SIZE (decl))
    {
      tree type = TREE_TYPE (decl);
      unsigned HOST_WIDE_INT size;

      init_output_initializer (file, name, type, TREE_PUBLIC (decl));
      size = tree_to_uhwi (DECL_SIZE_UNIT (decl));
      const char *section = nvptx_section_for_decl (decl);
      fprintf (file, "\t%s%s .align %d .u%d ",
	       TREE_PUBLIC (decl) ? " .visible" : "", section,
	       DECL_ALIGN (decl) / BITS_PER_UNIT,
	       decl_chunk_size * BITS_PER_UNIT);
      assemble_name (file, name);
      if (size > 0)
	fprintf (file, "[" HOST_WIDE_INT_PRINT_DEC "]",
		 (size + decl_chunk_size - 1) / decl_chunk_size);
      else
	object_finished = true;
      object_size = size;
    }
}

/* Implement TARGET_ASM_GLOBALIZE_LABEL by doing nothing.  */

static void
nvptx_globalize_label (FILE *, const char *)
{
}

/* Implement TARGET_ASM_ASSEMBLE_UNDEFINED_DECL.  Write an extern
   declaration only for variable DECL with NAME to FILE.  */
static void
nvptx_assemble_undefined_decl (FILE *file, const char *name, const_tree decl)
{
  if (TREE_CODE (decl) != VAR_DECL)
    return;
  const char *section = nvptx_section_for_decl (decl);
  fprintf (file, "// BEGIN%s VAR DECL: ", TREE_PUBLIC (decl) ? " GLOBAL" : "");
  assemble_name_raw (file, name);
  fputs ("\n", file);
  HOST_WIDE_INT size = int_size_in_bytes (TREE_TYPE (decl));
  fprintf (file, ".extern %s .b8 ", section);
  assemble_name_raw (file, name);
  if (size > 0)
    fprintf (file, "[" HOST_WIDE_INT_PRINT_DEC"]", size);
  fprintf (file, ";\n\n");
}

/* Output INSN, which is a call to CALLEE with result RESULT.  For ptx, this
   involves writing .param declarations and in/out copies into them.  For
   indirect calls, also write the .callprototype.  */

const char *
nvptx_output_call_insn (rtx_insn *insn, rtx result, rtx callee)
{
  char buf[256];
  static int labelno;
  bool needs_tgt = register_operand (callee, Pmode);
  rtx pat = PATTERN (insn);
  int arg_end = XVECLEN (pat, 0);
  tree decl = NULL_TREE;

  fprintf (asm_out_file, "\t{\n");
  if (result != NULL)
    fprintf (asm_out_file, "\t\t.param%s %%retval_in;\n",
	     nvptx_ptx_type_from_mode (arg_promotion (GET_MODE (result)),
				       false));

  /* Ensure we have a ptx declaration in the output if necessary.  */
  if (GET_CODE (callee) == SYMBOL_REF)
    {
      decl = SYMBOL_REF_DECL (callee);
      if (decl && DECL_EXTERNAL (decl))
	nvptx_record_fndecl (decl);
    }

  if (needs_tgt)
    {
      ASM_GENERATE_INTERNAL_LABEL (buf, "LCT", labelno);
      labelno++;
      ASM_OUTPUT_LABEL (asm_out_file, buf);
      std::stringstream s;
      write_func_decl_from_insn (s, result, pat, callee);
      fputs (s.str().c_str(), asm_out_file);
    }

  for (int i = 1, argno = 0; i < arg_end; i++)
    {
      rtx t = XEXP (XVECEXP (pat, 0, i), 0);
      machine_mode mode = GET_MODE (t);
      int count = maybe_split_mode (&mode);

      while (count--)
	fprintf (asm_out_file, "\t\t.param%s %%out_arg%d%s;\n",
		 nvptx_ptx_type_from_mode (mode, false), argno++,
		 mode == QImode || mode == HImode ? "[1]" : "");
    }
  for (int i = 1, argno = 0; i < arg_end; i++)
    {
      rtx t = XEXP (XVECEXP (pat, 0, i), 0);
      gcc_assert (REG_P (t));
      machine_mode mode = GET_MODE (t);
      int count = maybe_split_mode (&mode);

      if (count == 1)
	fprintf (asm_out_file, "\t\tst.param%s [%%out_arg%d], %%r%d;\n",
		 nvptx_ptx_type_from_mode (mode, false), argno++,
		 REGNO (t));
      else
	{
	  int n = 0;
	  while (count--)
	    fprintf (asm_out_file, "\t\tst.param%s [%%out_arg%d], %%r%d$%d;\n",
		     nvptx_ptx_type_from_mode (mode, false), argno++,
		     REGNO (t), n++);
	}
    }

  fprintf (asm_out_file, "\t\tcall ");
  if (result != NULL_RTX)
    fprintf (asm_out_file, "(%%retval_in), ");

  if (decl)
    {
      const char *name = get_fnname_from_decl (decl);
      name = nvptx_name_replacement (name);
      assemble_name (asm_out_file, name);
    }
  else
    output_address (callee);

  if (arg_end > 1 || (decl && DECL_STATIC_CHAIN (decl)))
    {
      const char *comma = "";
      
      fprintf (asm_out_file, ", (");
      for (int i = 1, argno = 0; i < arg_end; i++)
	{
	  rtx t = XEXP (XVECEXP (pat, 0, i), 0);
	  machine_mode mode = GET_MODE (t);
	  int count = maybe_split_mode (&mode);

	  while (count--)
	    {
	      fprintf (asm_out_file, "%s%%out_arg%d", comma, argno++);
	      comma = ", ";
	    }
	}
      if (decl && DECL_STATIC_CHAIN (decl))
	fprintf (asm_out_file, "%s%s", comma,
		 reg_names [OUTGOING_STATIC_CHAIN_REGNUM]);

      fprintf (asm_out_file, ")");
    }

  if (needs_tgt)
    {
      fprintf (asm_out_file, ", ");
      assemble_name (asm_out_file, buf);
    }
  fprintf (asm_out_file, ";\n");
  if (result != NULL_RTX)
    return "ld.param%t0\t%0, [%%retval_in];\n\t}";

  return "}";
}

/* Implement TARGET_PRINT_OPERAND_PUNCT_VALID_P.  */

static bool
nvptx_print_operand_punct_valid_p (unsigned char c)
{
  return c == '.' || c== '#';
}

static void nvptx_print_operand (FILE *, rtx, int);

/* Subroutine of nvptx_print_operand; used to print a memory reference X to FILE.  */

static void
nvptx_print_address_operand (FILE *file, rtx x, machine_mode)
{
  rtx off;
  if (GET_CODE (x) == CONST)
    x = XEXP (x, 0);
  switch (GET_CODE (x))
    {
    case PLUS:
      off = XEXP (x, 1);
      output_address (XEXP (x, 0));
      fprintf (file, "+");
      output_address (off);
      break;

    case SYMBOL_REF:
    case LABEL_REF:
      output_addr_const (file, x);
      break;

    default:
      gcc_assert (GET_CODE (x) != MEM);
      nvptx_print_operand (file, x, 0);
      break;
    }
}

/* Write assembly language output for the address ADDR to FILE.  */

static void
nvptx_print_operand_address (FILE *file, rtx addr)
{
  nvptx_print_address_operand (file, addr, VOIDmode);
}

/* Print an operand, X, to FILE, with an optional modifier in CODE.

   Meaning of CODE:
   . -- print the predicate for the instruction or an emptry string for an
        unconditional one.
   # -- print a rounding mode for the instruction

   A -- print an address space identifier for a MEM
   c -- print an opcode suffix for a comparison operator, including a type code
   f -- print a full reg even for something that must always be split
   B -- print a memory barrier level specified by CONST_INT
   R -- print an address space specified by CONST_INT
   S -- print a shuffle kind specified by CONST_INT
   t -- print a type opcode suffix, promoting QImode to 32 bits
   T -- print a type size in bits
   u -- print a type opcode suffix without promotions.  */

static void
nvptx_print_operand (FILE *file, rtx x, int code)
{
  rtx orig_x = x;
  machine_mode op_mode;

  if (code == '.')
    {
      x = current_insn_predicate;
      if (x)
	{
	  unsigned int regno = REGNO (XEXP (x, 0));
	  fputs ("[", file);
	  if (GET_CODE (x) == EQ)
	    fputs ("!", file);
	  fputs (reg_names [regno], file);
	  fputs ("]", file);
	}
      return;
    }
  else if (code == '#')
    {
      fputs (".rn", file);
      return;
    }

  enum rtx_code x_code = GET_CODE (x);

  switch (code)
    {
    case 'A':
      {
	addr_space_t as = nvptx_addr_space_from_address (XEXP (x, 0));
	fputs (nvptx_section_from_addr_space (as), file);
      }
      break;

    case 'B':
      {
	unsigned kind = UINTVAL (x);
	static const char *const kinds[] = 
	  {"cta", "gl", "sys"};
	fprintf (file, ".%s", kinds[kind]);
      }
      break;

    case 't':
      op_mode = nvptx_underlying_object_mode (x);
      fprintf (file, "%s", nvptx_ptx_type_from_mode (op_mode, true));
      break;

    case 'u':
      op_mode = nvptx_underlying_object_mode (x);
      fprintf (file, "%s", nvptx_ptx_type_from_mode (op_mode, false));
      break;

    case 'R':
      {
	addr_space_t as = UINTVAL (x);
	fputs (nvptx_section_from_addr_space (as), file);
      }
      break;

    case 'S':
      {
	unsigned kind = UINTVAL (x);
	static const char *const kinds[] = 
	  {"up", "down", "bfly", "idx"};
	fprintf (file, ".%s", kinds[kind]);
      }
      break;
      
    case 'T':
      fprintf (file, "%d", GET_MODE_BITSIZE (GET_MODE (x)));
      break;

    case 'j':
      fprintf (file, "@");
      goto common;

    case 'J':
      fprintf (file, "@!");
      goto common;

    case 'c':
      op_mode = GET_MODE (XEXP (x, 0));
      switch (x_code)
	{
	case EQ:
	  fputs (".eq", file);
	  break;
	case NE:
	  if (FLOAT_MODE_P (op_mode))
	    fputs (".neu", file);
	  else
	    fputs (".ne", file);
	  break;
	case LE:
	  fputs (".le", file);
	  break;
	case GE:
	  fputs (".ge", file);
	  break;
	case LT:
	  fputs (".lt", file);
	  break;
	case GT:
	  fputs (".gt", file);
	  break;
	case LEU:
	  fputs (".ls", file);
	  break;
	case GEU:
	  fputs (".hs", file);
	  break;
	case LTU:
	  fputs (".lo", file);
	  break;
	case GTU:
	  fputs (".hi", file);
	  break;
	case LTGT:
	  fputs (".ne", file);
	  break;
	case UNEQ:
	  fputs (".equ", file);
	  break;
	case UNLE:
	  fputs (".leu", file);
	  break;
	case UNGE:
	  fputs (".geu", file);
	  break;
	case UNLT:
	  fputs (".ltu", file);
	  break;
	case UNGT:
	  fputs (".gtu", file);
	  break;
	case UNORDERED:
	  fputs (".nan", file);
	  break;
	case ORDERED:
	  fputs (".num", file);
	  break;
	default:
	  gcc_unreachable ();
	}
      if (FLOAT_MODE_P (op_mode)
	  || x_code == EQ || x_code == NE
	  || x_code == GEU || x_code == GTU
	  || x_code == LEU || x_code == LTU)
	fputs (nvptx_ptx_type_from_mode (op_mode, true), file);
      else
	fprintf (file, ".s%d", GET_MODE_BITSIZE (op_mode));
      break;
    default:
    common:
      switch (x_code)
	{
	case SUBREG:
	  x = SUBREG_REG (x);
	  /* fall through */

	case REG:
	  if (HARD_REGISTER_P (x))
	    fprintf (file, "%s", reg_names[REGNO (x)]);
	  else
	    fprintf (file, "%%r%d", REGNO (x));
	  if (code != 'f' && nvptx_split_reg_p (GET_MODE (x)))
	    {
	      gcc_assert (GET_CODE (orig_x) == SUBREG
			  && !nvptx_split_reg_p (GET_MODE (orig_x)));
	      fprintf (file, "$%d", SUBREG_BYTE (orig_x) / UNITS_PER_WORD);
	    }
	  break;

	case MEM:
	  fputc ('[', file);
	  nvptx_print_address_operand (file, XEXP (x, 0), GET_MODE (x));
	  fputc (']', file);
	  break;

	case CONST_INT:
	  output_addr_const (file, x);
	  break;

	case CONST:
	case SYMBOL_REF:
	case LABEL_REF:
	  /* We could use output_addr_const, but that can print things like
	     "x-8", which breaks ptxas.  Need to ensure it is output as
	     "x+-8".  */
	  nvptx_print_address_operand (file, x, VOIDmode);
	  break;

	case CONST_DOUBLE:
	  long vals[2];
	  REAL_VALUE_TYPE real;
	  REAL_VALUE_FROM_CONST_DOUBLE (real, x);
	  real_to_target (vals, &real, GET_MODE (x));
	  vals[0] &= 0xffffffff;
	  vals[1] &= 0xffffffff;
	  if (GET_MODE (x) == SFmode)
	    fprintf (file, "0f%08lx", vals[0]);
	  else
	    fprintf (file, "0d%08lx%08lx", vals[1], vals[0]);
	  break;

	default:
	  output_addr_const (file, x);
	}
    }
}

/* Record replacement regs used to deal with subreg operands.  */
struct reg_replace
{
  rtx replacement[MAX_RECOG_OPERANDS];
  machine_mode mode;
  int n_allocated;
  int n_in_use;
};

/* Allocate or reuse a replacement in R and return the rtx.  */

static rtx
get_replacement (struct reg_replace *r)
{
  if (r->n_allocated == r->n_in_use)
    r->replacement[r->n_allocated++] = gen_reg_rtx (r->mode);
  return r->replacement[r->n_in_use++];
}

/* Clean up subreg operands.  In ptx assembly, everything is typed, and
   the presence of subregs would break the rules for most instructions.
   Replace them with a suitable new register of the right size, plus
   conversion copyin/copyout instructions.  */

static void
nvptx_reorg_subreg (void)
{
  struct reg_replace qiregs, hiregs, siregs, diregs;
  rtx_insn *insn, *next;

  qiregs.n_allocated = 0;
  hiregs.n_allocated = 0;
  siregs.n_allocated = 0;
  diregs.n_allocated = 0;
  qiregs.mode = QImode;
  hiregs.mode = HImode;
  siregs.mode = SImode;
  diregs.mode = DImode;

  for (insn = get_insns (); insn; insn = next)
    {
      next = NEXT_INSN (insn);
      if (!NONDEBUG_INSN_P (insn)
	  || asm_noperands (PATTERN (insn)) >= 0
	  || GET_CODE (PATTERN (insn)) == USE
	  || GET_CODE (PATTERN (insn)) == CLOBBER)
	continue;

      qiregs.n_in_use = 0;
      hiregs.n_in_use = 0;
      siregs.n_in_use = 0;
      diregs.n_in_use = 0;
      extract_insn (insn);
      enum attr_subregs_ok s_ok = get_attr_subregs_ok (insn);

      for (int i = 0; i < recog_data.n_operands; i++)
	{
	  rtx op = recog_data.operand[i];
	  if (GET_CODE (op) != SUBREG)
	    continue;

	  rtx inner = SUBREG_REG (op);

	  machine_mode outer_mode = GET_MODE (op);
	  machine_mode inner_mode = GET_MODE (inner);
	  gcc_assert (s_ok);
	  if (s_ok
	      && (GET_MODE_PRECISION (inner_mode)
		  >= GET_MODE_PRECISION (outer_mode)))
	    continue;
	  gcc_assert (SCALAR_INT_MODE_P (outer_mode));
	  struct reg_replace *r = (outer_mode == QImode ? &qiregs
				   : outer_mode == HImode ? &hiregs
				   : outer_mode == SImode ? &siregs
				   : &diregs);
	  rtx new_reg = get_replacement (r);

	  if (recog_data.operand_type[i] != OP_OUT)
	    {
	      enum rtx_code code;
	      if (GET_MODE_PRECISION (inner_mode)
		  < GET_MODE_PRECISION (outer_mode))
		code = ZERO_EXTEND;
	      else
		code = TRUNCATE;

	      rtx pat = gen_rtx_SET (new_reg,
				     gen_rtx_fmt_e (code, outer_mode, inner));
	      emit_insn_before (pat, insn);
	    }

	  if (recog_data.operand_type[i] != OP_IN)
	    {
	      enum rtx_code code;
	      if (GET_MODE_PRECISION (inner_mode)
		  < GET_MODE_PRECISION (outer_mode))
		code = TRUNCATE;
	      else
		code = ZERO_EXTEND;

	      rtx pat = gen_rtx_SET (inner,
				     gen_rtx_fmt_e (code, inner_mode, new_reg));
	      emit_insn_after (pat, insn);
	    }
	  validate_change (insn, recog_data.operand_loc[i], new_reg, false);
	}
    }
}

/* Loop structure of the function.The entire function is described as
   a NULL loop.  We should be able to extend this to represent
   superblocks.  */

struct parallel
{
  /* Parent parallel.  */
  parallel *parent;
  
  /* Next sibling parallel.  */
  parallel *next;

  /* First child parallel.  */
  parallel *inner;

  /* Partitioning mask of the parallel.  */
  unsigned mask;

  /* Partitioning used within inner parallels. */
  unsigned inner_mask;

  /* Location of parallel forked and join.  The forked is the first
     block in the parallel and the join is the first block after of
     the partition.  */
  basic_block forked_block;
  basic_block join_block;

  rtx_insn *forked_insn;
  rtx_insn *join_insn;

  rtx_insn *fork_insn;
  rtx_insn *joining_insn;

  /* Basic blocks in this parallel, but not in child parallels.  The
     FORKED and JOINING blocks are in the partition.  The FORK and JOIN
     blocks are not.  */
  auto_vec<basic_block> blocks;

public:
  parallel (parallel *parent, unsigned mode);
  ~parallel ();
};

/* Constructor links the new parallel into it's parent's chain of
   children.  */

parallel::parallel (parallel *parent_, unsigned mask_)
  :parent (parent_), next (0), inner (0), mask (mask_), inner_mask (0)
{
  forked_block = join_block = 0;
  forked_insn = join_insn = 0;
  fork_insn = joining_insn = 0;
  
  if (parent)
    {
      next = parent->inner;
      parent->inner = this;
    }
}

parallel::~parallel ()
{
  delete inner;
  delete next;
}

/* Map of basic blocks to insns */
typedef hash_map<basic_block, rtx_insn *> bb_insn_map_t;

/* A tuple of an insn of interest and the BB in which it resides.  */
typedef std::pair<rtx_insn *, basic_block> insn_bb_t;
typedef auto_vec<insn_bb_t> insn_bb_vec_t;

/* Split basic blocks such that each forked and join unspecs are at
   the start of their basic blocks.  Thus afterwards each block will
   have a single partitioning mode.  We also do the same for return
   insns, as they are executed by every thread.  Return the
   partitioning mode of the function as a whole.  Populate MAP with
   head and tail blocks.  We also clear the BB visited flag, which is
   used when finding partitions.  */

static void
nvptx_split_blocks (bb_insn_map_t *map)
{
  insn_bb_vec_t worklist;
  basic_block block;
  rtx_insn *insn;

  /* Locate all the reorg instructions of interest.  */
  FOR_ALL_BB_FN (block, cfun)
    {
      bool seen_insn = false;

      // Clear visited flag, for use by parallel locator  */
      block->flags &= ~BB_VISITED;
      
      FOR_BB_INSNS (block, insn)
	{
	  if (!INSN_P (insn))
	    continue;
	  switch (recog_memoized (insn))
	    {
	    default:
	      seen_insn = true;
	      continue;
	    case CODE_FOR_nvptx_forked:
	    case CODE_FOR_nvptx_join:
	      break;

	    case CODE_FOR_return:
	      /* We also need to split just before return insns, as
		 that insn needs executing by all threads, but the
		 block it is in probably does not.  */
	      break;
	    }

	  if (seen_insn)
	    /* We've found an instruction that  must be at the start of
	       a block, but isn't.  Add it to the worklist.  */
	    worklist.safe_push (insn_bb_t (insn, block));
	  else
	    /* It was already the first instruction.  Just add it to
	       the map.  */
	    map->get_or_insert (block) = insn;
	  seen_insn = true;
	}
    }

  /* Split blocks on the worklist.  */
  unsigned ix;
  insn_bb_t *elt;
  basic_block remap = 0;
  for (ix = 0; worklist.iterate (ix, &elt); ix++)
    {
      if (remap != elt->second)
	{
	  block = elt->second;
	  remap = block;
	}
      
      /* Split block before insn. The insn is in the new block  */
      edge e = split_block (block, PREV_INSN (elt->first));

      block = e->dest;
      map->get_or_insert (block) = elt->first;
    }
}

/* BLOCK is a basic block containing a head or tail instruction.
   Locate the associated prehead or pretail instruction, which must be
   in the single predecessor block.  */

static rtx_insn *
nvptx_discover_pre (basic_block block, int expected)
{
  gcc_assert (block->preds->length () == 1);
  basic_block pre_block = (*block->preds)[0]->src;
  rtx_insn *pre_insn;

  for (pre_insn = BB_END (pre_block); !INSN_P (pre_insn);
       pre_insn = PREV_INSN (pre_insn))
    gcc_assert (pre_insn != BB_HEAD (pre_block));

  gcc_assert (recog_memoized (pre_insn) == expected);
  return pre_insn;
}

/*  Dump this parallel and all its inner parallels.  */

static void
nvptx_dump_pars (parallel *par, unsigned depth)
{
  fprintf (dump_file, "%u: mask %d head=%d, tail=%d\n",
	   depth, par->mask,
	   par->forked_block ? par->forked_block->index : -1,
	   par->join_block ? par->join_block->index : -1);

  fprintf (dump_file, "    blocks:");

  basic_block block;
  for (unsigned ix = 0; par->blocks.iterate (ix, &block); ix++)
    fprintf (dump_file, " %d", block->index);
  fprintf (dump_file, "\n");
  if (par->inner)
    nvptx_dump_pars (par->inner, depth + 1);

  if (par->next)
    nvptx_dump_pars (par->next, depth);
}

typedef std::pair<basic_block, parallel *> bb_par_t;
typedef auto_vec<bb_par_t> bb_par_vec_t;

/* Walk the BBG looking for fork & join markers.  Construct a
   loop structure for the function.  MAP is a mapping of basic blocks
   to head & taiol markers, discoveded when splitting blocks.  This
   speeds up the discovery.  We rely on the BB visited flag having
   been cleared when splitting blocks.  */

static parallel *
nvptx_discover_pars (bb_insn_map_t *map)
{
  parallel *outer_par = new parallel (0, 0);
  bb_par_vec_t worklist;
  basic_block block;

  // Mark entry and exit blocks as visited.
  block = EXIT_BLOCK_PTR_FOR_FN (cfun);
  block->flags |= BB_VISITED;
  block = ENTRY_BLOCK_PTR_FOR_FN (cfun);
  worklist.safe_push (bb_par_t (block, outer_par));

  while (worklist.length ())
    {
      bb_par_t bb_par = worklist.pop ();
      parallel *l = bb_par.second;

      block = bb_par.first;

      // Have we met this block?
      if (block->flags & BB_VISITED)
	continue;
      block->flags |= BB_VISITED;
      
      rtx_insn **endp = map->get (block);
      if (endp)
	{
	  rtx_insn *end = *endp;
	  
	  /* This is a block head or tail, or return instruction.  */
	  switch (recog_memoized (end))
	    {
	    case CODE_FOR_return:
	      /* Return instructions are in their own block, and we
		 don't need to do anything more.  */
	      continue;

	    case CODE_FOR_nvptx_forked:
	      /* Loop head, create a new inner loop and add it into
		 our parent's child list.  */
	      {
		unsigned mask = UINTVAL (XVECEXP (PATTERN (end), 0, 0));

		gcc_assert (mask);
		l = new parallel (l, mask);
		l->forked_block = block;
		l->forked_insn = end;
		if (!(mask & GOMP_DIM_MASK (GOMP_DIM_MAX))
		    && (mask & GOMP_DIM_MASK (GOMP_DIM_WORKER)))
		  l->fork_insn
		    = nvptx_discover_pre (block, CODE_FOR_nvptx_fork);
	      }
	      break;

	    case CODE_FOR_nvptx_join:
	      /* A loop tail.  Finish the current loop and return to
		 parent.  */
	      {
		unsigned mask = UINTVAL (XVECEXP (PATTERN (end), 0, 0));

		gcc_assert (l->mask == mask);
		l->join_block = block;
		l->join_insn = end;
		if (!(mask & GOMP_DIM_MASK (GOMP_DIM_MAX))
		    && (mask & GOMP_DIM_MASK (GOMP_DIM_WORKER)))
		  l->joining_insn
		    = nvptx_discover_pre (block, CODE_FOR_nvptx_joining);
		l = l->parent;
	      }
	      break;

	    default:
	      gcc_unreachable ();
	    }
	}

      /* Add this block onto the current loop's list of blocks.  */
      l->blocks.safe_push (block);

      /* Push each destination block onto the work list.  */
      edge e;
      edge_iterator ei;
      FOR_EACH_EDGE (e, ei, block->succs)
	worklist.safe_push (bb_par_t (e->dest, l));
    }

  if (dump_file)
    {
      fprintf (dump_file, "\nLoops\n");
      nvptx_dump_pars (outer_par, 0);
      fprintf (dump_file, "\n");
    }
  
  return outer_par;
}

/* Propagate live state at the start of a partitioned region.  BLOCK
   provides the live register information, and might not contain
   INSN. Propagation is inserted just after INSN. RW indicates whether
   we are reading and/or writing state.  This
   separation is needed for worker-level proppagation where we
   essentially do a spill & fill.  FN is the underlying worker
   function to generate the propagation instructions for single
   register.  DATA is user data.

   We propagate the live register set and the entire frame.  We could
   do better by (a) propagating just the live set that is used within
   the partitioned regions and (b) only propagating stack entries that
   are used.  The latter might be quite hard to determine.  */

static void
nvptx_propagate (basic_block block, rtx_insn *insn, propagate_mask rw,
		 rtx (*fn) (rtx, propagate_mask,
			    unsigned, void *), void *data)
{
  bitmap live = DF_LIVE_IN (block);
  bitmap_iterator iterator;
  unsigned ix;

  /* Copy the frame array.  */
  HOST_WIDE_INT fs = get_frame_size ();
  if (fs)
    {
      rtx tmp = gen_reg_rtx (DImode);
      rtx idx = NULL_RTX;
      rtx ptr = gen_reg_rtx (Pmode);
      rtx pred = NULL_RTX;
      rtx_code_label *label = NULL;

      gcc_assert (!(fs & (GET_MODE_SIZE (DImode) - 1)));
      fs /= GET_MODE_SIZE (DImode);
      /* Detect single iteration loop. */
      if (fs == 1)
	fs = 0;

      start_sequence ();
      emit_insn (gen_rtx_SET (ptr, frame_pointer_rtx));
      if (fs)
	{
	  idx = gen_reg_rtx (SImode);
	  pred = gen_reg_rtx (BImode);
	  label = gen_label_rtx ();
	  
	  emit_insn (gen_rtx_SET (idx, GEN_INT (fs)));
	  /* Allow worker function to initialize anything needed */
	  rtx init = fn (tmp, PM_loop_begin, fs, data);
	  if (init)
	    emit_insn (init);
	  emit_label (label);
	  LABEL_NUSES (label)++;
	  emit_insn (gen_addsi3 (idx, idx, GEN_INT (-1)));
	}
      if (rw & PM_read)
	emit_insn (gen_rtx_SET (tmp, gen_rtx_MEM (DImode, ptr)));
      emit_insn (fn (tmp, rw, fs, data));
      if (rw & PM_write)
	emit_insn (gen_rtx_SET (gen_rtx_MEM (DImode, ptr), tmp));
      if (fs)
	{
	  emit_insn (gen_rtx_SET (pred, gen_rtx_NE (BImode, idx, const0_rtx)));
	  emit_insn (gen_adddi3 (ptr, ptr, GEN_INT (GET_MODE_SIZE (DImode))));
	  emit_insn (gen_br_true_uni (pred, label));
	  rtx fini = fn (tmp, PM_loop_end, fs, data);
	  if (fini)
	    emit_insn (fini);
	  emit_insn (gen_rtx_CLOBBER (GET_MODE (idx), idx));
	}
      emit_insn (gen_rtx_CLOBBER (GET_MODE (tmp), tmp));
      emit_insn (gen_rtx_CLOBBER (GET_MODE (ptr), ptr));
      rtx cpy = get_insns ();
      end_sequence ();
      insn = emit_insn_after (cpy, insn);
    }

  /* Copy live registers.  */
  EXECUTE_IF_SET_IN_BITMAP (live, 0, ix, iterator)
    {
      rtx reg = regno_reg_rtx[ix];

      if (REGNO (reg) >= FIRST_PSEUDO_REGISTER)
	{
	  rtx bcast = fn (reg, rw, 0, data);

	  insn = emit_insn_after (bcast, insn);
	}
    }
}

/* Worker for nvptx_vpropagate.  */

static rtx
vprop_gen (rtx reg, propagate_mask pm,
	   unsigned ARG_UNUSED (count), void *ARG_UNUSED (data))
{
  if (!(pm & PM_read_write))
    return 0;
  
  return nvptx_gen_vcast (reg);
}

/* Propagate state that is live at start of BLOCK across the vectors
   of a single warp.  Propagation is inserted just after INSN.   */

static void
nvptx_vpropagate (basic_block block, rtx_insn *insn)
{
  nvptx_propagate (block, insn, PM_read_write, vprop_gen, 0);
}

/* Worker for nvptx_wpropagate.  */

static rtx
wprop_gen (rtx reg, propagate_mask pm, unsigned rep, void *data_)
{
  wcast_data_t *data = (wcast_data_t *)data_;

  if (pm & PM_loop_begin)
    {
      /* Starting a loop, initialize pointer.    */
      unsigned align = GET_MODE_ALIGNMENT (GET_MODE (reg)) / BITS_PER_UNIT;

      if (align > worker_bcast_align)
	worker_bcast_align = align;
      data->offset = (data->offset + align - 1) & ~(align - 1);

      data->ptr = gen_reg_rtx (Pmode);

      return gen_adddi3 (data->ptr, data->base, GEN_INT (data->offset));
    }
  else if (pm & PM_loop_end)
    {
      rtx clobber = gen_rtx_CLOBBER (GET_MODE (data->ptr), data->ptr);
      data->ptr = NULL_RTX;
      return clobber;
    }
  else
    return nvptx_gen_wcast (reg, pm, rep, data);
}

/* Spill or fill live state that is live at start of BLOCK.  PRE_P
   indicates if this is just before partitioned mode (do spill), or
   just after it starts (do fill). Sequence is inserted just after
   INSN.  */

static void
nvptx_wpropagate (bool pre_p, basic_block block, rtx_insn *insn)
{
  wcast_data_t data;

  data.base = gen_reg_rtx (Pmode);
  data.offset = 0;
  data.ptr = NULL_RTX;

  nvptx_propagate (block, insn, pre_p ? PM_read : PM_write, wprop_gen, &data);
  if (data.offset)
    {
      /* Stuff was emitted, initialize the base pointer now.  */
      rtx init = gen_rtx_SET (data.base, worker_bcast_sym);
      emit_insn_after (init, insn);
      
      if (worker_bcast_hwm < data.offset)
	worker_bcast_hwm = data.offset;
    }
}

/* Emit a worker-level synchronization barrier.  We use different
   markers for before and after synchronizations.  */

static rtx
nvptx_wsync (bool after)
{
  return gen_nvptx_barsync (GEN_INT (after));
}

/* Single neutering according to MASK.  FROM is the incoming block and
   TO is the outgoing block.  These may be the same block. Insert at
   start of FROM:
   
     if (tid.<axis>) goto end.

   and insert before ending branch of TO (if there is such an insn):

     end:
     <possibly-broadcast-cond>
     <branch>

   We currently only use differnt FROM and TO when skipping an entire
   loop.  We could do more if we detected superblocks.  */

static void
nvptx_single (unsigned mask, basic_block from, basic_block to)
{
  rtx_insn *head = BB_HEAD (from);
  rtx_insn *tail = BB_END (to);
  unsigned skip_mask = mask;

  /* Find first insn of from block */
  while (head != BB_END (from) && !INSN_P (head))
    head = NEXT_INSN (head);

  /* Find last insn of to block */
  rtx_insn *limit = from == to ? head : BB_HEAD (to);
  while (tail != limit && !INSN_P (tail) && !LABEL_P (tail))
    tail = PREV_INSN (tail);

  /* Detect if tail is a branch.  */
  rtx tail_branch = NULL_RTX;
  rtx cond_branch = NULL_RTX;
  if (tail && INSN_P (tail))
    {
      tail_branch = PATTERN (tail);
      if (GET_CODE (tail_branch) != SET || SET_DEST (tail_branch) != pc_rtx)
	tail_branch = NULL_RTX;
      else
	{
	  cond_branch = SET_SRC (tail_branch);
	  if (GET_CODE (cond_branch) != IF_THEN_ELSE)
	    cond_branch = NULL_RTX;
	}
    }

  if (tail == head)
    {
      /* If this is empty, do nothing.  */
      if (!head || !INSN_P (head))
	return;

      /* If this is a dummy insn, do nothing.  */
      switch (recog_memoized (head))
	{
	default:break;
	case CODE_FOR_nvptx_fork:
	case CODE_FOR_nvptx_forked:
	case CODE_FOR_nvptx_joining:
	case CODE_FOR_nvptx_join:
	  return;
	}

      if (cond_branch)
	{
	  /* If we're only doing vector single, there's no need to
	     emit skip code because we'll not insert anything.  */
	  if (!(mask & GOMP_DIM_MASK (GOMP_DIM_VECTOR)))
	    skip_mask = 0;
	}
      else if (tail_branch)
	/* Block with only unconditional branch.  Nothing to do.  */
	return;
    }

  /* Insert the vector test inside the worker test.  */
  unsigned mode;
  rtx_insn *before = tail;
  for (mode = GOMP_DIM_WORKER; mode <= GOMP_DIM_VECTOR; mode++)
    if (GOMP_DIM_MASK (mode) & skip_mask)
      {
	rtx_code_label *label = gen_label_rtx ();
	rtx pred = cfun->machine->axis_predicate[mode - GOMP_DIM_WORKER];

	if (!pred)
	  {
	    pred = gen_reg_rtx (BImode);
	    cfun->machine->axis_predicate[mode - GOMP_DIM_WORKER] = pred;
	  }
	
	rtx br;
	if (mode == GOMP_DIM_VECTOR)
	  br = gen_br_true (pred, label);
	else
	  br = gen_br_true_uni (pred, label);
	emit_insn_before (br, head);

	LABEL_NUSES (label)++;
	if (tail_branch)
	  before = emit_label_before (label, before);
	else
	  emit_label_after (label, tail);
      }

  /* Now deal with propagating the branch condition.  */
  if (cond_branch)
    {
      rtx pvar = XEXP (XEXP (cond_branch, 0), 0);

      if (GOMP_DIM_MASK (GOMP_DIM_VECTOR) == mask)
	{
	  /* Vector mode only, do a shuffle.  */
	  emit_insn_before (nvptx_gen_vcast (pvar), tail);
	}
      else
	{
	  /* Includes worker mode, do spill & fill.  By construction
	     we should never have worker mode only. */
	  wcast_data_t data;

	  data.base = worker_bcast_sym;
	  data.ptr = 0;

	  if (worker_bcast_hwm < GET_MODE_SIZE (SImode))
	    worker_bcast_hwm = GET_MODE_SIZE (SImode);

	  data.offset = 0;
	  emit_insn_before (nvptx_gen_wcast (pvar, PM_read, 0, &data),
			    before);
	  /* Barrier so other workers can see the write.  */
	  emit_insn_before (nvptx_wsync (false), tail);
	  data.offset = 0;
	  emit_insn_before (nvptx_gen_wcast (pvar, PM_write, 0, &data), tail);
	  /* This barrier is needed to avoid worker zero clobbering
	     the broadcast buffer before all the other workers have
	     had a chance to read this instance of it.  */
	  emit_insn_before (nvptx_wsync (true), tail);
	}

      extract_insn (tail);
      rtx unsp = gen_rtx_UNSPEC (BImode, gen_rtvec (1, pvar),
				 UNSPEC_BR_UNIFIED);
      validate_change (tail, recog_data.operand_loc[0], unsp, false);
    }
}

/* PAR is a parallel that is being skipped in its entirety according to
   MASK.  Treat this as skipping a superblock starting at forked
   and ending at joining.  */

static void
nvptx_skip_par (unsigned mask, parallel *par)
{
  basic_block tail = par->join_block;
  gcc_assert (tail->preds->length () == 1);

  basic_block pre_tail = (*tail->preds)[0]->src;
  gcc_assert (pre_tail->succs->length () == 1);

  nvptx_single (mask, par->forked_block, pre_tail);
}

/* If PAR has a single inner parallel and PAR itself only contains
   empty entry and exit blocks, swallow the inner PAR.  */

static void
nvptx_optimize_inner (parallel *par)
{
  parallel *inner = par->inner;

  /* We mustn't be the outer dummy par.  */
  if (!par->mask)
    return;

  /* We must have a single inner par.  */
  if (!inner || inner->next)
    return;

  /* We must only contain 2 blocks ourselves -- the head and tail of
     the inner par.  */
  if (par->blocks.length () != 2)
    return;

  /* We must be disjoint partitioning.  As we only have vector and
     worker partitioning, this is sufficient to guarantee the pars
     have adjacent partitioning.  */
  if ((par->mask & inner->mask) & (GOMP_DIM_MASK (GOMP_DIM_MAX) - 1))
    /* This indicates malformed code generation.  */
    return;

  /* The outer forked insn should be the only one in its block.  */
  rtx_insn *probe;
  rtx_insn *forked = par->forked_insn;
  for (probe = BB_END (par->forked_block);
       probe != forked; probe = PREV_INSN (probe))
    if (INSN_P (probe))
      return;

  /* The outer joining insn, if any, must be in the same block as the inner
     joined instruction, which must otherwise be empty of insns.  */
  rtx_insn *joining = par->joining_insn;
  rtx_insn *join = inner->join_insn;
  for (probe = BB_END (inner->join_block);
       probe != join; probe = PREV_INSN (probe))
    if (probe != joining && INSN_P (probe))
      return;

  /* Preconditions met.  Swallow the inner par.  */
  par->mask |= inner->mask & (GOMP_DIM_MASK (GOMP_DIM_MAX) - 1);

  par->blocks.reserve (inner->blocks.length ());
  while (inner->blocks.length ())
    par->blocks.quick_push (inner->blocks.pop ());

  par->inner = inner->inner;
  inner->inner = NULL;

  delete inner;
}

/* Process the parallel PAR and all its contained
   parallels.  We do everything but the neutering.  Return mask of
   partitioned modes used within this parallel.  */

static unsigned
nvptx_process_pars (parallel *par)
{
  if (nvptx_optimize)
    nvptx_optimize_inner (par);
  
  unsigned inner_mask = par->mask;

  /* Do the inner parallels first.  */
  if (par->inner)
    {
      par->inner_mask = nvptx_process_pars (par->inner);
      inner_mask |= par->inner_mask;
    }

  if (par->mask & GOMP_DIM_MASK (GOMP_DIM_MAX))
    { /* No propagation needed for a call.  */ }
  else if (par->mask & GOMP_DIM_MASK (GOMP_DIM_WORKER))
    {
      nvptx_wpropagate (false, par->forked_block, par->forked_insn);
      nvptx_wpropagate (true, par->forked_block, par->fork_insn);
      /* Insert begin and end synchronizations.  */
      emit_insn_after (nvptx_wsync (false), par->forked_insn);
      emit_insn_before (nvptx_wsync (true), par->joining_insn);
    }
  else if (par->mask & GOMP_DIM_MASK (GOMP_DIM_VECTOR))
    nvptx_vpropagate (par->forked_block, par->forked_insn);

  /* Now do siblings.  */
  if (par->next)
    inner_mask |= nvptx_process_pars (par->next);
  return inner_mask;
}

/* Neuter the parallel described by PAR.  We recurse in depth-first
   order.  MODES are the partitioning of the execution and OUTER is
   the partitioning of the parallels we are contained in.  */

static void
nvptx_neuter_pars (parallel *par, unsigned modes, unsigned outer)
{
  unsigned me = par->mask
    & (GOMP_DIM_MASK (GOMP_DIM_WORKER) | GOMP_DIM_MASK (GOMP_DIM_VECTOR));
  unsigned  skip_mask = 0, neuter_mask = 0;
  
  if (par->inner)
    nvptx_neuter_pars (par->inner, modes, outer | me);

  for (unsigned mode = GOMP_DIM_WORKER; mode <= GOMP_DIM_VECTOR; mode++)
    {
      if ((outer | me) & GOMP_DIM_MASK (mode))
	{ /* Mode is partitioned: no neutering.  */ }
      else if (!(modes & GOMP_DIM_MASK (mode)))
	{ /* Mode  is not used: nothing to do.  */ }
      else if (par->inner_mask & GOMP_DIM_MASK (mode)
	       || !par->forked_insn)
	/* Partitioned in inner parallels, or we're not a partitioned
	   at all: neuter individual blocks.  */
	neuter_mask |= GOMP_DIM_MASK (mode);
      else if (!par->parent || !par->parent->forked_insn
	       || par->parent->inner_mask & GOMP_DIM_MASK (mode))
	/* Parent isn't a parallel or contains this paralleling: skip
	   parallel at this level.  */
	skip_mask |= GOMP_DIM_MASK (mode);
      else
	{ /* Parent will skip this parallel itself.  */ }
    }

  if (neuter_mask)
    {
      basic_block block;

      for (unsigned ix = 0; par->blocks.iterate (ix, &block); ix++)
	nvptx_single (neuter_mask, block, block);
    }

  if (skip_mask)
      nvptx_skip_par (skip_mask, par);
  
  if (par->next)
    nvptx_neuter_pars (par->next, modes, outer);
}

static void
nvptx_reorg_reductions (void)
{
  unsigned ix;

  for (ix = loop_reds.length (); ix--;)
    {
      if (loop_reds[ix].hwm > worker_red_hwm)
	worker_red_hwm = loop_reds[ix].hwm;
      loop_reds.pop ();
    }
}

/* PTX-specific reorganization
   - Scan and release reduction buffers
   - Split blocks at fork and join instructions
   - Compute live registers
   - Mark now-unused registers, so function begin doesn't declare
   unused registers.
   - Insert state propagation when entering partitioned mode
   - Insert neutering instructions when in single mode
   - Replace subregs with suitable sequences.
*/

static void
nvptx_reorg (void)
{
  nvptx_reorg_reductions ();
  
  /* We are freeing block_for_insn in the toplev to keep compatibility
     with old MDEP_REORGS that are not CFG based.  Recompute it now.  */
  compute_bb_for_insn ();

  thread_prologue_and_epilogue_insns ();

  /* Split blocks and record interesting unspecs.  */
  bb_insn_map_t bb_insn_map;

  nvptx_split_blocks (&bb_insn_map);

  /* Compute live regs */
  df_clear_flags (DF_LR_RUN_DCE);
  df_set_flags (DF_NO_INSN_RESCAN | DF_NO_HARD_REGS);
  df_live_add_problem ();
  df_live_set_all_dirty ();
  df_analyze ();
  regstat_init_n_sets_and_refs ();

  if (dump_file)
    df_dump (dump_file);
  
  /* Mark unused regs as unused.  */
  int max_regs = max_reg_num ();
  for (int i = LAST_VIRTUAL_REGISTER + 1; i < max_regs; i++)
    if (REG_N_SETS (i) == 0 && REG_N_REFS (i) == 0)
      regno_reg_rtx[i] = const0_rtx;

  /* Determine launch dimensions of the function.  If it is not an
     offloaded function  (i.e. this is a regular compiler), the
     function has no neutering.  */
  tree attr = get_oacc_fn_attrib (current_function_decl);
  if (attr)
    {
      /* If we determined this mask before RTL expansion, we could
	 elide emission of some levels of forks and joins.  */
      unsigned mask = 0;
      tree dims = TREE_VALUE (attr);
      unsigned ix;

      for (ix = 0; ix != GOMP_DIM_MAX; ix++, dims = TREE_CHAIN (dims))
	{
	  int size = TREE_INT_CST_LOW (TREE_VALUE (dims));
	  tree allowed = TREE_PURPOSE (dims);

	  if (size != 1 && !(allowed && integer_zerop (allowed)))
	    mask |= GOMP_DIM_MASK (ix);
	}
      /* If there is worker neutering, there must be vector
	 neutering.  Otherwise the hardware will fail.  */
      gcc_assert (!(mask & GOMP_DIM_MASK (GOMP_DIM_WORKER))
		  || (mask & GOMP_DIM_MASK (GOMP_DIM_VECTOR)));

      /* Discover & process partitioned regions.  */
      parallel *pars = nvptx_discover_pars (&bb_insn_map);
      nvptx_process_pars (pars);
      nvptx_neuter_pars (pars, mask, 0);
      delete pars;
    }

  nvptx_reorg_subreg ();
  
  regstat_free_n_sets_and_refs ();

  df_finish_pass (true);
}

/* Handle a "kernel" attribute; arguments as in
   struct attribute_spec.handler.  */

static tree
nvptx_handle_kernel_attribute (tree *node, tree name, tree ARG_UNUSED (args),
			       int ARG_UNUSED (flags), bool *no_add_attrs)
{
  tree decl = *node;

  if (TREE_CODE (decl) != FUNCTION_DECL)
    {
      error ("%qE attribute only applies to functions", name);
      *no_add_attrs = true;
    }

  else if (TREE_TYPE (TREE_TYPE (decl)) != void_type_node)
    {
      error ("%qE attribute requires a void return type", name);
      *no_add_attrs = true;
    }

  return NULL_TREE;
}

/* Table of valid machine attributes.  */
static const struct attribute_spec nvptx_attribute_table[] =
{
  /* { name, min_len, max_len, decl_req, type_req, fn_type_req, handler,
       affects_type_identity } */
  { "kernel", 0, 0, true, false,  false, nvptx_handle_kernel_attribute, false },
  { NULL, 0, 0, false, false, false, NULL, false }
};

/* Limit vector alignments to BIGGEST_ALIGNMENT.  */

static HOST_WIDE_INT
nvptx_vector_alignment (const_tree type)
{
  HOST_WIDE_INT align = tree_to_shwi (TYPE_SIZE (type));

  return MIN (align, BIGGEST_ALIGNMENT);
}

/* Indicate that INSN cannot be duplicated.   */

static bool
nvptx_cannot_copy_insn_p (rtx_insn *insn)
{
  switch (recog_memoized (insn))
    {
    case CODE_FOR_nvptx_shufflesi:
    case CODE_FOR_nvptx_shufflesf:
    case CODE_FOR_nvptx_barsync:
    case CODE_FOR_nvptx_fork:
    case CODE_FOR_nvptx_forked:
    case CODE_FOR_nvptx_joining:
    case CODE_FOR_nvptx_join:
      return true;
    default:
      return false;
    }
}

/* Record a symbol for mkoffload to enter into the mapping table.  */

static void
nvptx_record_offload_symbol (tree decl)
{
  switch (TREE_CODE (decl))
    {
    case VAR_DECL:
      fprintf (asm_out_file, "//:VAR_MAP \"%s\"\n",
	       IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl)));
      break;

    case FUNCTION_DECL:
      {
	tree attr = get_oacc_fn_attrib (decl);
	tree dims = TREE_VALUE (attr);
	unsigned ix;
	
	fprintf (asm_out_file, "//:FUNC_MAP \"%s\"",
		 IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl)));

	for (ix = 0; ix != GOMP_DIM_MAX; ix++, dims = TREE_CHAIN (dims))
	  {
	    int size = TREE_INT_CST_LOW (TREE_VALUE (dims));

	    gcc_assert (!TREE_PURPOSE (dims));
	    fprintf (asm_out_file, ", %#x", size);
	  }

	fprintf (asm_out_file, "\n");
      }
      break;
  
    default:
      gcc_unreachable ();
    }
}

/* Implement TARGET_ASM_FILE_START.  Write the kinds of things ptxas expects
   at the start of a file.  */

static void
nvptx_file_start (void)
{
  fputs ("// BEGIN PREAMBLE\n", asm_out_file);
  fputs ("\t.version\t3.1\n", asm_out_file);
  if (TARGET_SM35)
    fputs ("\t.target\tsm_35\n", asm_out_file);
  else
    fputs ("\t.target\tsm_30\n", asm_out_file);
  fprintf (asm_out_file, "\t.address_size %d\n", GET_MODE_BITSIZE (Pmode));
  fprintf (asm_out_file, "\t.extern .shared .u8 sdata[];\n");
  fputs ("// END PREAMBLE\n", asm_out_file);
}

/* Write out the function declarations we've collected and declare storage
   for the broadcast buffer.  */

static void
nvptx_file_end (void)
{
  hash_table<tree_hasher>::iterator iter;
  tree decl;
  FOR_EACH_HASH_TABLE_ELEMENT (*needed_fndecls_htab, decl, tree, iter)
    nvptx_record_fndecl (decl, true);
  fputs (func_decls.str().c_str(), asm_out_file);

  if (worker_bcast_hwm)
    {
      /* Define the broadcast buffer.  */

      worker_bcast_hwm = (worker_bcast_hwm + worker_bcast_align - 1)
	& ~(worker_bcast_align - 1);
      
      fprintf (asm_out_file, "// BEGIN VAR DEF: %s\n", worker_bcast_name);
      fprintf (asm_out_file, ".shared .align %d .u8 %s[%d];\n",
	       worker_bcast_align,
	       worker_bcast_name, worker_bcast_hwm);
    }

  if (worker_red_hwm)
    {
      /* Define the reduction buffer.  */

      worker_red_hwm = (worker_red_hwm + worker_red_align - 1)
	& ~(worker_red_align - 1);
      
      fprintf (asm_out_file, "// BEGIN VAR DEF: %s\n", worker_red_name);
      fprintf (asm_out_file, ".shared .align %d .u8 %s[%d];\n",
	       worker_red_align,
	       worker_red_name, worker_red_hwm);
    }

  /* Emit lock variables.  */
  for (unsigned ix = LOCK_MAX; ix--;)
    if (lock_used[ix])
      {
	fprintf (asm_out_file, "// BEGIN VAR DEF: %s\n", lock_names[ix]);
	fprintf (asm_out_file, "%s .u32 %s;\n",
		 nvptx_section_from_addr_space (lock_space[ix]),
		 lock_names[ix]);
      }
}

/* Descriptor for a builtin.  */

struct builtin_description
{
  const char *name;
  unsigned short type;
  rtx (*expander) (tree, rtx, machine_mode, int);
};

/* Expander for the shuffle down builtins.  */
static rtx
nvptx_expand_shuffle_down (tree exp, rtx target, machine_mode mode, int ignore)
{
  if (ignore)
    return target;
  
  if (! target)
    target = gen_reg_rtx (mode);

  rtx src = expand_expr (CALL_EXPR_ARG (exp, 0),
			 NULL_RTX, mode, EXPAND_NORMAL);
  if (!REG_P (src))
    src = copy_to_mode_reg (mode, src);

  rtx idx = expand_expr (CALL_EXPR_ARG (exp, 1),
			NULL_RTX, SImode, EXPAND_NORMAL);
  if (!REG_P (idx) && GET_CODE (idx) != CONST_INT)
    idx = copy_to_mode_reg (SImode, idx);

  rtx pat = nvptx_gen_shuffle (target, src, idx, SHUFFLE_DOWN);
  if (pat)
    emit_insn (pat);

  return target;
}

/* Worker reduction address expander.  */
static rtx
nvptx_expand_work_red_addr (tree exp, rtx target,
			    machine_mode ARG_UNUSED (mode),
			    int ignore)
{
  if (ignore)
    return target;
  
  rtx loop_id = expand_expr (CALL_EXPR_ARG (exp, 0),
			     NULL_RTX, mode, EXPAND_NORMAL);
  rtx red_id = expand_expr (CALL_EXPR_ARG (exp, 1),
			     NULL_RTX, mode, EXPAND_NORMAL);
  gcc_assert (GET_CODE (loop_id) == CONST_INT
	      && GET_CODE (red_id) == CONST_INT);
  gcc_assert (REG_P (target));

  unsigned lid = (unsigned)UINTVAL (loop_id);
  unsigned rid = (unsigned)UINTVAL (red_id);

  unsigned ix;

  for (ix = 0; ix != loop_reds.length (); ix++)
    if (loop_reds[ix].id == lid)
      goto found_lid;
  /* Allocate a new loop.  */
  loop_reds.safe_push (loop_red (lid));
 found_lid:
  loop_red &loop = loop_reds[ix];
  for (ix = 0; ix != loop.vars.length (); ix++)
    if (loop.vars[ix].first == rid)
      goto found_rid;

  /* Allocate a new var. */
  {
    tree type = TREE_TYPE (TREE_TYPE (exp));
    enum machine_mode mode = TYPE_MODE (type);
    unsigned align = GET_MODE_ALIGNMENT (mode) / BITS_PER_UNIT;
    unsigned off = loop.hwm;

    if (align > worker_red_align)
      worker_red_align = align;
    off = (off + align - 1) & ~(align -1);
    loop.hwm = off + GET_MODE_SIZE (mode);
    loop.vars.safe_push (var_red_t (rid, off));
  }
 found_rid:

  /* Return offset into worker reduction array.  */
  unsigned offset = loop.vars[ix].second;
  
  emit_insn (gen_rtx_SET (target, worker_red_sym));

  if (offset)
    emit_insn (gen_rtx_SET (target,
			    gen_rtx_PLUS (Pmode, target, GEN_INT (offset))));
	       
  emit_insn (gen_rtx_SET (target,
			  gen_rtx_UNSPEC (Pmode, gen_rtvec (1, target),
					  UNSPEC_FROM_SHARED)));

  return target;
}

enum nvptx_types
  {
    NT_UINT_UINT_INT,
    NT_ULL_ULL_INT,
    NT_FLT_FLT_INT,
    NT_DBL_DBL_INT,
    NT_UINTPTR_UINT_UINT,
    NT_ULLPTR_UINT_UINT,
    NT_FLTPTR_UINT_UINT,
    NT_DBLPTR_UINT_UINT,
    NT_MAX
  };

/* Codes for all the NVPTX builtins.  */
enum nvptx_builtins
{
  NVPTX_BUILTIN_SHUFFLE_DOWN,
  NVPTX_BUILTIN_SHUFFLE_DOWNLL,
  NVPTX_BUILTIN_SHUFFLE_DOWNF,
  NVPTX_BUILTIN_SHUFFLE_DOWND,
  NVPTX_BUILTIN_WORK_RED_ADDR,
  NVPTX_BUILTIN_WORK_RED_ADDRLL,
  NVPTX_BUILTIN_WORK_RED_ADDRF,
  NVPTX_BUILTIN_WORK_RED_ADDRD,
  NVPTX_BUILTIN_MAX
};

static const struct builtin_description builtins[] =
{
  {"__builtin_nvptx_shuffle_down", NT_UINT_UINT_INT,
   nvptx_expand_shuffle_down},
  {"__builtin_nvptx_shuffle_downll", NT_ULL_ULL_INT,
   nvptx_expand_shuffle_down},
  {"__builtin_nvptx_shuffle_downf", NT_FLT_FLT_INT,
   nvptx_expand_shuffle_down},
  {"__builtin_nvptx_shuffle_downd", NT_DBL_DBL_INT,
   nvptx_expand_shuffle_down},
  {"__builtin_nvptx_work_red_addr", NT_UINTPTR_UINT_UINT,
   nvptx_expand_work_red_addr},
  {"__builtin_nvptx_work_red_addrll", NT_ULLPTR_UINT_UINT,
   nvptx_expand_work_red_addr},
  {"__builtin_nvptx_work_red_addrf", NT_FLTPTR_UINT_UINT,
   nvptx_expand_work_red_addr},
  {"__builtin_nvptx_work_red_addrd", NT_DBLPTR_UINT_UINT,
   nvptx_expand_work_red_addr},
};

static GTY(()) tree nvptx_builtin_decls[NVPTX_BUILTIN_MAX];

/* Return the NVPTX builtin for CODE.  */
static tree
nvptx_builtin_decl (unsigned code, bool initialize_p ATTRIBUTE_UNUSED)
{
  if (code >= NVPTX_BUILTIN_MAX)
    return error_mark_node;

  return nvptx_builtin_decls[code];
}

/* Set up all builtin functions for this target.  */
static void
nvptx_init_builtins (void)
{
  tree types[NT_MAX];
  unsigned ix;

  types[NT_UINT_UINT_INT]
    = build_function_type_list (unsigned_type_node, unsigned_type_node,
				integer_type_node, NULL_TREE);
  types[NT_ULL_ULL_INT]
    = build_function_type_list (long_long_unsigned_type_node,
				long_long_unsigned_type_node,
				integer_type_node, NULL_TREE);
  types[NT_FLT_FLT_INT]
    = build_function_type_list (float_type_node, float_type_node,
				integer_type_node, NULL_TREE);
  types[NT_DBL_DBL_INT]
    = build_function_type_list (double_type_node, double_type_node,
				integer_type_node, NULL_TREE);
  types[NT_UINTPTR_UINT_UINT]
    = build_function_type_list (build_pointer_type (unsigned_type_node),
				unsigned_type_node, unsigned_type_node,
				NULL_TREE);

  types[NT_ULLPTR_UINT_UINT]
    = build_function_type_list (build_pointer_type
				(long_long_unsigned_type_node),
				unsigned_type_node, unsigned_type_node,
				NULL_TREE);

  types[NT_FLTPTR_UINT_UINT]
    = build_function_type_list (build_pointer_type (float_type_node),
				unsigned_type_node, unsigned_type_node,
				NULL_TREE);

  types[NT_DBLPTR_UINT_UINT]
    = build_function_type_list (build_pointer_type (double_type_node),
				unsigned_type_node, unsigned_type_node,
				NULL_TREE);

  for (ix = 0; ix != NVPTX_BUILTIN_MAX; ix++)
    nvptx_builtin_decls[ix]
      = add_builtin_function (builtins[ix].name, types[builtins[ix].type],
			      ix, BUILT_IN_MD, NULL, NULL);
}

/* Expand an expression EXP that calls a built-in function,
   with result going to TARGET if that's convenient
   (and in mode MODE if that's convenient).
   SUBTARGET may be used as the target for computing one of EXP's operands.
   IGNORE is nonzero if the value is to be ignored.  */

static rtx
nvptx_expand_builtin (tree exp, rtx target,
		     rtx subtarget ATTRIBUTE_UNUSED,
		     machine_mode mode,
		     int ignore)
{
  tree fndecl = TREE_OPERAND (CALL_EXPR_FN (exp), 0);
  const struct builtin_description *d = &builtins[DECL_FUNCTION_CODE (fndecl)];

  return d->expander (exp, target, mode, ignore);
}

/* Define vector size for known hardware.  */
#define PTX_VECTOR_LENGTH 32
#define PTX_WORKER_LENGTH 32

/* Validate compute dimensions, fill in non-unity defaults.  FN_LEVEL
   indicates the level at which a routine might spawn a loop.  It is
   negative for non-routines.  */

static bool
nvptx_validate_dims (tree decl, int dims[], int fn_level)
{
  bool changed = false;

  /* The vector size must be 32, unless this is a SEQ routine.  */
  if (fn_level <= GOMP_DIM_VECTOR
      && dims[GOMP_DIM_VECTOR] != PTX_VECTOR_LENGTH)
    {
      if (dims[GOMP_DIM_VECTOR] >= 0 && fn_level < 0)
	warning_at (DECL_SOURCE_LOCATION (decl), 0,
		    dims[GOMP_DIM_VECTOR]
		    ? "using vector_length (%d), ignoring %d"
		    : "using vector_length (%d), ignoring runtime setting",
		    PTX_VECTOR_LENGTH, dims[GOMP_DIM_VECTOR]);
      dims[GOMP_DIM_VECTOR] = PTX_VECTOR_LENGTH;
      changed = true;
    }

  /* Check the num workers is not too large.  */
  if (dims[GOMP_DIM_WORKER] > PTX_WORKER_LENGTH)
    {
      warning_at (DECL_SOURCE_LOCATION (decl), 0,
		  "using num_workers (%d), ignoring %d",
		  PTX_WORKER_LENGTH, dims[GOMP_DIM_WORKER]);
      dims[GOMP_DIM_WORKER] = PTX_WORKER_LENGTH;
      changed = true;
    }

  return changed;
}

/* Return maximum dimension size, or zero for unbounded.  */

static unsigned
nvptx_dim_limit (unsigned axis)
{
  switch (axis)
    {
    case GOMP_DIM_WORKER:
      return PTX_WORKER_LENGTH;
      break;
    case GOMP_DIM_VECTOR:
      return  PTX_VECTOR_LENGTH;
      break;
    default: break;
    }
  return 0;
}

/* Determine whether fork & joins are needed.  */

static bool
nvptx_xform_fork_join (gimple stmt, const int dims[],
		       bool ARG_UNUSED (is_fork))
{
  tree arg = gimple_call_arg (stmt, 0);
  unsigned axis = TREE_INT_CST_LOW (arg);

  /* We only care about worker and vector partitioning.  */
  if (axis < GOMP_DIM_WORKER)
    return true;

  /* If the size is 1, there's no partitioning.  */
  if (dims[axis] == 1)
    return true;

  return false;
}

/* Check lock & unlock.  We only need the gang- & worker-level ones.
 */

static bool
nvptx_xform_lock (gimple stmt, const int *ARG_UNUSED (dims), unsigned ifn_code)
{
  tree arg = gimple_call_arg (stmt, 0);
  unsigned mode = TREE_INT_CST_LOW (arg);
  
  switch (ifn_code)
    {
    case IFN_GOACC_LOCK:
    case IFN_GOACC_UNLOCK:
      return mode > GOMP_DIM_WORKER;

    case IFN_GOACC_LOCK_INIT:
      return force_global_locks || mode != GOMP_DIM_WORKER;

    default: gcc_unreachable();
    }
}

static tree
nvptx_get_worker_red_addr_fn (tree var, tree rid, tree lid)
{
  tree vartype = TREE_TYPE (var);
  tree fndecl, call;
  enum nvptx_builtins fn;
  machine_mode mode = TYPE_MODE (vartype);

  switch (mode)
    {
    case QImode:
    case HImode:
    case SImode:
      fn = NVPTX_BUILTIN_WORK_RED_ADDR;
      break;
    case DImode:
      fn = NVPTX_BUILTIN_WORK_RED_ADDRLL;
      break;
    case DFmode:
      fn = NVPTX_BUILTIN_WORK_RED_ADDRD;
      break;
    case SFmode:
      fn = NVPTX_BUILTIN_WORK_RED_ADDRF;
      break;
    default:
      gcc_unreachable ();
    }

  fndecl = nvptx_builtin_decl (fn, true);
  call = build_call_expr (fndecl, 2, lid, rid);

  return call;
}

/* Emit a SHFL.DOWN using index SHFL of VAR into DEST_VAR.  This function
   will cast the variable if necessary.  */

static void
nvptx_generate_vector_shuffle (tree dest_var, tree var, int shfl,
			       gimple_seq *seq)
{
  tree vartype = TREE_TYPE (var);
  enum nvptx_builtins fn = NVPTX_BUILTIN_SHUFFLE_DOWN;
  machine_mode mode = TYPE_MODE (vartype);
  tree casted_dest = dest_var;
  tree casted_var = var;
  tree call_arg_type;

  switch (mode)
    {
    case QImode:
    case HImode:
    case SImode:
      fn = NVPTX_BUILTIN_SHUFFLE_DOWN;
      call_arg_type = unsigned_type_node;
      break;
    case DImode:
      fn = NVPTX_BUILTIN_SHUFFLE_DOWNLL;
      call_arg_type = long_long_unsigned_type_node;
      break;
    case DFmode:
      fn = NVPTX_BUILTIN_SHUFFLE_DOWND;
      call_arg_type = double_type_node;
      break;
    case SFmode:
      fn = NVPTX_BUILTIN_SHUFFLE_DOWNF;
      call_arg_type = float_type_node;
      break;
    default:
      gcc_unreachable ();
    }

  /* All of the integral types need to be unsigned.  Furthermore, small
     integral types may need to be extended to 32-bits.  */
  bool need_conversion = !types_compatible_p (vartype, call_arg_type);

  if (need_conversion)
    {
      casted_var = make_ssa_name (call_arg_type);
      tree t1 = fold_build1 (NOP_EXPR, call_arg_type, var);
      gassign *conv1 = gimple_build_assign (casted_var, t1);
      gimple_seq_add_stmt (seq, conv1);
    }

  tree fndecl = nvptx_builtin_decl (fn, true);
  tree shift =  build_int_cst (unsigned_type_node, shfl);
  gimple call = gimple_build_call (fndecl, 2, casted_var, shift);

  gimple_seq_add_stmt (seq, call);

  if (need_conversion)
    {
      casted_dest = make_ssa_name (call_arg_type);
      tree t2 = fold_build1 (NOP_EXPR, vartype, casted_dest);
      gassign *conv2 = gimple_build_assign (dest_var, t2);
      gimple_seq_add_stmt (seq, conv2);
    }

  update_stmt (call);
  gimple_call_set_lhs (call, casted_dest);
}

/* Fold an OpenACC vector reduction using shuffle down instructions.  */

static void
nvptx_shuffle_reduction (tree lhs, tree var, enum tree_code code,
			 gimple_seq *seq)
{
  /* Generate a sequence of instructions to preform a tree reduction using
     shfl.down as an intermediate step.  */

  tree type = TREE_TYPE (var);
  tree t, t2;
  gassign *g;

  if (code == TRUTH_ANDIF_EXPR)
    code = BIT_AND_EXPR;
  else if (code == TRUTH_ORIF_EXPR)
    code = BIT_IOR_EXPR;

  for (int shfl = PTX_VECTOR_LENGTH / 2; shfl > 0; shfl = shfl >> 1)
    {
      t = make_ssa_name (type);
      nvptx_generate_vector_shuffle (t, var, shfl, seq);
      t2 = make_ssa_name (create_tmp_var (type));
      g = gimple_build_assign (t2, fold_build2 (code, type, var, t));
      gimple_seq_add_stmt (seq, g);
      var = t2;
    }

  /* Restore the type of the comparison operand.  */
  if (code == EQ_EXPR || code == NE_EXPR)
    {
      type = TREE_TYPE (lhs);
      t = make_ssa_name (type);
      t2 = fold_build1 (NOP_EXPR, type, var);
      g = gimple_build_assign (t, t2);
      gimple_seq_add_stmt (seq, g);
      var = t;
    }

  g = gimple_build_assign (lhs, var);
  gimple_seq_add_stmt (seq, g);
}

/* NVPTX implementation of GOACC_REDUCTION_SETUP.  Reserve shared
   memory for worker reductions.

   Given:

     V = IFN_RED_SETUP (RES_PTR, LOCAL, LEVEL, OP, LID, RID)

   Expand to:

   Vector:

     V = LOCAL;

   Worker:

     *ptx_work_red_addr<T> (LID, RID) = LOCAL;
     ptx_mem_bar (WORKER)  // Should be inserted automatically by the
                           // predication framework.

   Gang:

     if (RES_PTR != NULL)
       V = LOCAL
*/

static bool
nvptx_goacc_reduction_setup (gimple call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  tree v = gimple_call_lhs (call);
  tree local_var = gimple_call_arg (call, 1);
  int loop_dim = tree_to_shwi (gimple_call_arg (call, 2));
  tree lid = gimple_call_arg (call, 4);
  tree rid = gimple_call_arg (call, 5);
  gimple_seq seq = NULL;

  push_gimplify_context (true);

  switch (loop_dim)
    {
    case GOMP_DIM_GANG:
    case GOMP_DIM_VECTOR:
      gimplify_assign (v, local_var, &seq);
      break;
    case GOMP_DIM_WORKER:
      {
	tree ptr = make_ssa_name (build_pointer_type (TREE_TYPE (local_var)));
	tree call = nvptx_get_worker_red_addr_fn (local_var, rid, lid);
	tree ref;

	gimplify_assign (ptr, call, &seq);
	ref = build_simple_mem_ref (ptr);
	TREE_THIS_VOLATILE (ref) = 1;
	gimplify_assign (ref, local_var, &seq);
	if (v)
	  gimplify_assign (v, local_var, &seq);
      }
      break;
    default:
      gcc_unreachable ();
    }

  pop_gimplify_context (NULL);

  gsi_replace_with_seq (&gsi, seq, true);

  return false;
}

/* NVPTX implementation of GOACC_REDUCTION_INIT. Initialize the private
   reduction variables.  Vectors are special in that tid.x = 0 contains
   the original value of LOCAL prior to the reduction.

   Given:

     V = IFN_RED_INIT (RES_PTR, LOCAL, LEVEL, OP, LID, RID)

   Expand to:

   Vector:

     V = IFN_OACC_DIM_POS (VECTOR) ? {init_val<T> (OP)} : LOCAL

   Worker:

     V = {init_val<T> (OPERATOR)}

   Gang:

     V = {init_val<T> (OPERATOR)}
*/

static bool
nvptx_goacc_reduction_init (gimple call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  tree v = gimple_call_lhs (call);
  tree local_var = gimple_call_arg (call, 1);
  tree clause = build_omp_clause (UNKNOWN_LOCATION, OMP_CLAUSE_REDUCTION);
  int loop_dim = tree_to_shwi (gimple_call_arg (call, 2));
  tree local_vartype = TREE_TYPE (local_var);
  enum tree_code op;
  gimple_seq seq = NULL;
  bool retval = false;

  op = (enum tree_code) tree_to_shwi (gimple_call_arg (call, 3));
  OMP_CLAUSE_REDUCTION_CODE (clause) = op;

  switch (loop_dim)
    {
    case GOMP_DIM_GANG:
    case GOMP_DIM_WORKER:
      push_gimplify_context (true);
      gimplify_assign(v, omp_reduction_init (clause, local_vartype), &seq);
      pop_gimplify_context (NULL);
      gsi_replace_with_seq (&gsi, seq, true);
      break;
    case GOMP_DIM_VECTOR:
      {
	tree tid = make_ssa_name (unsigned_type_node);
	tree dim_vector = build_int_cst (unsigned_type_node, GOMP_DIM_VECTOR);
	gimple tid_call = gimple_build_call_internal (IFN_GOACC_DIM_POS, 1,
						      dim_vector);

	gimple_call_set_lhs (tid_call, tid);
	gsi_insert_before (&gsi, tid_call, GSI_SAME_STMT);

	tree zero = build_int_cst (unsigned_type_node, 0);
	gimple cond_stmt = gimple_build_cond (NE_EXPR, tid, zero,
					      NULL_TREE, NULL_TREE);

	gsi_insert_before (&gsi, cond_stmt, GSI_SAME_STMT);

	basic_block cond_bb = gsi_bb (gsi);
	edge e = split_block (cond_bb, cond_stmt);
	basic_block fallthru_bb = e->dest;
	basic_block true_bb = create_empty_bb (cond_bb);
	basic_block false_bb = create_empty_bb (cond_bb);
	gimple_stmt_iterator true_gsi = gsi_start_bb (true_bb);
	gimple_stmt_iterator false_gsi = gsi_start_bb (false_bb);

	/* True case: v = gomp_init_reduction () */

	make_edge (cond_bb, true_bb, EDGE_TRUE_VALUE);
	edge etrue = make_edge (true_bb, fallthru_bb, EDGE_FALLTHRU);
	remove_edge (e);

	add_bb_to_loop (true_bb, cond_bb->loop_father);
	set_immediate_dominator (CDI_DOMINATORS, true_bb, cond_bb);

	tree true_v = make_ssa_name (local_vartype);
	seq = NULL;

	push_gimplify_context (true);
	gimplify_assign (true_v, omp_reduction_init (clause, local_vartype),
			 &seq);
	pop_gimplify_context (NULL);
	gsi_insert_seq_after (&true_gsi, seq, GSI_CONTINUE_LINKING);
	gsi = gsi_start_bb (fallthru_bb);

	/* False case: v = local_var  */

	make_edge (cond_bb, false_bb, EDGE_FALSE_VALUE);
	edge efalse = make_edge (false_bb, fallthru_bb, EDGE_FALLTHRU);

	tree false_v = make_ssa_name (local_vartype);
	seq = NULL;

	push_gimplify_context (true);
	gimplify_assign (false_v, local_var, &seq);
	pop_gimplify_context (NULL);
	gsi_insert_seq_after (&false_gsi, seq, GSI_CONTINUE_LINKING);

	gsi = gsi_for_stmt (call);

	add_bb_to_loop (false_bb, cond_bb->loop_father);
	set_immediate_dominator (CDI_DOMINATORS, false_bb, cond_bb);

	gsi_remove (&gsi, true);

	/* Update phi.  */

	gphi *phi = create_phi_node (v, fallthru_bb);
	add_phi_arg (phi, true_v, etrue, UNKNOWN_LOCATION);
	add_phi_arg (phi, false_v, efalse, UNKNOWN_LOCATION);

	retval = true;
      }
      break;
    default:
      gcc_unreachable ();
    }

  return retval;
}

/* NVPTX implementation of GOACC_REDUCTION_FINI. For vectors, preform
   a tree reduction on LOCAL, otherwise, preform the reduction operation
   atomically.

   Given:

     V = IFN_RED_INIT (RES_PTR, LOCAL, LEVEL, OP, LID, RID)

   Expand to:

   Vector:

     for (ix = IFN_OACC_DIM_SIZE (VECTOR); ix >>= 1;)
       {
          T tmp = ptx_shuffle_down<T> (LOCAL, ix);
          LOCAL = OP (LOCAL, tmp);
       }
     V = LOCAL

   Worker:

     T tmp = *ptx_work_red_addr<T> (LID, RID);
     tmp = OP (tmp, LOCAL);
     *ptx_work_red_addr<T> (LID, RID) = tmp;

   Gang:

     V = OPERATOR (*RES_PTR, LOCAL);
     *RES_PTR = V;
*/

static bool
nvptx_goacc_reduction_fini (gimple call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  tree v = gimple_call_lhs (call);
  tree ref_to_res = gimple_call_arg (call, 0);
  tree local_var = gimple_call_arg (call, 1);
  int loop_dim = tree_to_shwi (gimple_call_arg (call, 2));
  enum tree_code op = (enum tree_code)tree_to_shwi (gimple_call_arg (call, 3));
  tree lid = gimple_call_arg (call, 4);
  tree rid = gimple_call_arg (call, 5);
  tree local_vartype = TREE_TYPE (local_var);
  gimple_seq seq = NULL;

  if (op == TRUTH_ANDIF_EXPR)
    op = BIT_AND_EXPR;
  else if (op == TRUTH_ORIF_EXPR)
    op = BIT_IOR_EXPR;

  push_gimplify_context (true);

  switch (loop_dim)
    {
    case GOMP_DIM_GANG:
      {
	tree ref = build_simple_mem_ref (ref_to_res);
	tree t = make_ssa_name (local_vartype);

	gimplify_assign (t, fold_build2 (op, local_vartype, ref, local_var),
			 &seq);
	gimplify_assign (ref, t, &seq);

	if (v != NULL)
	  {
	    push_gimplify_context (true);
	    gimplify_assign (v, t, &seq);
	  }
      }
      break;
    case GOMP_DIM_WORKER:
      {
	tree ptr = make_ssa_name (build_pointer_type (local_vartype));
	tree call = nvptx_get_worker_red_addr_fn (local_var, rid, lid);
	tree t1 = make_ssa_name (local_vartype);
	tree t2 = make_ssa_name (local_vartype);
	tree ref;

	gimplify_assign (ptr, call, &seq);
	ref = build_simple_mem_ref (ptr);
	TREE_THIS_VOLATILE (ref) = 1;
	gimplify_assign (t1, ref, &seq);
	gimplify_assign (t2, fold_build2 (op, local_vartype, t1, local_var),
			 &seq);
	ref = build_simple_mem_ref (ptr);
	gimplify_assign (ref, t2, &seq);
	TREE_THIS_VOLATILE (ref) = 1;

	if (v != NULL)
	  gimplify_assign (v, t2, &seq);
      }
      break;
    case GOMP_DIM_VECTOR:
      nvptx_shuffle_reduction (v, local_var, op, &seq);
      break;
    default:
      gcc_unreachable ();
    }

  push_gimplify_context (true);

  gsi_replace_with_seq (&gsi, seq, true);

  return false;
}

/* NVPTX implementation of GOACC_REDUCTION_TEARDOWN.  For workers
   and vectors, ensure that V has the final reduction value.  Likewise,
   for gangs, writeback V to RES_PTR if necessary.

   Given:

     V = IFN_RED_TEARDOWN (RES_PTR, LOCAL, LEVEL, OP, LID, RID)

   Expand to:

   Vector:

     V = LOCAL;

   Worker:

     ptx_mem_bar (WORKER)
     V = *ptx_work_red_addr<T> (LID, RID);

   Gang:

     if (RES_PTR != NULL)
       V = LOCAL
*/

static bool
nvptx_goacc_reduction_teardown (gimple call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  tree v = gimple_call_lhs (call);
  tree local_var = gimple_call_arg (call, 1);
  int loop_dim = tree_to_shwi (gimple_call_arg (call, 2));
  tree lid = gimple_call_arg (call, 4);
  tree rid = gimple_call_arg (call, 5);
  gimple_seq seq = NULL;

  if (v == NULL)
    {
      gsi_remove (&gsi, true);
      return false;
    }

  push_gimplify_context (true);

  switch (loop_dim)
    {
    case GOMP_DIM_GANG:
    case GOMP_DIM_VECTOR:
      gimplify_assign (v, local_var, &seq);
      break;
    case GOMP_DIM_WORKER:
      {
	tree ptr = make_ssa_name (build_pointer_type (TREE_TYPE (local_var)));
	tree call = nvptx_get_worker_red_addr_fn (local_var, rid, lid);
	tree ref;

	gimplify_assign (ptr, call, &seq);
	ref = build_simple_mem_ref (ptr);
	TREE_THIS_VOLATILE (ref) = 1;
	gimplify_assign (v, ref, &seq);
      }
      break;
    default:
      gcc_unreachable ();
    }

  pop_gimplify_context (NULL);

  gsi_replace_with_seq (&gsi, seq, true);

  return false;
}

/* Default goacc.reduction early expander.  */

bool
nvptx_goacc_reduction (gimple call)
{
  /* Reductions modify the SSA names in complicated ways.  Let update_ssa
     correct it.  */
  mark_virtual_operands_for_renaming (cfun);

  switch (gimple_call_internal_fn (call))
    {
    case IFN_GOACC_REDUCTION_SETUP:
      return nvptx_goacc_reduction_setup (call);

    case IFN_GOACC_REDUCTION_INIT:
      return nvptx_goacc_reduction_init (call);

    case IFN_GOACC_REDUCTION_FINI:
      return nvptx_goacc_reduction_fini (call);

    case IFN_GOACC_REDUCTION_TEARDOWN:
      return nvptx_goacc_reduction_teardown (call);

    default:
      gcc_unreachable ();
    }
}

/* Don't allow use of anchored addresses.  */

static bool
nvptx_use_anchors_for_symbol (const_rtx ARG_UNUSED (symbol))
{
  return false;
}

#undef TARGET_OPTION_OVERRIDE
#define TARGET_OPTION_OVERRIDE nvptx_option_override

#undef TARGET_ATTRIBUTE_TABLE
#define TARGET_ATTRIBUTE_TABLE nvptx_attribute_table

#undef TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P nvptx_legitimate_address_p

#undef  TARGET_PROMOTE_FUNCTION_MODE
#define TARGET_PROMOTE_FUNCTION_MODE nvptx_promote_function_mode

#undef TARGET_FUNCTION_ARG
#define TARGET_FUNCTION_ARG nvptx_function_arg
#undef TARGET_FUNCTION_INCOMING_ARG
#define TARGET_FUNCTION_INCOMING_ARG nvptx_function_incoming_arg
#undef TARGET_FUNCTION_ARG_ADVANCE
#define TARGET_FUNCTION_ARG_ADVANCE nvptx_function_arg_advance
#undef TARGET_FUNCTION_ARG_BOUNDARY
#define TARGET_FUNCTION_ARG_BOUNDARY nvptx_function_arg_boundary
#undef TARGET_FUNCTION_ARG_ROUND_BOUNDARY
#define TARGET_FUNCTION_ARG_ROUND_BOUNDARY nvptx_function_arg_boundary
#undef TARGET_PASS_BY_REFERENCE
#define TARGET_PASS_BY_REFERENCE nvptx_pass_by_reference
#undef TARGET_FUNCTION_VALUE_REGNO_P
#define TARGET_FUNCTION_VALUE_REGNO_P nvptx_function_value_regno_p
#undef TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE nvptx_function_value
#undef TARGET_LIBCALL_VALUE
#define TARGET_LIBCALL_VALUE nvptx_libcall_value
#undef TARGET_FUNCTION_OK_FOR_SIBCALL
#define TARGET_FUNCTION_OK_FOR_SIBCALL nvptx_function_ok_for_sibcall
#undef TARGET_GET_DRAP_RTX
#define TARGET_GET_DRAP_RTX nvptx_get_drap_rtx
#undef TARGET_SPLIT_COMPLEX_ARG
#define TARGET_SPLIT_COMPLEX_ARG hook_bool_const_tree_true
#undef TARGET_RETURN_IN_MEMORY
#define TARGET_RETURN_IN_MEMORY nvptx_return_in_memory
#undef TARGET_OMIT_STRUCT_RETURN_REG
#define TARGET_OMIT_STRUCT_RETURN_REG true
#undef TARGET_STRICT_ARGUMENT_NAMING
#define TARGET_STRICT_ARGUMENT_NAMING nvptx_strict_argument_naming
#undef TARGET_STATIC_CHAIN
#define TARGET_STATIC_CHAIN nvptx_static_chain

#undef TARGET_CALL_ARGS
#define TARGET_CALL_ARGS nvptx_call_args
#undef TARGET_END_CALL_ARGS
#define TARGET_END_CALL_ARGS nvptx_end_call_args

#undef TARGET_ASM_FILE_START
#define TARGET_ASM_FILE_START nvptx_file_start
#undef TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END nvptx_file_end
#undef TARGET_ASM_GLOBALIZE_LABEL
#define TARGET_ASM_GLOBALIZE_LABEL nvptx_globalize_label
#undef TARGET_ASM_ASSEMBLE_UNDEFINED_DECL
#define TARGET_ASM_ASSEMBLE_UNDEFINED_DECL nvptx_assemble_undefined_decl
#undef  TARGET_PRINT_OPERAND
#define TARGET_PRINT_OPERAND nvptx_print_operand
#undef  TARGET_PRINT_OPERAND_ADDRESS
#define TARGET_PRINT_OPERAND_ADDRESS nvptx_print_operand_address
#undef  TARGET_PRINT_OPERAND_PUNCT_VALID_P
#define TARGET_PRINT_OPERAND_PUNCT_VALID_P nvptx_print_operand_punct_valid_p
#undef TARGET_ASM_INTEGER
#define TARGET_ASM_INTEGER nvptx_assemble_integer
#undef TARGET_ASM_DECL_END
#define TARGET_ASM_DECL_END nvptx_assemble_decl_end
#undef TARGET_ASM_DECLARE_CONSTANT_NAME
#define TARGET_ASM_DECLARE_CONSTANT_NAME nvptx_asm_declare_constant_name
#undef TARGET_USE_BLOCKS_FOR_CONSTANT_P
#define TARGET_USE_BLOCKS_FOR_CONSTANT_P hook_bool_mode_const_rtx_true
#undef TARGET_ASM_NEED_VAR_DECL_BEFORE_USE
#define TARGET_ASM_NEED_VAR_DECL_BEFORE_USE true

#undef TARGET_MACHINE_DEPENDENT_REORG
#define TARGET_MACHINE_DEPENDENT_REORG nvptx_reorg
#undef TARGET_NO_REGISTER_ALLOCATION
#define TARGET_NO_REGISTER_ALLOCATION true

#undef TARGET_RECORD_OFFLOAD_SYMBOL
#define TARGET_RECORD_OFFLOAD_SYMBOL nvptx_record_offload_symbol

#undef TARGET_VECTOR_ALIGNMENT
#define TARGET_VECTOR_ALIGNMENT nvptx_vector_alignment

#undef TARGET_CANNOT_COPY_INSN_P
#define TARGET_CANNOT_COPY_INSN_P nvptx_cannot_copy_insn_p

#undef TARGET_INIT_BUILTINS
#define TARGET_INIT_BUILTINS nvptx_init_builtins
#undef TARGET_EXPAND_BUILTIN
#define TARGET_EXPAND_BUILTIN nvptx_expand_builtin
#undef  TARGET_BUILTIN_DECL
#define TARGET_BUILTIN_DECL nvptx_builtin_decl

#undef TARGET_GOACC_VALIDATE_DIMS
#define TARGET_GOACC_VALIDATE_DIMS nvptx_validate_dims

#undef TARGET_GOACC_DIM_LIMIT
#define TARGET_GOACC_DIM_LIMIT nvptx_dim_limit

#undef TARGET_GOACC_FORK_JOIN
#define TARGET_GOACC_FORK_JOIN nvptx_xform_fork_join

#undef TARGET_GOACC_LOCK
#define TARGET_GOACC_LOCK nvptx_xform_lock

#undef TARGET_GOACC_REDUCTION
#define TARGET_GOACC_REDUCTION nvptx_goacc_reduction

#undef TARGET_USE_ANCHORS_FOR_SYMBOL_P
#define TARGET_USE_ANCHORS_FOR_SYMBOL_P nvptx_use_anchors_for_symbol

struct gcc_target targetm = TARGET_INITIALIZER;

#include "gt-nvptx.h"
