/* { dg-do run { target i?86-*-* x86_64-*-* } } */
/* { dg-additional-sources pr68661-2b.c } */

extern void (*bar[]) (int, int, int, int, int, int, int, int, int)
   __attribute__ ((no_caller_saved_registers));

void
foo (void)
{
  bar[0] (0, 1, 2, 3, 4, 5, 6, 7, 8);
}

void
bad (void)
{
  __builtin_abort ();
}
