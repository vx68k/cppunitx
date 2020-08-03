## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/libcppunitx

check_LTLIBRARIES = \
test_assertion.la \
test_example.la

TESTS = $(check_LTLIBRARIES)

TEST_EXTENSIONS = .la
LA_LOG_COMPILER = $(top_builddir)/cppunitx/cppunitx

# NOTE: A '-rpath' option is required to produce a loadable module even if not
# to be installed.

test_assertion_la_LDFLAGS = -module -no-undefined -shared -avoid-version -rpath $(libdir)
test_assertion_la_SOURCES = test_assertion.cpp
test_assertion_la_LIBADD = \
$(top_builddir)/libcppunitx/libcppunitx.la

test_example_la_LDFLAGS = -module -no-undefined -shared -avoid-version -rpath $(libdir)
test_example_la_SOURCES = test_example.cpp
test_example_la_LIBADD = \
$(top_builddir)/libcppunitx/libcppunitx.la
