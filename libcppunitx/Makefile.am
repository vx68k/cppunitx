## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -D_CPPUNITX_IMPLEMENTATION \
$(LTDLINCL)

lib_LTLIBRARIES = libcppunitx.la

nobase_include_HEADERS = \
cppunitx/exception \
cppunitx/assertion \
cppunitx/framework \
cppunitx/driver \
cppunitx/module \
bits/cppunitx.h \
bits/cppunitx/exception.h \
bits/cppunitx/assert.h \
bits/cppunitx/registry.h \
bits/cppunitx/test.h \
bits/cppunitx/driver.h \
bits/cppunitx/module.h
noinst_HEADERS = ltdl_utility.h

libcppunitx_la_LDFLAGS = -version-info 0:0:0
libcppunitx_la_LIBADD = $(LIBLTDL)
libcppunitx_la_SOURCES = \
exception.cpp \
assertion.cpp \
registry.cpp \
test.cpp \
context.cpp \
driver.cpp
