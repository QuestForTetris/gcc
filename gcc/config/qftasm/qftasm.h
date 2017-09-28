/* Target machine header for the QFT computer. -quartata */
#pragma once

/*
 * We define two "registers": one for storing comparison codes (address 5) to make cbranch simpler,
 * and one for the stack pointer (address 6) which is required.
 */
enum reg_class { NO_REGS, CC_REG, STACK_POINTER, LIM_REG_CLASSES };

#define CC_ADDRESS "5"
#define SP_ADDRESS "6"

#define REGISTER_NAMES {CC_ADDRESS, SP_ADDRESS}
#define FIXED_REGISTERS {1, 1}
#define FIRST_PSEUDO_REGISTER 2
#define N_REG_CLASSES (int) LIM_REG_CLASSES

#define REGNO_REG_CLASS(REGNO) (REGNO > 1 ? NO_REGS : (REGNO ? STACK_POINTER : CC_REG))

/* Type info, change me */
#define INT_TYPE_SIZE 16
#define SHORT_TYPE_SIZE 16
#define LONG_TYPE_SIZE 16
#define LONG_LONG_TYPE_SIZE 16

#define FLOAT_TYPE_SIZE 16
#define DOUBLE_TYPE_SIZE 16
#define LONG_DOUBLE_TYPE_SIZE 16

#define DEFAULT_SIGNED_CHAR 0

#undef  SIZE_TYPE
#define SIZE_TYPE "unsigned short"

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "short"

#undef  WCHAR_TYPE
#define WCHAR_TYPE "unsigned short"

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE BITS_PER_WORD

#define MOVE_MAX 2

/* Storage */
#undef BITS_PER_UNIT
#define BITS_PER_UNIT 8
#define UNITS_PER_WORD 2

#define STRICT_ALIGNMENT 1
#define BIGGEST_ALIGNMENT 16
#define PARM_BOUNDARY 16
#define STACK_BOUNDARY 16

#define BYTES_BIG_ENDIAN 0
#define WORDS_BIG_ENDIAN 0

/* Assembly file structure */
#undef ASM_SPEC
#define ASM_SPEC "" // replace with command line options that should be passed to assembler

#define ASM_COMMENT_START ";"
#define ASM_APP_ON ""
#define ASM_APP_OFF ""

#define FILE_ASM_OP ""
#define TEXT_SECTION_ASM_OP ""
#define DATA_SECTION_ASM_OP ""

/* Stack and calling convention */
#define STACK_POINTER_REGNUM 1

#define FUNCTION_BOUNDARY 8
#define TRAMPOLINE_SIZE 0 // no exec stack, @KZhang?

#define CUMULATIVE_ARGS unsigned int

/* Adjust memory * immediate multiplication instruction which is variable length. */
#define ADJUST_INSN_LENGTH(insn, length) \
  if (GET_CODE(PATTERN(insn)) == MULT) {\
    if (GET_CODE(XEXP(PATTERN(insn), 1)) == CONST_INT) {\
      length = __builtin_popcount(INTVAL(XEXP(PATTERN(insn), 1))) * 2; \
    } else if (GET_CODE(XEXP(PATTERN(insn), 2)) == CONST_INT) {\
      length = __builtin_popcount(INTVAL(XEXP(PATTERN(insn), 2))) * 2; \
    }\
  }

/* Macro definitions when compiling for this target */
#define TARGET_CPU_CPP_BUILTINS() builtin_define_std("QFT");
