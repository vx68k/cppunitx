## Process this file with automake to produce a Makefile.in.

lib_LTLIBRARIES = libcppunitx.la

libcppunitx_la_LDFLAGS = -no-undefined -version-info 0:0:0 $(LTLDFLAGS)
libcppunitx_la_LIBADD = $(LIBLTDL)
libcppunitx_la_SOURCES = engine.cpp base.cpp

nobase_include_HEADERS = cppunitx/module cppunitx/test \
cppunitx/bits/module.h cppunitx/bits/test_runner.h cppunitx/bits/base.h
