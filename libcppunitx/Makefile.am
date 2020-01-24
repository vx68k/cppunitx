## Process this file with automake to produce a Makefile.in.

lib_LTLIBRARIES = libcppunitx.la

nobase_include_HEADERS = cppunitx/framework cppunitx/module cppunitx/driver \
bits/cppunitx.h bits/cppunitx/registry.h bits/cppunitx/test.h \
bits/cppunitx/module.h bits/cppunitx/driver.h \
cppunitx/bits/test_runner.h

noinst_HEADERS = ltdl_utility.h

libcppunitx_la_LDFLAGS = -version-info 0:0:0 $(LTLDFLAGS)
libcppunitx_la_SOURCES = registry.cpp test.cpp driver.cpp
