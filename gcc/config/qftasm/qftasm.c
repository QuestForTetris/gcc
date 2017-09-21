/* Target machine for the QFT computer. -quartata */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "rtl.h"
#include "target.h"
#include "tree.h"

#include "target-def.h"

/* Helper functions for instructions in machine description. */
static const char *qft_cbranch(rtx[] operands, int which_alternative) {
  switch (GET_CODE(operands[0])) {
  case EQ: // equals
    switch (which_alternative) {
    case 0: // memory, memory
      return "SUB A%2 A%1 " CC_ADDRESS ";\n"
             "MNZ A" CC_ADDRESS " %l3 0;\n";
    
    }

  case NE: // not equals
    switch (which_alternative) {
    case 0: // memory, memory
      return "SUB A%2 A%1 " CC_ADDRESS ";\n"
             "MNZ A" CC_ADDRESS " %l3 0;\n";
    case 1: // memory, immediate
      if (INTVAL(operands[2]) == 0) {
        return "MNZ A%1 %l3 0;\n";
      } else {
        return "SUB A%2 %1 " CC_ADDRESS ";\n"
               "MNZ A" CC_ADDRESS " %l3 0;\n";
      }
    case 2: // immediate, memory
      if (INTVAL(operands[1]) == 0) {
        return "MNZ A%2 %l3 0;\n";
      } else {
        return "SUB %2 A%1 " CC_ADDRESS ";\n"
               "MNZ A" CC_ADDRESS " %l3 0;\n";
      }
    }

  case GT: // greater than
    switch (which_alternative) {
    case 0: // memory, memory
      return "SUB A%2 A%1 " CC_ADDRESS ";\n"
             "MLZ A" CC_ADDRESS " %l3 0;\n";
    case 1: // memory, immediate
      return "SUB %2 A%1 " CC_ADDRESS ";\n"
             "MLZ A" CC_ADDRESS " %l3 0;\n";
    case 2: // immediate, memory
      if (INTVAL(operands[1]) == 0) {
        return "MLZ A%1 %l3 0;\n";
      } else {
        return "SUB A%2 %1 " CC_ADDRESS ";\n"
               "MLZ A" CC_ADDRESS " %l3 0;\n";
      }
    }

  case LT: // less than
    switch (which_alternative) {
    case 0: // memory, memory
      return "SUB A%1 A%2 " CC_ADDRESS ";\n"
             "MLZ A" CC_ADDRESS " %l3 0;\n";
    case 1: // memory, immediate
      if (INTVAL(operands[2]) == 0) {
        return "MLZ A%1 %l3 0;\n";
      } else {
        return "SUB A%1 %2 " CC_ADDRESS ";\n"
               "MLZ A" CC_ADDRESS " %l3 0;\n";
      }
    case 2: // immediate, memory
      return "SUB %1 A%2 " CC_ADDRESS ";\n"
             "MLZ A" CC_ADDRESS " %l3 0;\n";
    }

  /* do these later, they're harder than they look */
  case GE: // greater than or equal
    assert(false);

  case LE: // less than or equal
    assert(false);
  }
}

static const char *qft_multiply(rtx[] operands, unsigned int which_alternative) {
  if (which_alternative == 0) { // memory, memory
    return ". ADD A0 2 3;\n"
           ". ADD A0 5 4;\n"
           ". MLZ -1 15 1;\n"
           ". SRA A%2 A1 2;\n"
           ". ANT 1 A2 2;\n"
           ". MNZ A2 A4 0;\n"
           ". SL A%1 A1 2;\n"
           ". ADD A2 A%0 %0;\n"
           ". MNZ A1 A3 0;\n"
           ". SUB A1 1 1;\n"
  } else { // memory and an immediate, either order
    char *output_buffer = (char*) malloc(561); // number of bytes * shift buffer size without terminator + terminator = 16 * 35 + 1
    char shift_buffer[36]; // length of format string + length of max short + terminator = 36
    int pos = 0;

    int immediate = INTVAL(operands[which_alternative ^ 3]);

    for (int i = 0; i < 16; i++) {
      if (immediate & (1 << i)) {
        int copied = sprintf(shift_buffer, ". SL A%%%d %d 1;\n. ADD A%%0 A1 %%0;\n", which_alternative, i);

        memcpy(output_buffer + pos, shift_buffer, copied);
        pos += copied;
      }
    }

    output_buffer[pos] = '\0';
    return (const char*) output_buffer;
  }
}

/* Target machine functions. */

/*static rtx qft_scalar_return(const_tree val, const_tree func, bool outgoing) {
  
}

#undef TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE qft_scalar_return*/

static bool qft_cc_regs(unsigned int *cc0, unsigned int *cc1) {
  *cc0 = 0;
  *cc1 = INVALID_REG_NUM;

  return true;
}

#undef	TARGET_FIXED_CONDITION_CODE_REGS
#define	TARGET_FIXED_CONDITION_CODE_REGS qft_cc_regs

struct gcc_target targetm = TARGET_INITIALIZER;