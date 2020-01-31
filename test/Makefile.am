## Process this file with automake to produce a Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx -I$(top_builddir)/libcppunitx

check_PROGRAMS = runtest
check_LTLIBRARIES = assertion.la example.la

TESTS = $(check_LTLIBRARIES)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = ./runtest

runtest_LDFLAGS = -no-install
runtest_SOURCES = runtest.cpp
runtest_LDADD = \
-dlopen assertion.la \
-dlopen example.la \
$(top_builddir)/libcppunitx/libcppunitx.la $(LIBLTDL)

# A '-rpath' option is required to produce a loadable module.

assertion_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
assertion_la_SOURCES = assertion.cpp
assertion_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la

example_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
example_la_SOURCES = example.cpp
example_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la
