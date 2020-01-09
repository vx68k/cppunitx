## Process this file with automake to produce a Makefile.in.

lib_LTLIBRARIES = libcppunitx.la

libcppunitx_la_LDFLAGS = -version-info 0:0:0 $(LTLDFLAGS)
libcppunitx_la_SOURCES = engine.cpp module_loader.cpp base.cpp

nobase_include_HEADERS = cppunitx/engine cppunitx/module cppunitx/test \
cppunitx/bits/engine.h \
cppunitx/bits/module.h cppunitx/bits/test_runner.h cppunitx/bits/base.h
