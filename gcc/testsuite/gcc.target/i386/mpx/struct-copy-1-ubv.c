/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-fmpx" } */
/* { dg-additional-options "-L/opt/intel/lib -lpl-runtime64" } */

#define XFAIL

#include "mpx-check.h"

int buf1[100];
int buf2[200];

struct s1 {
  int a;
  int *p[2];
} s1;

struct s2 {
  int a;
  struct s1 b[2];
} s2;

struct s2 s = { 1, { {1, { buf1, buf2 }}, {2, { buf2, buf1} } } };

int mpx_test (int argc, const char *argv[])
{
  struct s2 ss = s;

  printf ("%d\n", ss.b[0].p[0][100]);

  return 0;
}
