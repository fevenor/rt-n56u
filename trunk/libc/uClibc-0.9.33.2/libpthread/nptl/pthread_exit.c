/* Copyright (C) 2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@redhat.com>, 2002.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <stdlib.h>
#include "pthreadP.h"


void
attribute_protected attribute_noreturn
__pthread_exit (void* value)
{
  THREAD_SETMEM (THREAD_SELF, result, value);

  __do_cancel ();
}
strong_alias (__pthread_exit, pthread_exit)

/*
 * After a thread terminates, __uClibc_main decrements __nptl_nthreads
 * defined in pthread_create.c.
 */
PTHREAD_STATIC_FN_REQUIRE (pthread_create)
