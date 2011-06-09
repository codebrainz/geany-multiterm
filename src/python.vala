using Gtk;
using Vte;

namespace MultiTerm
{
	public class PythonTerminal : Terminal
	{
		public override void init_shell()
		{
			string? py = GLib.Environment.find_program_in_path("bpython");

			if (py == null)
			{
				py = GLib.Environment.find_program_in_path("python");
				if (py == null)
				{
					terminal.fork_command(null, null, null, null, true, true, true);
					run_command("echo \"No Python interpreter was located.\"");
				}
				else
					terminal.fork_command(py, null, null, null, true, true, true);
			}
			else
				terminal.fork_command("%s".printf(py), null, null, null, true, true, true);

		}
	}
}