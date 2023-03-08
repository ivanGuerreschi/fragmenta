/* fragment.c

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

#include <stdio.h>
#include <string.h>
#include "fragment.h"

static fragment_type fragment[] = {
  {"c", "include", "#include <stdio.h>"},
  {"c", "puts", "puts (\"Hello, World!\");"},
  {"c", "printf", "printf (\"%s\\n\", \"Hello, World!\");"},
  {"go", "printf", "fmt.Printf(\"%s\\n\", \"Hello, World!\")"},
};

size_t
length (void)
{
  return sizeof (fragment) / sizeof (fragment[0]);
}

fragment_type *
all_fragments (void)
{
  return fragment;
}

const char *
search_fragment_for_name (const char *language, const char *key)
{
  size_t length_fragments = length ();
  char *searched_snippet;

  for (size_t i = 0; i < length_fragments; i++)
    {
      if (strcmp (fragment[i].language, language) == 0)
	{
	  if (strcmp (fragment[i].name, key) == 0)
	    {
	      searched_snippet = malloc (strlen (fragment[i].snippet) + 1);
	      strcpy (searched_snippet, fragment[i].snippet);
	      break;
	    }
	  else
	    {
	      const char *message = "There is no such programming language";
	      searched_snippet = malloc (strlen (message) + 1);
	      strcpy (searched_snippet, message);
	    }
	}
      else
	{
	  const char *message = "Your search has returned no results";
	  searched_snippet = malloc (strlen (message) + 1);
	  strcpy (searched_snippet, message);
	}
    }

  return searched_snippet;
}
