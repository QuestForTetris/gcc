/* Test the `vdup_nf32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vdup_nf32 (void)
{
  float32x2_t out_float32x2_t;
  float32_t arg0_float32_t;

  out_float32x2_t = vdup_n_f32 (arg0_float32_t);
}

/* { dg-final { scan-assembler "vdup\.32\[ 	\]+\[dD\]\[0-9\]+, \[rR\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
