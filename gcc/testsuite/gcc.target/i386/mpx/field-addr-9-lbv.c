/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-fmpx" } */
/* { dg-additional-options "-L/opt/intel/lib -lpl-runtime64" } */
/* { dg-additional-options "-fmpx-narrow-to-innermost-array" } */

#define XFAIL

#include "mpx-check.h"

struct S {
  int first;
  int a[10];
  int b;
} S;

struct S1 {
  int a;
  struct S b[10];
  int c;
} S1;

struct S2 {
  int x;
  struct S1 a[10];
  struct S1 b;
} S2;

int foo (int *p, int i)
{
  int res = p[i];
  printf ("%d\n", res);
  return res;
}

struct S2 s1;
struct S2 *s2 = &s1;

int mpx_test (int argc, const char **argv)
{
  foo (&(s2->a[argc].b[5].a[0]), -1);

  return 0;
}
