/* search_fragment_for_name_test.c

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

#include "fragment.h"
#include <string.h>

int
main ()
{
  const char *search_puts = search_fragment_for_name ("c", "puts");
  const char *expected = "puts (\"Hello, World!\");";
  if (strcmp (search_puts, expected) == 0)
    return 0;
  else
    return 1;
}
