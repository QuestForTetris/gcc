/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-fmpx" } */
/* { dg-additional-options "-L/opt/intel/lib -lpl-runtime64" } */

#define XFAIL

#include "mpx-check.h"

int *buf1[100];
int buf2[100];

void wr (int i)
{
  buf1[i] = buf2;
}

int rd(int i, int j)
{
  int res = buf1[i][j];
  printf("%d\n", res);
  return res;
}

int mpx_test (int argc, const char **argv)
{
  wr(10);
  rd(10, 100);

  return 0;
}
