/* fragment.h

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

#ifndef FRAGMENT_H
#define FRAGMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

typedef struct
{
  char language[50];
  char name[50];
  char snippet[50];
} fragment_type;

size_t fragment_length (void);
char *all_fragments (void);
const char *search_fragment_for_name (const char *language,
				      const char *name);

#ifdef __cplusplus
}
#endif

#endif				/* FRAGMENT_H */
