# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([CppUnitX], [1.0], [https://bitbucket.org/vx68k/cppunitx/issues/new],
[cppunitx], [https://www.vx68k.org/cppunitx])
AC_CONFIG_SRCDIR([libcppunitx/base.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
LT_PREREQ([2.4.6])
LT_INIT([dlopen])
AM_INIT_AUTOMAKE([foreign no-define])
AC_PROG_CC
AC_PROG_CXX
AH_CHECK_LIB([ltdl])dnl
AC_CHECK_LIB([ltdl], [lt_dlopen], [AC_DEFINE([HAVE_LIBLTDL])
  LIBLTDL=-lltdl], [LIBLTDL=])
AC_SUBST([LIBLTDL])dnl
AC_CHECK_HEADERS([ltdl.h])
AC_SUBST([LTLDFLAGS])dnl
AC_CONFIG_FILES([Makefile libcppunitx/Makefile examples/Makefile doc/Makefile])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
