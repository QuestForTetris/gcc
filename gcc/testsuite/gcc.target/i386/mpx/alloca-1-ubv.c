/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-fmpx" } */
/* { dg-additional-options "-L/opt/intel/lib -lpl-runtime64" } */

#define XFAIL

#include "mpx-check.h"

int rd (int *p, int i)
{
  int res = p[i];
  printf ("%d\n", res);
  return res;
}

int mpx_test (int argc, const char **argv)
{
  int *buf = (int *)alloca (100 * sizeof(int));

  rd (buf, 100);

  return 0;
}
