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
#include "fragment.h"
#include <libguile.h>
#include <stdio.h>
#include <string.h>

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

static SCM
print_license (void)
{
  SCM result = scm_from_utf8_string (license ());
  return result;
}

static SCM
print_bugreport (void)
{
  SCM result = scm_from_utf8_string (bugreport ());
  return result;
}

static SCM
print_all_fragments (void)
{
  char *fragments = all_fragments ();
  SCM result = scm_from_utf8_string (fragments);
  free (fragments);
  fragments = NULL;
  return result;
}

static SCM
print_search_fragment_for_name (SCM l, SCM k)
{
  const char *languge = scm_to_utf8_stringn (l, NULL);
  const char *key = scm_to_utf8_stringn (k, NULL);
  SCM result = scm_from_utf8_string (search_fragment_for_name (languge, key));
  return result;
}

static void
inner_main (void *closure, int argc, char **argv)
{
  scm_c_define_gsubr ("version", 0, 0, 0, print_version);
  scm_c_define_gsubr ("package", 0, 0, 0, print_package);
  scm_c_define_gsubr ("license", 0, 0, 0, print_license);
  scm_c_define_gsubr ("bugreport", 0, 0, 0, print_bugreport);
  scm_c_define_gsubr ("fragments", 0, 0, 0, print_all_fragments);
  scm_c_define_gsubr ("search_for_name", 2, 0, 0,
		      print_search_fragment_for_name);

  scm_shell (argc, argv);
}

int
main (int argc, char **argv)
{
  scm_boot_guile (argc, argv, inner_main, 0);

  return 0;
}
