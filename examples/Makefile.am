## Process this file with automake to produce a Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx -I$(top_builddir)/libcppunitx

check_PROGRAMS = runtest
check_LTLIBRARIES = selftest.la

TESTS = $(check_LTLIBRARIES)
# All tests are expected to fail for now.
XFAIL_TESTS = $(TESTS)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = ./runtest

runtest_LDFLAGS = -no-install
runtest_SOURCES = runtest.cpp
runtest_LDADD = -dlopen selftest.la \
$(top_builddir)/libcppunitx/libcppunitx.la $(LIBLTDL)

# A '-rpath' option is required to produce a loadable module.
selftest_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
selftest_la_SOURCES = example.cpp
selftest_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la
