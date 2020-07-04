## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -D_LIBCPPUNITX

pkgconfigdir = $(libdir)/pkgconfig

EXTRA_DIST = cppunitx.pc.in

lib_LTLIBRARIES = libcppunitx.la

pkgconfig_DATA = cppunitx.pc

nobase_include_HEADERS = \
cppunitx/exception \
cppunitx/assertion \
cppunitx/framework \
cppunitx/driver \
cppunitx/module \
bits/cppunitx.h \
bits/cppunitx/exception.h \
bits/cppunitx/assert.h \
bits/cppunitx/test.h \
bits/cppunitx/registry.h \
bits/cppunitx/suite.h \
bits/cppunitx/context.h \
bits/cppunitx/driver.h \
bits/cppunitx/module.h
noinst_HEADERS = \
module_loader.h

libcppunitx_la_LDFLAGS = -version-info 0:0:0
libcppunitx_la_SOURCES = \
exception.cpp \
assertion.cpp \
registry.cpp \
test.cpp \
context.cpp \
driver.cpp \
module_loader.cpp

CLEANFILES = $(pkgconfig_DATA)

cppunitx.pc: $(srcdir)/cppunitx.pc.in $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status --file=$(subdir)/$@

installcheck-local::
	if test -n '$(PKG_CONFIG)'; then \
	    export PKG_CONFIG_PATH=$(pkgconfigdir); \
	    $(PKG_CONFIG) --exists --exact-version=$(VERSION) cppunitx; \
	fi
