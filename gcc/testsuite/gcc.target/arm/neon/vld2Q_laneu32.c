/* Test the `vld2Q_laneu32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vld2Q_laneu32 (void)
{
  uint32x4x2_t out_uint32x4x2_t;
  uint32x4x2_t arg1_uint32x4x2_t;

  out_uint32x4x2_t = vld2q_lane_u32 (0, arg1_uint32x4x2_t, 1);
}

/* { dg-final { scan-assembler "vld2\.32\[ 	\]+\\\{((\[dD\]\[0-9\]+\\\[\[0-9\]+\\\]-\[dD\]\[0-9\]+\\\[\[0-9\]+\\\])|(\[dD\]\[0-9\]+\\\[\[0-9\]+\\\], \[dD\]\[0-9\]+\\\[\[0-9\]+\\\]))\\\}, \\\[\[rR\]\[0-9\]+\\\]!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
