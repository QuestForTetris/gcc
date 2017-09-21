/* Target machine header for the QFT computer. -quartata */
#pragma once

/* Define a comparison code "register" (address 5) so that comparison operators aren't hell */
enum reg_class { NO_REGS, CC_REGS, LIM_REG_CLASSES };

#define CC_ADDRESS "5"

#define REGISTER_NAMES {CC_ADDRESS}
#define FIXED_REGISTERS {1}
#define FIRST_PSEUDO_REGISTER 1
#define N_REG_CLASSES (int) LIM_REG_CLASSES

#define HARD_REGNO_MODE_OK(REGNO, MODE) 0
#define REGNO_REG_CLASS(REGNO) (REGNO ? NO_REGS : CC_REGS)

/* Type info, change me */
#undef BITS_PER_UNIT
#define BITS_PER_UNIT 8
#define UNITS_PER_WORD 2

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
#define MOVE_MAX 2
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
