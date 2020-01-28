## Process this file with automake to produce a Makefile.in.

lib_LTLIBRARIES = libcppunitx.la

nobase_include_HEADERS = cppunitx/framework cppunitx/assert cppunitx/driver \
cppunitx/module \
bits/cppunitx.h bits/cppunitx/registry.h bits/cppunitx/test.h \
bits/cppunitx/assert.h bits/cppunitx/driver.h bits/cppunitx/module.h

noinst_HEADERS = ltdl_utility.h

libcppunitx_la_LDFLAGS = -version-info 0:0:0 $(LTLDFLAGS)
libcppunitx_la_SOURCES = registry.cpp test.cpp context.cpp assert.cpp \
driver.cpp
