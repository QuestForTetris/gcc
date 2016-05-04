/* GCC MELT GENERATED C++ FILE warmelt-hooks+01.cc - DO NOT EDIT - see http://gcc-melt.org/ */
/* secondary MELT generated C++ file of rank #1 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f1[] = MELT_RUN_HASHMD5 /* from melt-run.h */;


/**** warmelt-hooks+01.cc declarations ****/
/**** MELT GENERATED DECLARATIONS for warmelt-hooks ** DO NOT EDIT ; see gcc-melt.org ****/

/****++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
***
    Copyright 2012 - 2014  Free Software Foundation, Inc.
    Contributed by Basile Starynkevitch <basile@starynkevitch.net>

    This file is part of GCC.

    GCC is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3, or (at your option)
    any later version.

    GCC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GCC; see the file COPYING3.  If not see
    <http://www.gnu.org/licenses/>.
***
----------------------------------------------------------------****/


/** ordinary MELT module meltbuild-sources/warmelt-hooks**/
#define MELT_HAS_INITIAL_ENVIRONMENT 1 /*usualmodule*/



class Melt_InitialClassyFrame_WARMELTmiHOOKS_h244320376; // forward declaration fromline 6691
typedef Melt_InitialClassyFrame_WARMELTmiHOOKS_h244320376 Melt_InitialFrame;
/*** 8 MELT module variables declarations ****/
MELT_EXTERN void melt_forwarding_module_data (void);
MELT_EXTERN void melt_marking_module_data (void);

MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY melt_WARMELTmiHOOKS_module_var_ptr_tab[16];
MELT_EXTERN bool MELT_MODULE_VISIBILITY melt_WARMELTmiHOOKS_module_var_flags[1];

static inline melt_ptr_t
melt_module_var_fetch (int ix)
{
    return (ix > 0  &&  ix <= 8)?melt_WARMELTmiHOOKS_module_var_ptr_tab[ix]:NULL;
}

static inline void
melt_module_var_put (int ix, melt_ptr_t val)
{
    if (ix > 0  &&  ix <= 8)
        {
            melt_WARMELTmiHOOKS_module_var_ptr_tab[ix]= val;
            melt_WARMELTmiHOOKS_module_var_flags[ix/16] = true;
        }
}

/* MELT module variables indexes */
enum
{
    meltmodatix_none,
    meltmodvarix_GCC_ATTRIBUTE_DICT_symb = 1,
    meltmodvarix_GCC_ATTRIBUTE_INSTALLER_LIST_symb = 2,
    meltmodvarix_PRAGMA_PROCESSOR_symb = 3,
    meltmodvarix_PRAGMA_HANDLER_TUPLE_symb = 4,
    meltmodvarix_MELT_INPCHANBUCK_symb = 5,
    meltmodvarix_JSON_NAME_DICT_symb = 6,
    meltmodvarix_MELT_ALARMBUCKET_symb = 7,
    meltmodvarix_MELT_CHILDBUCK_symb = 8,
    meltmodatix_last
}; /* end MELT module variables indexes */

/*** 4 MELT called hook declarations ***/

/*declare MELT called hook #0 HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_PREVENV, const char* meltinp1_MODULNAME);

/*declare MELT called hook #1 HOOK_MACRO_EXPORTER **/
MELT_EXTERN void melthook_HOOK_MACRO_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_VAL, melt_ptr_t meltinp2_CONTENV);

/*declare MELT called hook #2 HOOK_SYMBOL_IMPORTER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_SYMBOL_IMPORTER (melt_ptr_t melthookdatap, const char* meltinp0_SYMNAMESTR, const char* meltinp1_MODULENAMESTR, melt_ptr_t meltinp2_PARENV);

/*declare MELT called hook #3 HOOK_VALUE_EXPORTER **/
MELT_EXTERN void melthook_HOOK_VALUE_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_VAL, melt_ptr_t meltinp2_CONTENV);

/*** end of 4 MELT called hook declarations ***/

/*** 29 extra MELT c-headers ***/


/** MELT extra c-header 1 : h25383009 **/

/* cheader for override gate in warmelt-hooks.melt */
static void
melt_override_gate_callback (void* gccdata,
                             void* userdata ATTRIBUTE_UNUSED)
{
    bool *pgatestatus = (bool*) gccdata;
    bool gatsta = false;
    long oldgatstalng = 0, newgatstalng = 0;
    gcc_assert (pgatestatus != NULL);
    gatsta = *pgatestatus;
    oldgatstalng = newgatstalng = (long)gatsta;
    melthookproc_HOOK_OVERRIDE_GATE (oldgatstalng, &newgatstalng);
    gatsta = (newgatstalng != 0L);
    *pgatestatus = gatsta;
} /* end of  melt_override_gate_callback */




/** MELT extra c-header 2 : h17996579 **/

/* flag for PLUGIN_OVERRIDE_GATE */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_override_gate_registered_flag;




/** MELT extra c-header 3 : h160333989 **/

/* flag for PLUGIN_START_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_start_unit_registered_flag;




/** MELT extra c-header 4 : h850751999 **/


void MELT_MODULE_VISIBILITY
melt_startunithook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                             void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 5 : h735898614 **/

/* flag for PLUGIN_FINISH_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_unit_registered_flag;




/** MELT extra c-header 6 : h484051762 **/


void MELT_MODULE_VISIBILITY
melt_finishunithook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                              void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 7 : h726359283 **/

/* flag for PLUGIN_ALL_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_passes_start_registered_flag;




/** MELT extra c-header 8 : h680852009 **/


void MELT_MODULE_VISIBILITY
melt_all_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                     void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 9 : h838302894 **/

/* flag for PLUGIN_ALL_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_passes_end_registered_flag;




/** MELT extra c-header 10 : h474747019 **/


void MELT_MODULE_VISIBILITY
melt_all_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 11 : h976685337 **/

/* flag for PLUGIN_ALL_IPA_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_ipa_passes_start_registered_flag;




/** MELT extra c-header 12 : h308476728 **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 13 : h547684143 **/

/* flag for PLUGIN_ALL_IPA_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_ipa_passes_end_registered_flag;




/** MELT extra c-header 14 : h219756380 **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                       void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 15 : h243258254 **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_early_gimple_passes_start_registered_flag;




/** MELT extra c-header 16 : h15470532 **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 17 : h154621044 **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_early_gimple_passes_end_registered_flag;




/** MELT extra c-header 18 : h794934896 **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 19 : h329325342 **/

/* flag for PLUGIN_PRE_GENERICIZE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_pre_genericize_registered_flag;




/** MELT extra c-header 20 : h119827664 **/


void MELT_MODULE_VISIBILITY
melt_pre_genericize_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 21 : h749010620 **/

/* flag for PLUGIN_FINISH_TYPE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_type_registered_flag;




/** MELT extra c-header 22 : h218546915 **/


void MELT_MODULE_VISIBILITY
melt_finish_type_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 23 : h944663762 **/

/* flag for PLUGIN_FINISH_DECL declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_decl_registered_flag;




/** MELT extra c-header 24 : h519729539 **/


void MELT_MODULE_VISIBILITY
melt_finish_decl_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 25 : h466161867 **/

/* flag for PLUGIN_PASS_EXECUTION declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_pass_execution_registered_flag;




/** MELT extra c-header 26 : h398570221 **/


void MELT_MODULE_VISIBILITY
melt_pass_execution_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);




/** MELT extra c-header 27 : h182032758 **/

/* cheader for attributes in warmelt-hooks.melt */
#if  MELT_GCC_VERSION >= 4009 /* GCC 4.9 or later */
#include "attribs.h"
#endif /*GCC 4.9*/
MELT_EXTERN tree MELT_MODULE_VISIBILITY melt_attribute_handler_glue
(tree *pnode, tree name, tree args, int flags, bool *no_add_attrs);




/** MELT extra c-header 28 : h130302843 **/

/* header from warmelt-hooks.melt for poll etc... */
#include <poll.h>

#define MELT_BUFSIZE 8192
#define MELT_POLL_DELAY_MILLISEC 500




/** MELT extra c-header 29 : h317017663 **/

/* headers before connect_to_server */
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <map>

struct Melt_connect_info
{
    std::string             mci_service;
    int             	   mci_family;
    int             	   mci_socktype;
    int             	   mci_protocol;
    socklen_t       	   mci_addrlen;
    struct sockaddr_storage mci_sockaddr;
};
typedef std::map<std::string,Melt_connect_info> melt_connect_info_map_t;
/* end of headers for connect_to_server */


/*** end of 29 extra MELT c-headers ***/

/** start of declaration for hook melthook_HOOK_LOW_DEBUG_VALUE_AT**/

/** declaration of hook melthook_HOOK_LOW_DEBUG_VALUE_AT */
MELT_EXTERN
void melthook_HOOK_LOW_DEBUG_VALUE_AT(melt_ptr_t melthookdatap,
                                      melt_ptr_t meltinp0_VAL,
                                      const char* meltinp1_FILENAME,
                                      long meltinp2_LINENO,
                                      const char* meltinp3_MSG,
                                      long meltinp4_COUNT)
;



/** end of declaration for hook melthook_HOOK_LOW_DEBUG_VALUE_AT**/



/** start of declaration for hook melthook_HOOK_LOW_STDERR_VALUE_AT**/

/** declaration of hook melthook_HOOK_LOW_STDERR_VALUE_AT */
MELT_EXTERN
void melthook_HOOK_LOW_STDERR_VALUE_AT(melt_ptr_t melthookdatap,
                                       melt_ptr_t meltinp0_VAL,
                                       const char* meltinp1_FILENAME,
                                       long meltinp2_LINENO,
                                       const char* meltinp3_MSG,
                                       long meltinp4_COUNT)
;



/** end of declaration for hook melthook_HOOK_LOW_STDERR_VALUE_AT**/



/** start of declaration for hook melthook_HOOK_OVERRIDE_GATE**/

/** declaration of hook melthook_HOOK_OVERRIDE_GATE */
MELT_EXTERN
void melthook_HOOK_OVERRIDE_GATE(melt_ptr_t melthookdatap,
                                 long meltinp0_BEFOREGATE,
                                 long* meltoutp0_AFTERGATE)
;



/** end of declaration for hook melthook_HOOK_OVERRIDE_GATE**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_4_WARMELTmiHOOKS_ENABLE_OVERRIDE_GATE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_5_WARMELTmiHOOKS_MAYBE_DISABLE_OVERRIDE_GATE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_6_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_7_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_8_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_9_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_10_WARMELTmiHOOKS_LAMBDA_cl1(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_11_WARMELTmiHOOKS_LAMBDA_cl2(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_12_WARMELTmiHOOKS_LAMBDA_cl3(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_START_UNIT**/

/** declaration of hook melthook_HOOK_START_UNIT */
MELT_EXTERN
void melthook_HOOK_START_UNIT(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_START_UNIT**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_14_WARMELTmiHOOKS_ENABLE_START_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_UNIT**/

/** declaration of hook melthook_HOOK_FINISH_UNIT */
MELT_EXTERN
void melthook_HOOK_FINISH_UNIT(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_FINISH_UNIT**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_PASSES_START**/

/** declaration of hook melthook_HOOK_ALL_PASSES_START */
MELT_EXTERN
void melthook_HOOK_ALL_PASSES_START(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_ALL_PASSES_START**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_PASSES_END**/

/** declaration of hook melthook_HOOK_ALL_PASSES_END */
MELT_EXTERN
void melthook_HOOK_ALL_PASSES_END(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_ALL_PASSES_END**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_IPA_PASSES_START**/

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_START */
MELT_EXTERN
void melthook_HOOK_ALL_IPA_PASSES_START(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_ALL_IPA_PASSES_START**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_IPA_PASSES_END**/

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_END */
MELT_EXTERN
void melthook_HOOK_ALL_IPA_PASSES_END(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_ALL_IPA_PASSES_END**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_START**/

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_START */
MELT_EXTERN
void melthook_HOOK_EARLY_GIMPLE_PASSES_START(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_START**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_END**/

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_END */
MELT_EXTERN
void melthook_HOOK_EARLY_GIMPLE_PASSES_END(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_END**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_45_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_46_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_47_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_48_WARMELTmiHOOKS_ENABLE_PRE_GENERICIZE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_PRE_GENERICIZE**/

/** declaration of hook melthook_HOOK_PRE_GENERICIZE */
MELT_EXTERN
void melthook_HOOK_PRE_GENERICIZE(melt_ptr_t melthookdatap,
                                  melt_treeptr_t meltinp0_TFNDECL)
;



/** end of declaration for hook melthook_HOOK_PRE_GENERICIZE**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_50_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_51_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_52_WARMELTmiHOOKS_ENABLE_FINISH_TYPE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_TYPE**/

/** declaration of hook melthook_HOOK_FINISH_TYPE */
MELT_EXTERN
void melthook_HOOK_FINISH_TYPE(melt_ptr_t melthookdatap,
                               melt_treeptr_t meltinp0_TFNDECL)
;



/** end of declaration for hook melthook_HOOK_FINISH_TYPE**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_54_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_55_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_56_WARMELTmiHOOKS_RUN_ENDMELTPASS_FUNCTIONS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_57_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_58_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_59_WARMELTmiHOOKS_ENABLE_FINISH_DECL(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_DECL**/

/** declaration of hook melthook_HOOK_FINISH_DECL */
MELT_EXTERN
void melthook_HOOK_FINISH_DECL(melt_ptr_t melthookdatap,
                               melt_treeptr_t meltinp0_TFNDECL)
;



/** end of declaration for hook melthook_HOOK_FINISH_DECL**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_61_WARMELTmiHOOKS_REGISTER_FINISH_DECL_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_62_WARMELTmiHOOKS_REGISTER_FINISH_DECL_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_PASS_EXECUTION**/

/** declaration of hook melthook_HOOK_PASS_EXECUTION */
MELT_EXTERN
void melthook_HOOK_PASS_EXECUTION(melt_ptr_t melthookdatap,
                                  const char* meltinp0_PASSNAME,
                                  long meltinp1_PASSNUM,
                                  long meltinp2_TYPENUM)
;



/** end of declaration for hook melthook_HOOK_PASS_EXECUTION**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_64_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_65_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_GIMPLE_GATE**/

/** declaration of hook melthook_HOOK_GIMPLE_GATE */
MELT_EXTERN
long melthook_HOOK_GIMPLE_GATE(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_GIMPLE_GATE**/



/** start of declaration for hook melthook_HOOK_GIMPLE_EXECUTE**/

/** declaration of hook melthook_HOOK_GIMPLE_EXECUTE */
MELT_EXTERN
long melthook_HOOK_GIMPLE_EXECUTE(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_GIMPLE_EXECUTE**/



/** start of declaration for hook melthook_HOOK_RTL_GATE**/

/** declaration of hook melthook_HOOK_RTL_GATE */
MELT_EXTERN
long melthook_HOOK_RTL_GATE(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_RTL_GATE**/



/** start of declaration for hook melthook_HOOK_RTL_EXECUTE**/

/** declaration of hook melthook_HOOK_RTL_EXECUTE */
MELT_EXTERN
long melthook_HOOK_RTL_EXECUTE(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_RTL_EXECUTE**/



/** start of declaration for hook melthook_HOOK_SIMPLE_IPA_EXECUTE**/

/** declaration of hook melthook_HOOK_SIMPLE_IPA_EXECUTE */
MELT_EXTERN
long melthook_HOOK_SIMPLE_IPA_EXECUTE(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_SIMPLE_IPA_EXECUTE**/



/** start of declaration for hook melthook_HOOK_MELT_DO_INITIAL_MODE**/

/** declaration of hook melthook_HOOK_MELT_DO_INITIAL_MODE */
MELT_EXTERN
void melthook_HOOK_MELT_DO_INITIAL_MODE(melt_ptr_t melthookdatap,
                                        melt_ptr_t meltinp0_MODATA,
                                        const char* meltinp1_MODSTR)
;



/** end of declaration for hook melthook_HOOK_MELT_DO_INITIAL_MODE**/



/** start of declaration for hook melthook_HOOK_INSTALL_ATTRIBUTES**/

/** declaration of hook melthook_HOOK_INSTALL_ATTRIBUTES */
MELT_EXTERN
void melthook_HOOK_INSTALL_ATTRIBUTES(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_INSTALL_ATTRIBUTES**/



/** start of declaration for hook melthook_HOOK_HANDLE_ATTRIBUTE**/

/** declaration of hook melthook_HOOK_HANDLE_ATTRIBUTE */
MELT_EXTERN
melt_treeptr_t melthook_HOOK_HANDLE_ATTRIBUTE(melt_ptr_t melthookdatap,
        melt_treeptr_t meltinp0_TR_IN_NODE,
        melt_treeptr_t meltinp1_TR_NAME,
        melt_treeptr_t meltinp2_TR_ARGS,
        long meltinp3_FLAGS,
        melt_treeptr_t* meltoutp0_TR_OUT_NODE,
        long* meltoutp1_OUT_NO_ADD_ATTRS)
;



/** end of declaration for hook melthook_HOOK_HANDLE_ATTRIBUTE**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_74_WARMELTmiHOOKS_REGISTER_GCC_ATTRIBUTE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_75_WARMELTmiHOOKS_MELT_REGISTER_GCC_ATTRIBUTE_AT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_76_WARMELTmiHOOKS_LAMBDA_cl7(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EXIT_FINALIZER**/

/** declaration of hook melthook_HOOK_EXIT_FINALIZER */
MELT_EXTERN
void melthook_HOOK_EXIT_FINALIZER(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_EXIT_FINALIZER**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_78_WARMELTmiHOOKS_AT_EXIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_79_WARMELTmiHOOKS_AT_EXIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_80_WARMELTmiHOOKS_REGISTER_PRAGMA_PROCESSOR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_PROCESS_PRAGMA**/

/** declaration of hook melthook_HOOK_PROCESS_PRAGMA */
MELT_EXTERN
void melthook_HOOK_PROCESS_PRAGMA(melt_ptr_t melthookdatap,
                                  long meltinp0_LIX)
;



/** end of declaration for hook melthook_HOOK_PROCESS_PRAGMA**/



/** start of declaration for hook melthook_HOOK_REGISTER_PRAGMAS**/

/** declaration of hook melthook_HOOK_REGISTER_PRAGMAS */
MELT_EXTERN
void melthook_HOOK_REGISTER_PRAGMAS(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_REGISTER_PRAGMAS**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_83_WARMELTmiHOOKS_ADD_PRAGMA_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_84_WARMELTmiHOOKS_REMOVE_PRAGMA_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_85_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_POLL_INPUTS**/

/** declaration of hook melthook_HOOK_POLL_INPUTS */
MELT_EXTERN
void melthook_HOOK_POLL_INPUTS(melt_ptr_t melthookdatap,
                               long meltinp0_DELAYMS)
;



/** end of declaration for hook melthook_HOOK_POLL_INPUTS**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_87_WARMELTmiHOOKS_IS_POLLING_INPUTS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_88_WARMELTmiHOOKS_EVERY_POLLING_INPUT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_89_WARMELTmiHOOKS_GET_POLLING_INPUT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_90_WARMELTmiHOOKS_REGISTER_PARAGRAPH_INPUT_CHANNEL_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_91_WARMELTmiHOOKS_REGISTER_RAW_INPUT_CHANNEL_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_92_WARMELTmiHOOKS_UNREGISTER_INPUT_CHANNEL(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_93_WARMELTmiHOOKS_CONNECT_TO_SERVER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_94_WARMELTmiHOOKS_JSON_LEXER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_95_WARMELTmiHOOKS_JSON_STATE_ACCEPTING_JVALUE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_96_WARMELTmiHOOKS_MAKE_JSON_PARSER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_97_WARMELTmiHOOKS_JSON_PARSER_INPUT_PROCESSOR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_98_WARMELTmiHOOKS_DO_BLOCKING_JSONRPC2_CALL(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_99_WARMELTmiHOOKS_LAMBDA_cl8(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_100_WARMELTmiHOOKS_LAMBDA_cl9(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_HANDLE_SIGIO**/

/** declaration of hook melthook_HOOK_HANDLE_SIGIO */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGIO(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_HANDLE_SIGIO**/



/** start of declaration for hook melthook_HOOK_HANDLE_SIGALRM**/

/** declaration of hook melthook_HOOK_HANDLE_SIGALRM */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGALRM(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_HANDLE_SIGALRM**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_103_WARMELTmiHOOKS_REGISTER_ALARM_TIMER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_104_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_HANDLE_SIGCHLD**/

/** declaration of hook melthook_HOOK_HANDLE_SIGCHLD */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGCHLD(melt_ptr_t melthookdatap)
;



/** end of declaration for hook melthook_HOOK_HANDLE_SIGCHLD**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_106_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_107_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);


MELT_EXTERN MELT_LOW_OPTIMIZATION void* melt_start_this_module (void*); /*mandatory start of module*/

MELT_EXTERN const char melt_module_is_gpl_compatible[];

/*declare opaque initial frame: */

typedef Melt_InitialClassyFrame_WARMELTmiHOOKS_h244320376 /*opaqueinitialclassy*/ meltinitial_frame_t;


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG > 0
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG*/
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG*/



void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_0 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_1 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_2 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_3 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_4 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_5 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_6 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_7 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_8 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_9 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_10 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_11 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_12 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_13 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_14 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_15 (meltinitial_frame_t*, char*); //declare

void MELT_MODULE_VISIBILITY MELT_LOW_OPTIMIZATION meltmod__WARMELTmiHOOKS__initialmeltchunk_16 (meltinitial_frame_t*, char*); //declare



/**** warmelt-hooks+01.cc implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST fromline 1752 */

    /** start of frame for meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST), clos) {};
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST)) {};
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST


    /** end of frame for meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST fromline 1697**/

    /* end of frame for routine meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST fromline 1756 */

    /* classy proc frame meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST */ MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("AT_START_UNIT_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:379:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:381:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!START_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
            /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:383:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:384:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_START_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:385:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:383:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:381:/ clear");
        /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_START_UNIT_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST fromline 1752 */

    /** start of frame for meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST), clos) {};
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST)) {};
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST


    /** end of frame for meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST fromline 1697**/

    /* end of frame for routine meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST fromline 1756 */

    /* classy proc frame meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST */ MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("AT_START_UNIT_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:388:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:390:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!START_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 3, "DELQU_LAST");
            /*_.LASTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:392:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:393:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_START_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:394:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:392:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:390:/ clear");
        /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_START_UNIT_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 fromline 1752 */

    /** start of frame for meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4), clos) {};
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4)) {};
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4


    /** end of frame for meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 fromline 1697**/

    /* end of frame for routine meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 fromline 1756 */

    /* classy proc frame meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 */ MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl4", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:428:/ getarg");
    /*_.FIRSTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:429:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 0, "REFERENCED_VALUE");
            /*_.PREVRES__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:430:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0]);
            /*_.NEXTRES__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)(/*_.FIRSTPROC__V2*/ meltfptr[1]), (melt_ptr_t)(/*_.PREVRES__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:432:/ quasiblock");


        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @REFERENCED_VALUE", melt_magic_discr((melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0]))) == MELTOBMAG_OBJECT);
        melt_putfield_object(((/*~RESCONT*/ meltfclos->tabval[0])), (0), (/*_.NEXTRES__V4*/ meltfptr[3]), "REFERENCED_VALUE");
        ;
        /*^touch*/
        meltgc_touch((/*~RESCONT*/ meltfclos->tabval[0]));
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object ((/*~RESCONT*/ meltfclos->tabval[0]), "put-fields");
        ;


        MELT_LOCATION("warmelt-hooks.melt:429:/ clear");
        /*clear*/ /*_.PREVRES__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_.NEXTRES__V4*/ meltfptr[3] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl4", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 fromline 1752 */

    /** start of frame for meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5// fromline 1568
        : public Melt_CallFrameWithValues<2>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<2> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5), clos) {};
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5() //the constructor fromline 1642
            : Melt_CallFrameWithValues<2> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5)) {};
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5


    /** end of frame for meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 fromline 1697**/

    /* end of frame for routine meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 fromline 1756 */

    /* classy proc frame meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 */ MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl5", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:437:/ getarg");
    /*_.LASTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:438:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        meltgc_prepend_list((melt_ptr_t)((/*~REVLASTLIST*/ meltfclos->tabval[0])), (melt_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1]));
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:437:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl5", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 fromline 1752 */

    /** start of frame for meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6), clos) {};
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6)) {};
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6


    /** end of frame for meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 fromline 1697**/

    /* end of frame for routine meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 fromline 1756 */

    /* classy proc frame meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 */ MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl6", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:442:/ getarg");
    /*_.LASTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:443:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 0, "REFERENCED_VALUE");
            /*_.PREVRES__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:444:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0]);
            /*_.NEXTRES__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1]), (melt_ptr_t)(/*_.PREVRES__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:446:/ quasiblock");


        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @REFERENCED_VALUE", melt_magic_discr((melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0]))) == MELTOBMAG_OBJECT);
        melt_putfield_object(((/*~RESCONT*/ meltfclos->tabval[0])), (0), (/*_.NEXTRES__V4*/ meltfptr[3]), "REFERENCED_VALUE");
        ;
        /*^touch*/
        meltgc_touch((/*~RESCONT*/ meltfclos->tabval[0]));
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object ((/*~RESCONT*/ meltfclos->tabval[0]), "put-fields");
        ;


        MELT_LOCATION("warmelt-hooks.melt:443:/ clear");
        /*clear*/ /*_.PREVRES__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_.NEXTRES__V4*/ meltfptr[3] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl6", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT fromline 1752 */

    /** start of frame for meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT), clos) {};
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT)) {};
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT


    /** end of frame for meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT fromline 1697**/

    /* end of frame for routine meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT fromline 1756 */

    /* classy proc frame meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT */ MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_FINISH_UNIT", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:470:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:471:/ locexp");
            /* enable_finish_unit ENFINISHUNIT_CHK__1 */
            if (!melthk_finish_unit_registered_flag)
                {
                    melthk_finish_unit_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_FINISH_UNIT,
                                       melt_finishunithook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_FINISH_UNIT", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST fromline 1752 */

    /** start of frame for meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST), clos) {};
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST)) {};
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST


    /** end of frame for meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST fromline 1697**/

    /* end of frame for routine meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST fromline 1756 */

    /* classy proc frame meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST */ MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("AT_FINISH_UNIT_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:484:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:487:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
            /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:489:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:490:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_FINISH_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:491:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:489:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:487:/ clear");
        /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_FINISH_UNIT_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST fromline 1752 */

    /** start of frame for meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST// fromline 1568
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST), clos) {};
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST)) {};
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST


    /** end of frame for meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST fromline 1697**/

    /* end of frame for routine meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST fromline 1756 */

    /* classy proc frame meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST */ MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("AT_FINISH_UNIT_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:494:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:497:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 3, "DELQU_LAST");
            /*_.LASTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:499:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:500:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_FINISH_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:501:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:499:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:497:/ clear");
        /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_FINISH_UNIT_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START fromline 1752 */

    /** start of frame for meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START), clos) {};
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START)) {};
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START


    /** end of frame for meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START fromline 1697**/

    /* end of frame for routine meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START fromline 1756 */

    /* classy proc frame meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START */ MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_ALL_PASSES_START", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:570:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:571:/ locexp");
            /* enable_all_passes_start ENALLPASSESSTART_CHK__1 */
            if (!melthk_all_passes_start_registered_flag)
                {
                    melthk_all_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_PASSES_START,
                                       melt_all_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST fromline 1752 */

    /** start of frame for meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST


    /** end of frame for meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST fromline 1697**/

    /* end of frame for routine meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST fromline 1756 */

    /* classy proc frame meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST */ MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_PASSES_START_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:583:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:587:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:588:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:590:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:591:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:593:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:594:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:592:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:591:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:599:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:588:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:587:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:602:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_start_hook_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:583:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST fromline 1752 */

    /** start of frame for meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST)) {};
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST


    /** end of frame for meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST fromline 1697**/

    /* end of frame for routine meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST fromline 1756 */

    /* classy proc frame meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST */ MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_PASSES_START_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:606:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:610:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:611:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:613:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:614:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:616:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:617:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:615:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:614:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:622:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:611:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:610:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:625:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:606:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END fromline 1752 */

    /** start of frame for meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END), clos) {};
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END)) {};
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END


    /** end of frame for meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END fromline 1697**/

    /* end of frame for routine meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END fromline 1756 */

    /* classy proc frame meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END */ MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_ALL_PASSES_END", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:699:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:700:/ locexp");
            /* enable_all_passes_end ENALLPASSESEND_CHK__1 */
            if (!melthk_all_passes_end_registered_flag)
                {
                    melthk_all_passes_end_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_PASSES_END,
                                       melt_all_passes_end_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_PASSES_END", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST fromline 1752 */

    /** start of frame for meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST), clos) {};
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST)) {};
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST


    /** end of frame for meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST fromline 1697**/

    /* end of frame for routine meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST fromline 1756 */

    /* classy proc frame meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST */ MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_PASSES_END_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:712:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:716:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:717:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:719:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:720:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:722:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:723:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:721:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:720:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:728:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:717:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:716:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:731:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_end_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:712:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_END_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST fromline 1752 */

    /** start of frame for meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST), clos) {};
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST)) {};
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST


    /** end of frame for meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST fromline 1697**/

    /* end of frame for routine meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST fromline 1756 */

    /* classy proc frame meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST */ MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_PASSES_END_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:735:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:739:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:740:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:742:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:743:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:745:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:746:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:744:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:743:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:751:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:740:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:739:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:754:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_end_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:735:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_END_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START fromline 1752 */

    /** start of frame for meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START), clos) {};
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START)) {};
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START


    /** end of frame for meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START fromline 1697**/

    /* end of frame for routine meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START fromline 1756 */

    /* classy proc frame meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START */ MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_ALL_IPA_PASSES_START", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:821:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:822:/ locexp");
            /* enable_all_ipa_passes_start ENALLPASSESSTART_CHK__2 */
            if (!melthk_all_ipa_passes_start_registered_flag)
                {
                    melthk_all_ipa_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_IPA_PASSES_START,
                                       melt_all_ipa_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_IPA_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST fromline 1752 */

    /** start of frame for meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST


    /** end of frame for meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST fromline 1697**/

    /* end of frame for routine meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST fromline 1756 */

    /* classy proc frame meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST */ MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_IPA_PASSES_START_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:834:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:838:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:839:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:841:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:842:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:844:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:845:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:843:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:842:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:850:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:839:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:838:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:853:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_start_hook_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:834:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST fromline 1752 */

    /** start of frame for meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST)) {};
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST


    /** end of frame for meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST fromline 1697**/

    /* end of frame for routine meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST fromline 1756 */

    /* classy proc frame meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST */ MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_IPA_PASSES_START_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:857:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:861:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:862:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:864:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:865:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:867:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:868:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:866:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:865:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:873:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:862:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:861:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:876:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:857:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END fromline 1752 */

    /** start of frame for meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END), clos) {};
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END)) {};
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END


    /** end of frame for meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END fromline 1697**/

    /* end of frame for routine meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END fromline 1756 */

    /* classy proc frame meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END */ MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_ALL_IPA_PASSES_END", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:944:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:945:/ locexp");
            /* enable_all_ipa_passes_end ENALLPASSESEND_CHK__2 */
            if (!melthk_all_ipa_passes_end_registered_flag)
                {
                    melthk_all_ipa_passes_end_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_IPA_PASSES_END,
                                       melt_all_ipa_passes_end_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_IPA_PASSES_END", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST fromline 1752 */

    /** start of frame for meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST), clos) {};
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST)) {};
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST


    /** end of frame for meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST fromline 1697**/

    /* end of frame for routine meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST fromline 1756 */

    /* classy proc frame meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST */ MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_IPA_PASSES_END_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:957:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:961:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:962:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:964:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:965:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:967:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:968:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:966:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:965:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:973:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:962:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:961:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:976:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_end_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:957:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_END_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST fromline 1752 */

    /** start of frame for meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST), clos) {};
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST)) {};
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST


    /** end of frame for meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST fromline 1697**/

    /* end of frame for routine meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST fromline 1756 */

    /* classy proc frame meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST */ MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_ALL_IPA_PASSES_END_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:980:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:984:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:985:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:987:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:988:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:990:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:991:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:989:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:988:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:996:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:985:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:984:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:999:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_end_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:980:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_END_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START fromline 1752 */

    /** start of frame for meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START// fromline 1568
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1572*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START), clos) {};
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START() //the constructor fromline 1642
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START)) {};
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START


    /** end of frame for meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START fromline 1697**/

    /* end of frame for routine meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START fromline 1756 */

    /* classy proc frame meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START */ MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("ENABLE_EARLY_GIMPLE_PASSES_START", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:1067:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:1068:/ locexp");
            /* enable_early_gimple_passes_start ENALLPASSESSTART_CHK__3 */
            if (!melthk_early_gimple_passes_start_registered_flag)
                {
                    melthk_early_gimple_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_EARLY_GIMPLE_PASSES_START,
                                       melt_early_gimple_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_EARLY_GIMPLE_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST fromline 1752 */

    /** start of frame for meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST


    /** end of frame for meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST fromline 1697**/

    /* end of frame for routine meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST fromline 1756 */

    /* classy proc frame meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST */ MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_EARLY_GIMPLE_PASSES_START_FIRST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:1080:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:1084:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:1085:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:1087:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_EARLY_GIMPLE_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:1088:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1090:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1091:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:1089:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:1088:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:1096:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:1085:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:1084:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:1099:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_early_gimple_passes_start_hook_\
first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:1080:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_EARLY_GIMPLE_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST*/






melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG > 0
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1538

    /* start of frame for routine meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST fromline 1752 */

    /** start of frame for meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST of CLASS_PROCROUTINEOBJ from 1555**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST// fromline 1568
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1572*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1630
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1634*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1638*/
                sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST() //the constructor fromline 1642
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG > 0 /*fromline 1646*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1650*/
                sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG > 0 /*fromline 1654*/
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1656
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST)) {};
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1661
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1666*/

    }; // end  class MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST


    /** end of frame for meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST fromline 1697**/

    /* end of frame for routine meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST fromline 1756 */

    /* classy proc frame meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST */ MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST
    meltfram__ /*declfrastruct fromline 1780*/
    /*classyprocarg meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST fromline 1785*/
#if MELT_HAVE_DEBUG > 0
    (__FILE__, __LINE__, meltclosp_) /* fromline 1789*/
#else /*MELT_HAVE_DEBUG */
    (meltclosp_) /* fromline 1793*/
#endif /*MELT_HAVE_DEBUG */

    ;
#define meltframe meltfram__

    melt_trace_start("REGISTER_EARLY_GIMPLE_PASSES_START_LAST", meltcallcount);
    /*use arguments*/ (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:1103:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:1107:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:1108:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:1110:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_EARLY_GIMPLE_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*reallynil*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        (/*null*/(/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:1111:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1113:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1114:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:1112:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:1111:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:1119:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:1108:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:1107:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:1122:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_early_gimple_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:1103:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_EARLY_GIMPLE_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_melt;
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST*/




/**** end of warmelt-hooks+01.cc ****/

