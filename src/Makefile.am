ACLOCAL_AMFLAGS = -I m4

VALAFLAGS = --vapidir vapi \
				--pkg gtk+-2.0 \
				--pkg geany \
				--pkg vte \
				-H multiterm.h --use-header

geanypluginsdir = $(libdir)/geany
geanyplugins_LTLIBRARIES = multiterm.la

multiterm_la_LDFLAGS	= 	-module -avoid-version -shared
multiterm_la_CPPFLAGS	= 	@GTK_CFLAGS@ @GEANY_CFLAGS@ @VTE_CFLAGS@
multiterm_la_LIBADD		= 	@GTK_LIBS@ @GEANY_LIBS@ @VTE_LIBS@
multiterm_la_SOURCES	=	plugin.vala \
							tab-label.vala \
							terminal.vala \
							notebook.vala
