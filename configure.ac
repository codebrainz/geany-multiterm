AC_PREREQ([2.67])
AC_INIT([multiterm], [1.0], [mbrush@leftclick.ca])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall silent-rules])
AM_SILENT_RULES([yes])

LT_PREREQ([2.2.0])
LT_INIT
AC_PROG_CC
AM_PROG_VALAC([0.7.0])
AC_PROG_INSTALL

PKG_CHECK_MODULES([GTK], [gtk+-2.0])
PKG_CHECK_MODULES([GEANY], [geany])
PKG_CHECK_MODULES([VTE], [vte])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
