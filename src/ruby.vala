using Gtk;
using Vte;

namespace MultiTerm
{
	public class RubyTerminal : Terminal
	{
		public override void init_shell()
		{
			string? py = GLib.Environment.find_program_in_path("irb");

			if (py == null)
			{
				terminal.fork_command(null, null, null, null, true, true, true);
				run_command("echo \"No Ruby interpreter was located.\"");
			}
			else
				terminal.fork_command("%s".printf(py), null, null, null, true, true, true);

		}
	}
}
