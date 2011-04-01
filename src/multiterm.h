/* multiterm.h generated by valac 0.11.6.38-0ec3, the Vala compiler, do not modify */


#ifndef __MULTITERM_H__
#define __MULTITERM_H__

#include <glib.h>
#include <geanyplugin.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <vte/vte.h>

G_BEGIN_DECLS


#define MULTI_TERM_TYPE_NOTEBOOK (multi_term_notebook_get_type ())
#define MULTI_TERM_NOTEBOOK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_NOTEBOOK, MultiTermNotebook))
#define MULTI_TERM_NOTEBOOK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MULTI_TERM_TYPE_NOTEBOOK, MultiTermNotebookClass))
#define MULTI_TERM_IS_NOTEBOOK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_NOTEBOOK))
#define MULTI_TERM_IS_NOTEBOOK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MULTI_TERM_TYPE_NOTEBOOK))
#define MULTI_TERM_NOTEBOOK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MULTI_TERM_TYPE_NOTEBOOK, MultiTermNotebookClass))

typedef struct _MultiTermNotebook MultiTermNotebook;
typedef struct _MultiTermNotebookClass MultiTermNotebookClass;

#define MULTI_TERM_TYPE_TAB_LABEL (multi_term_tab_label_get_type ())
#define MULTI_TERM_TAB_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabel))
#define MULTI_TERM_TAB_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabelClass))
#define MULTI_TERM_IS_TAB_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_TAB_LABEL))
#define MULTI_TERM_IS_TAB_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MULTI_TERM_TYPE_TAB_LABEL))
#define MULTI_TERM_TAB_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabelClass))

typedef struct _MultiTermTabLabel MultiTermTabLabel;
typedef struct _MultiTermTabLabelClass MultiTermTabLabelClass;
typedef struct _MultiTermTabLabelPrivate MultiTermTabLabelPrivate;

#define MULTI_TERM_TYPE_TERMINAL (multi_term_terminal_get_type ())
#define MULTI_TERM_TERMINAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_TERMINAL, MultiTermTerminal))
#define MULTI_TERM_TERMINAL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MULTI_TERM_TYPE_TERMINAL, MultiTermTerminalClass))
#define MULTI_TERM_IS_TERMINAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_TERMINAL))
#define MULTI_TERM_IS_TERMINAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MULTI_TERM_TYPE_TERMINAL))
#define MULTI_TERM_TERMINAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MULTI_TERM_TYPE_TERMINAL, MultiTermTerminalClass))

typedef struct _MultiTermTerminal MultiTermTerminal;
typedef struct _MultiTermTerminalClass MultiTermTerminalClass;
typedef struct _MultiTermTerminalPrivate MultiTermTerminalPrivate;
typedef struct _MultiTermNotebookPrivate MultiTermNotebookPrivate;

struct _MultiTermTabLabel {
	GtkHBox parent_instance;
	MultiTermTabLabelPrivate * priv;
	GtkLabel* label;
};

struct _MultiTermTabLabelClass {
	GtkHBoxClass parent_class;
};

struct _MultiTermTerminal {
	GtkFrame parent_instance;
	MultiTermTerminalPrivate * priv;
	VteTerminal* terminal;
};

struct _MultiTermTerminalClass {
	GtkFrameClass parent_class;
};

struct _MultiTermNotebook {
	GtkNotebook parent_instance;
	MultiTermNotebookPrivate * priv;
};

struct _MultiTermNotebookClass {
	GtkNotebookClass parent_class;
};


extern GeanyPlugin* geany_plugin;
extern GeanyData* geany_data;
extern GeanyFunctions* geany_functions;
GType multi_term_notebook_get_type (void) G_GNUC_CONST;
extern MultiTermNotebook* nb;
gint plugin_version_check (gint abi_version);
void plugin_set_info (PluginInfo* info);
void plugin_init (GeanyData* data);
void plugin_cleanup (void);
GType multi_term_tab_label_get_type (void) G_GNUC_CONST;
MultiTermTabLabel* multi_term_tab_label_new (const gchar* text);
MultiTermTabLabel* multi_term_tab_label_construct (GType object_type, const gchar* text);
const gchar* multi_term_tab_label_get_text (MultiTermTabLabel* self);
void multi_term_tab_label_set_text (MultiTermTabLabel* self, const gchar* value);
GtkButton* multi_term_tab_label_get_button (MultiTermTabLabel* self);
GType multi_term_terminal_get_type (void) G_GNUC_CONST;
MultiTermTerminal* multi_term_terminal_new (void);
MultiTermTerminal* multi_term_terminal_construct (GType object_type);
const gchar* multi_term_terminal_get_tab_label_text (MultiTermTerminal* self);
void multi_term_terminal_set_tab_label_text (MultiTermTerminal* self, const gchar* value);
void multi_term_terminal_set_background_color (MultiTermTerminal* self, const gchar* value);
void multi_term_terminal_set_foreground_color (MultiTermTerminal* self, const gchar* value);
void multi_term_notebook_add_terminal (MultiTermNotebook* self);
void multi_term_notebook_remove_terminal (MultiTermNotebook* self, gint tab_num);
MultiTermNotebook* multi_term_notebook_new (guint initial_terms);
MultiTermNotebook* multi_term_notebook_construct (GType object_type, guint initial_terms);


G_END_DECLS

#endif
