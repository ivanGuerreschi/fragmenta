.PHONY: check-syntax

check-syntax:
	$(CC) -I/usr/include/guile/3.0 -I $(top_srcdir)/lib -I $(top_srcdir)/src -Wall -Werror -o /dev/null -S ${CHK_SOURCES} || true


