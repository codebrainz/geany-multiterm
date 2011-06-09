/* shell.c generated by valac 0.11.6.38-0ec3, the Vala compiler
 * generated from shell.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include "multiterm.h"
#include <vte/vte.h>



static gpointer multi_term_shell_terminal_parent_class = NULL;

enum  {
	MULTI_TERM_SHELL_TERMINAL_DUMMY_PROPERTY
};
static void multi_term_shell_terminal_real_init_shell (MultiTermTerminal* base);


static void multi_term_shell_terminal_real_init_shell (MultiTermTerminal* base) {
	MultiTermShellTerminal * self;
	self = (MultiTermShellTerminal*) base;
	vte_terminal_fork_command (((MultiTermTerminal*) self)->terminal, NULL, NULL, NULL, NULL, TRUE, TRUE, TRUE);
}


MultiTermShellTerminal* multi_term_shell_terminal_construct (GType object_type) {
	MultiTermShellTerminal * self = NULL;
	self = (MultiTermShellTerminal*) multi_term_terminal_construct (object_type);
	return self;
}


MultiTermShellTerminal* multi_term_shell_terminal_new (void) {
	return multi_term_shell_terminal_construct (MULTI_TERM_TYPE_SHELL_TERMINAL);
}


static void multi_term_shell_terminal_class_init (MultiTermShellTerminalClass * klass) {
	multi_term_shell_terminal_parent_class = g_type_class_peek_parent (klass);
	MULTI_TERM_TERMINAL_CLASS (klass)->init_shell = multi_term_shell_terminal_real_init_shell;
}


static void multi_term_shell_terminal_instance_init (MultiTermShellTerminal * self) {
}


GType multi_term_shell_terminal_get_type (void) {
	static volatile gsize multi_term_shell_terminal_type_id__volatile = 0;
	if (g_once_init_enter (&multi_term_shell_terminal_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MultiTermShellTerminalClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) multi_term_shell_terminal_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MultiTermShellTerminal), 0, (GInstanceInitFunc) multi_term_shell_terminal_instance_init, NULL };
		GType multi_term_shell_terminal_type_id;
		multi_term_shell_terminal_type_id = g_type_register_static (MULTI_TERM_TYPE_TERMINAL, "MultiTermShellTerminal", &g_define_type_info, 0);
		g_once_init_leave (&multi_term_shell_terminal_type_id__volatile, multi_term_shell_terminal_type_id);
	}
	return multi_term_shell_terminal_type_id__volatile;
}



