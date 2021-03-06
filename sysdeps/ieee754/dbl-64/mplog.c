/*
 * IBM Accurate Mathematical Library
 * written by International Business Machines Corp.
 * Copyright (C) 2001-2018 Free Software Foundation, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */
/************************************************************************/
/*                                                                      */
/*     MODULE_NAME:mplog.c                                              */
/*                                                                      */
/*     FUNCTIONS:  mplog                                                */
/*                                                                      */
/*     FILES NEEDED: endian.h mpa.h  mplog.h                            */
/*                    mpexp.c                                           */
/*                                                                      */
/* Multi-Precision logarithm function subroutine (for precision p >= 4, */
/* 2**(-1024) < x < 2**1024) and x is outside of the interval           */
/* [1-2**(-54),1+2**(-54)]. Upon entry, x should be set to the          */
/* multi-precision value of the input and y should be set into a multi- */
/* precision value of an approximation of log(x) with relative error    */
/* bound of at most 2**(-52). The routine improves the accuracy of y.   */
/*                                                                      */
/************************************************************************/
#include "endian.h"
#include "mpa.h"

void
__mplog (mp_no *x, mp_no *y, int p)
{
  int i, m;
  static const int mp[33] =
    {
      0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    };
  mp_no mpt1, mpt2;

  /* Choose m.  */
  m = mp[p];

  /* Perform m newton iterations to solve for y: exp(y) - x = 0.  The
     iterations formula is:  y(n + 1) = y(n) + (x * exp(-y(n)) - 1).   */
  __cpy (y, &mpt1, p);
  for (i = 0; i < m; i++)
    {
      mpt1.d[0] = -mpt1.d[0];
      __mpexp (&mpt1, &mpt2, p);
      __mul (x, &mpt2, &mpt1, p);
      __sub (&mpt1, &__mpone, &mpt2, p);
      __add (y, &mpt2, &mpt1, p);
      __cpy (&mpt1, y, p);
    }
}
