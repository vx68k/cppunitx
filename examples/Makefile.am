## Process this file with automake to produce a Makefile.in.

AM_CPPFLAGS = -I$(top_builddir)/libcppunitx -I$(top_srcdir)/libcppunitx

check_LTLIBRARIES = selftest.la
check_PROGRAMS = run

TESTS = $(check_LTLIBRARIES)
# All tests are expected to fail for now.
XFAIL_TESTS = $(TESTS)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = ./run

# A '-rpath' option is required to produce a loadable module.
selftest_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
selftest_la_SOURCES = selftest.cpp
selftest_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la

run_SOURCES = run.cpp
run_LDADD = -dlopen selftest.la $(top_builddir)/libcppunitx/libcppunitx.la
