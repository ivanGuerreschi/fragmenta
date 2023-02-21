.PHONY: check-syntax

check-syntax:
	$(CC) -o /dev/null -S ${CHK_SOURCES} || true


