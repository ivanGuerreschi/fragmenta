/* main.c

   Copyright (C) 2023 Ivan Guerreschi.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "info.h"
#include <libguile.h>

static SCM
print_version (void)
{
  SCM result = scm_from_utf8_string (version ());
  return result;
}

static SCM
print_package (void)
{
  SCM result = scm_from_utf8_string (package ());
  return result;
}

static void
inner_main (void *closure, int argc, char **argv)
{
  scm_c_define_gsubr ("version", 0, 0, 0, print_version);
  scm_c_define_gsubr ("package", 0, 0, 0, print_package);
  
  scm_shell(argc, argv);
}

int
main (int argc, char **argv)
{
  scm_boot_guile (argc, argv, inner_main, 0);
  return 0;
}
