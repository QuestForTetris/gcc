/* Typedefs for polynomial integers used in GCC.
   Copyright (C) 2016-2017 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef HAVE_POLY_INT_TYPES_H
#define HAVE_POLY_INT_TYPES_H

typedef poly_int_pod<NUM_POLY_INT_COEFFS, unsigned short> poly_uint16_pod;
typedef poly_int_pod<NUM_POLY_INT_COEFFS, HOST_WIDE_INT> poly_int64_pod;
typedef poly_int_pod<NUM_POLY_INT_COEFFS,
		     unsigned HOST_WIDE_INT> poly_uint64_pod;
typedef poly_int_pod<NUM_POLY_INT_COEFFS, offset_int> poly_offset_int_pod;
typedef poly_int_pod<NUM_POLY_INT_COEFFS, wide_int> poly_wide_int_pod;
typedef poly_int_pod<NUM_POLY_INT_COEFFS, widest_int> poly_widest_int_pod;

typedef poly_int<NUM_POLY_INT_COEFFS, unsigned short> poly_uint16;
typedef poly_int<NUM_POLY_INT_COEFFS, HOST_WIDE_INT> poly_int64;
typedef poly_int<NUM_POLY_INT_COEFFS, unsigned HOST_WIDE_INT> poly_uint64;
typedef poly_int<NUM_POLY_INT_COEFFS, offset_int> poly_offset_int;
typedef poly_int<NUM_POLY_INT_COEFFS, wide_int> poly_wide_int;
typedef poly_int<NUM_POLY_INT_COEFFS, widest_int> poly_widest_int;

/* Divide bit quantity X by BITS_PER_UNIT and round down (towards -Inf).
   If X is a bit size, this gives the number of whole bytes spanned by X.

   This is safe because non-constant mode sizes must be a whole number
   of bytes in size.  */
#define bits_to_bytes_round_down(X) force_align_down_and_div (X, BITS_PER_UNIT)

/* Divide bit quantity X by BITS_PER_UNIT and round up (towards +Inf).
   If X is a bit size, this gives the number of whole or partial bytes
   spanned by X.

   This is safe because non-constant mode sizes must be a whole number
   of bytes in size.  */
#define bits_to_bytes_round_up(X) force_align_up_and_div (X, BITS_PER_UNIT)

#endif
