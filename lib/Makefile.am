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

AM_CFLAGS = -I $(top_srcdir)/lib \
	-Wall -Wextra -Wformat=2 -Wshadow -Wjump-misses-init -Wlogical-op\
	-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
	-Wredundant-decls -Wnested-externs -Wmissing-include-dirs

noinst_LIBRARIES = libfragmenta.a
noinst_HEADERS = info.h fragment.h

libfragmenta_a_SOURCES = $(libfragmenta_a_HEADERS) info.c fragment.c
