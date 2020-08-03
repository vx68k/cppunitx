## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx \
-I$(top_builddir)/libgnu -I$(top_srcdir)/libgnu

bin_PROGRAMS = cppunitx

cppunitx_SOURCES = cppunitx.cpp
cppunitx_LDADD = \
$(top_builddir)/libcppunitx/libcppunitx.la \
$(top_builddir)/libgnu/libgnu.a

installcheck-local::
	$(bindir)/cppunitx --version
	$(bindir)/cppunitx --help
