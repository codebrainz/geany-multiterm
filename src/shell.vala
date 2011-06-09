using Gtk;
using Vte;

namespace MultiTerm
{
	public class ShellTerminal : Terminal
	{
		public override void init_shell()
		{
			/* TODO: add wrapper for fork_command_full() since this
			 * function is deprecated */
			terminal.fork_command(null, null, null, null, true, true, true);
		}
	}
}