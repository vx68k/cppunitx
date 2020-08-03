# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([C++UnitX], [1-alpha.5],
[https://bitbucket.org/kazssym/cppunitx/issues/new], [cppunitx],
[https://www.vx68k.org/cppunitx])
AC_CONFIG_SRCDIR([libcppunitx/registry.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign no-define subdir-objects tar-ustar])
# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
gl_EARLY
# Checks for libraries.
AC_SEARCH_LIBS([dlopen], [dl])
# Checks for header files.
AC_CHECK_HEADERS([dlfcn.h])
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.
AC_CHECK_FUNCS([dlopen])
# Checks for other features.
LT_PREREQ([2.4.6])
LT_INIT
gl_INIT
# Configuration actions.
AC_CONFIG_FILES([Makefile cppunitx/Makefile libcppunitx/Makefile
libgnu/Makefile test/Makefile doc/Makefile])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
