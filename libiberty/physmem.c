/* Calculate the size of physical memory.
   Copyright 2000, 2001, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

/* Written by Paul Eggert and Jim Meyering.  */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#if HAVE_UNISTD_H
# include <unistd.h>
#endif

#if HAVE_SYS_PSTAT_H
# include <sys/pstat.h>
#endif

#if HAVE_SYS_SYSMP_H
#include <sys/sysmp.h>
#endif

#include "libiberty.h"

/* Return the total amount of physical memory.  */
double
physmem_total ()
{
#if defined _SC_PHYS_PAGES && defined _SC_PAGESIZE
  {
    double pages = sysconf (_SC_PHYS_PAGES);
    double pagesize = sysconf (_SC_PAGESIZE);
    if (0 <= pages && 0 <= pagesize)
      return pages * pagesize;
  }
#endif

#if HAVE_PSTAT_GETSTATIC
  { /* This works on hpux11.  */
    struct pst_static pss;
    if (0 <= pstat_getstatic (&pss, sizeof pss, 1, 0))
      {
	double pages = pss.physical_memory;
	double pagesize = pss.page_size;
	if (0 <= pages && 0 <= pagesize)
	  return pages * pagesize;
      }
  }
#endif

#if HAVE_SYSMP && defined MP_SAGET && defined MPSA_RMINFO && defined _SC_PAGESIZE
  { /* This works on irix6. */
    struct rminfo realmem;
    if (sysmp(MP_SAGET, MPSA_RMINFO, &realmem, sizeof(realmem)) == 0)
      {
	double pagesize = sysconf (_SC_PAGESIZE);
	double pages = realmem.physmem;
	if (0 <= pages && 0 <= pagesize)
          return pages * pagesize;
      }
  }
#endif

  /* Return 0 if we can't determine the value.  */
  return 0;
}

/* Return the amount of physical memory available.  */
double
physmem_available ()
{
#if defined _SC_AVPHYS_PAGES && defined _SC_PAGESIZE
  {
    double pages = sysconf (_SC_AVPHYS_PAGES);
    double pagesize = sysconf (_SC_PAGESIZE);
    if (0 <= pages && 0 <= pagesize)
      return pages * pagesize;
  }
#endif

#if HAVE_PSTAT_GETSTATIC && HAVE_PSTAT_GETDYNAMIC
  { /* This works on hpux11.  */
    struct pst_static pss;
    struct pst_dynamic psd;
    if (0 <= pstat_getstatic (&pss, sizeof pss, 1, 0)
	&& 0 <= pstat_getdynamic (&psd, sizeof psd, 1, 0))
      {
	double pages = psd.psd_free;
	double pagesize = pss.page_size;
	if (0 <= pages && 0 <= pagesize)
	  return pages * pagesize;
      }
  }
#endif

#if HAVE_SYSMP && defined MP_SAGET && defined MPSA_RMINFO && defined _SC_PAGESIZE
  { /* This works on irix6. */
    struct rminfo realmem;
    if (sysmp(MP_SAGET, MPSA_RMINFO, &realmem, sizeof(realmem)) == 0)
      {
	double pagesize = sysconf (_SC_PAGESIZE);
	double pages = realmem.availrmem;
	if (0 <= pages && 0 <= pagesize)
          return pages * pagesize;
      }
  }
#endif

  /* Guess 25% of physical memory.  */
  return physmem_total () / 4;
}


#if DEBUG

# include <stdio.h>
# include <stdlib.h>

int
main ()
{
  printf ("%12.f %12.f\n", physmem_total (), physmem_available ());
  exit (0);
}

#endif /* DEBUG */

/*
Local Variables:
compile-command: "gcc -DDEBUG -DHAVE_CONFIG_H -I.. -g -O -Wall -W physmem.c"
End:
*/
