## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx -I$(top_builddir)/libcppunitx \
$(LTDLINCL)

check_PROGRAMS = runtest
check_LTLIBRARIES = \
test_assertion.la \
test_example.la

TESTS = $(check_LTLIBRARIES)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = ./runtest

runtest_LDFLAGS = -no-install
runtest_SOURCES = runtest.cpp
runtest_LDADD = \
-dlopen test_assertion.la \
-dlopen test_example.la \
$(top_builddir)/libcppunitx/libcppunitx.la $(LIBLTDL)

# A '-rpath' option is required to produce a loadable module.

test_assertion_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
test_assertion_la_SOURCES = assertion.cpp
test_assertion_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la

test_example_la_LDFLAGS = -module -avoid-version -rpath $(libdir)
test_example_la_SOURCES = example.cpp
test_example_la_LIBADD = $(top_builddir)/libcppunitx/libcppunitx.la
