/* multiterm.h generated by valac 0.11.6.38-0ec3, the Vala compiler, do not modify */


#ifndef __MULTITERM_H__
#define __MULTITERM_H__

#include <glib.h>
#include <geanyplugin.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>
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

#define MULTI_TERM_TYPE_SHELL_CONFIG (multi_term_shell_config_get_type ())

#define MULTI_TERM_TYPE_CONFIG (multi_term_config_get_type ())
#define MULTI_TERM_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_CONFIG, MultiTermConfig))
#define MULTI_TERM_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MULTI_TERM_TYPE_CONFIG, MultiTermConfigClass))
#define MULTI_TERM_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_CONFIG))
#define MULTI_TERM_IS_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MULTI_TERM_TYPE_CONFIG))
#define MULTI_TERM_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MULTI_TERM_TYPE_CONFIG, MultiTermConfigClass))

typedef struct _MultiTermConfig MultiTermConfig;
typedef struct _MultiTermConfigClass MultiTermConfigClass;
typedef struct _MultiTermShellConfig MultiTermShellConfig;
typedef struct _MultiTermConfigPrivate MultiTermConfigPrivate;

#define MULTI_TERM_TYPE_TAB_LABEL (multi_term_tab_label_get_type ())
#define MULTI_TERM_TAB_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabel))
#define MULTI_TERM_TAB_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabelClass))
#define MULTI_TERM_IS_TAB_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_TAB_LABEL))
#define MULTI_TERM_IS_TAB_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MULTI_TERM_TYPE_TAB_LABEL))
#define MULTI_TERM_TAB_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MULTI_TERM_TYPE_TAB_LABEL, MultiTermTabLabelClass))

typedef struct _MultiTermTabLabel MultiTermTabLabel;
typedef struct _MultiTermTabLabelClass MultiTermTabLabelClass;
typedef struct _MultiTermTabLabelPrivate MultiTermTabLabelPrivate;

#define MULTI_TERM_TYPE_ITERMINAL (multi_term_iterminal_get_type ())
#define MULTI_TERM_ITERMINAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MULTI_TERM_TYPE_ITERMINAL, MultiTermITerminal))
#define MULTI_TERM_IS_ITERMINAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MULTI_TERM_TYPE_ITERMINAL))
#define MULTI_TERM_ITERMINAL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), MULTI_TERM_TYPE_ITERMINAL, MultiTermITerminalIface))

typedef struct _MultiTermITerminal MultiTermITerminal;
typedef struct _MultiTermITerminalIface MultiTermITerminalIface;

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

struct _MultiTermShellConfig {
	gchar* section;
	gchar* name;
	gchar* command;
	gboolean track_title;
	MultiTermConfig* cfg;
};

struct _MultiTermConfig {
	GTypeInstance parent_instance;
	volatile int ref_count;
	MultiTermConfigPrivate * priv;
};

struct _MultiTermConfigClass {
	GTypeClass parent_class;
	void (*finalize) (MultiTermConfig *self);
};

struct _MultiTermTabLabel {
	GtkHBox parent_instance;
	MultiTermTabLabelPrivate * priv;
	GtkLabel* label;
};

struct _MultiTermTabLabelClass {
	GtkHBoxClass parent_class;
};

struct _MultiTermITerminalIface {
	GTypeInterface parent_iface;
	void (*run_command) (MultiTermITerminal* self, const gchar* command);
	const gchar* (*get_tab_label_text) (MultiTermITerminal* self);
	void (*set_tab_label_text) (MultiTermITerminal* self, const gchar* value);
	void (*set_background_color) (MultiTermITerminal* self, const gchar* value);
	void (*set_foreground_color) (MultiTermITerminal* self, const gchar* value);
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
GType multi_term_shell_config_get_type (void) G_GNUC_CONST;
gpointer multi_term_config_ref (gpointer instance);
void multi_term_config_unref (gpointer instance);
GParamSpec* multi_term_param_spec_config (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void multi_term_value_set_config (GValue* value, gpointer v_object);
void multi_term_value_take_config (GValue* value, gpointer v_object);
gpointer multi_term_value_get_config (const GValue* value);
GType multi_term_config_get_type (void) G_GNUC_CONST;
MultiTermShellConfig* multi_term_shell_config_dup (const MultiTermShellConfig* self);
void multi_term_shell_config_free (MultiTermShellConfig* self);
void multi_term_shell_config_copy (const MultiTermShellConfig* self, MultiTermShellConfig* dest);
void multi_term_shell_config_destroy (MultiTermShellConfig* self);
MultiTermConfig* multi_term_config_new (const gchar* filename);
MultiTermConfig* multi_term_config_construct (GType object_type, const gchar* filename);
void multi_term_config_store (MultiTermConfig* self);
gchar* multi_term_config_get_background_color (MultiTermConfig* self);
void multi_term_config_set_background_color (MultiTermConfig* self, const gchar* value);
gchar* multi_term_config_get_foreground_color (MultiTermConfig* self);
void multi_term_config_set_foreground_color (MultiTermConfig* self, const gchar* value);
gchar* multi_term_config_get_font (MultiTermConfig* self);
void multi_term_config_set_font (MultiTermConfig* self, const gchar* value);
const gchar* multi_term_config_get_filename (MultiTermConfig* self);
GList* multi_term_config_get_shell_configs (MultiTermConfig* self);
GType multi_term_tab_label_get_type (void) G_GNUC_CONST;
MultiTermTabLabel* multi_term_tab_label_new (const gchar* text);
MultiTermTabLabel* multi_term_tab_label_construct (GType object_type, const gchar* text);
const gchar* multi_term_tab_label_get_text (MultiTermTabLabel* self);
void multi_term_tab_label_set_text (MultiTermTabLabel* self, const gchar* value);
GtkButton* multi_term_tab_label_get_button (MultiTermTabLabel* self);
GType multi_term_iterminal_get_type (void) G_GNUC_CONST;
void multi_term_iterminal_run_command (MultiTermITerminal* self, const gchar* command);
const gchar* multi_term_iterminal_get_tab_label_text (MultiTermITerminal* self);
void multi_term_iterminal_set_tab_label_text (MultiTermITerminal* self, const gchar* value);
void multi_term_iterminal_set_background_color (MultiTermITerminal* self, const gchar* value);
void multi_term_iterminal_set_foreground_color (MultiTermITerminal* self, const gchar* value);
GType multi_term_terminal_get_type (void) G_GNUC_CONST;
void multi_term_terminal_run_command (MultiTermTerminal* self, const gchar* command);
void multi_term_terminal_send_command (MultiTermTerminal* self, const gchar* command);
MultiTermTerminal* multi_term_terminal_new (MultiTermShellConfig* sh);
MultiTermTerminal* multi_term_terminal_construct (GType object_type, MultiTermShellConfig* sh);
const gchar* multi_term_terminal_get_tab_label_text (MultiTermTerminal* self);
void multi_term_terminal_set_tab_label_text (MultiTermTerminal* self, const gchar* value);
void multi_term_terminal_set_background_color (MultiTermTerminal* self, const gchar* value);
void multi_term_terminal_set_foreground_color (MultiTermTerminal* self, const gchar* value);
void multi_term_notebook_add_terminal (MultiTermNotebook* self, MultiTermShellConfig* cfg);
void multi_term_notebook_remove_terminal (MultiTermNotebook* self, gint tab_num);
MultiTermNotebook* multi_term_notebook_new (const gchar* config_filename);
MultiTermNotebook* multi_term_notebook_construct (GType object_type, const gchar* config_filename);


G_END_DECLS

#endif
