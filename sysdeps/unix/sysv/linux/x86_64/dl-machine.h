/* Machine-dependent ELF dynamic relocation inline functions.
   Linux/x86-64 version.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifdef ENABLE_CET
# include <sysdeps/unix/sysv/linux/x86/dl-cet.h>
#endif
#ifdef __ILP32__
# include <sysdeps/x86_64/x32/dl-machine.h>
#else
# include <sysdeps/x86_64/dl-machine.h>
#endif