## Process this file with automake to produce a Makefile.in.

ACLOCAL_AMFLAGS = -Im4

EXTRA_DIST = README.md

SUBDIRS = libcppunitx test doc

dist-hook:
	cd $(distdir) && \
	find . -type f ! -name \*SUMS -exec shasum -a 256 {} \; > SHA256SUMS
