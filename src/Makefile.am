# Makefile.am
#
# Copyright (C) 2023 Ivan Guerreschi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

include $(top_srcdir)/flymake.mk

AM_CFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/lib \
	-Wall -Wextra -Wformat=2 -Wjump-misses-init -Wlogical-op -Wshadow \
	-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
	-Wredundant-decls -Wnested-externs -Wmissing-include-dirs

nobase_include_HEADERS =
bin_PROGRAMS = fragmenta
fragmenta_SOURCES = main.c
fragmenta_CFLAGS = @GUILE_CFLAGS@ -I $(top_srcdir)/lib
fragmenta_LDADD = @GUILE_LIBS@ $(top_builddir)/lib/libfragmenta.a

