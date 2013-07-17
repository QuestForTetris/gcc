/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-fmpx" } */
/* { dg-additional-options "-L/opt/intel/lib -lpl-runtime64" } */

#define XFAIL

#include "mpx-check.h"

struct s1 {
  int *p[2];
} s1;

int rd (struct s1 s, int i)
{
  int res = s.p[1][i];
  printf ("%d\n", res);
  return res;
}

int buf[100];
int buf1[100];

int mpx_test (int argc, const char **argv)
{
  struct s1 s = { {buf, buf1} };

  rd (s, -1);

  return 0;
}
