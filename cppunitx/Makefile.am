## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx \
-I$(top_builddir)/libgnu -I$(top_srcdir)/libgnu

bin_PROGRAMS = cppunitx

cppunitx_SOURCES = cppunitx.cpp
cppunitx_LDADD = -L$(top_builddir)/libcppunitx -lcppunitx \
-L$(top_builddir)/libgnu -lgnu

installcheck-local::
	$(bindir)/cppunitx --version
	$(bindir)/cppunitx --help
