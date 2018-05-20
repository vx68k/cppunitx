## Process this file with automake to produce a Makefile.in.

AM_CPPFLAGS = -I$(top_builddir)/libcppunitx -I$(top_srcdir)/libcppunitx

check_LTLIBRARIES = selftest.la
check_PROGRAMS = run

TESTS = $(check_LTLIBRARIES)
# All tests are expeced to fail for now.
XFAIL_TESTS = $(TESTS)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = ./run

# A '-rpath' option is required to produce a loadable module.
selftest_la_LDFLAGS = -rpath $(libdir) -no-undefined -module -avoid-version
selftest_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la
selftest_la_SOURCES = selftest.cpp

run_SOURCES = run.cpp
run_LDADD = -dlpreopen selftest.la $(top_builddir)/libcppunitx/libcppunitx.la

$(top_builddir)/libcppunitx/libcppunitx.la:
	cd $(top_builddir)/libcppunitx && $(MAKE) $(AM_MAKEFLAGS) libcppunitx.la
