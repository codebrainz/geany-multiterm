using Gtk;
using Vte;

namespace MultiTerm
{
	public class Terminal : Frame
	{
		public Vte.Terminal terminal;

		private void on_window_title_changed()
		{
			tab_label_text = terminal.window_title;
		}

		public string tab_label_text
		{
			get
			{
				TabLabel label = this.get_data<TabLabel>("label");
				return label.text;
			}
			set
			{
				TabLabel label = this.get_data<TabLabel>("label");
				label.text = value;
			}
		}

		public string background_color
		{
			set
			{
				Gdk.Color color = Gdk.Color();
				Gdk.Colormap.get_system().alloc_color(color, true, true);
				Gdk.Color.parse(value, out color);
				terminal.set_color_background(color);
			}
		}

		public string foreground_color
		{
			set
			{
				Gdk.Color color = Gdk.Color();
				Gdk.Colormap.get_system().alloc_color(color, true, true);
				Gdk.Color.parse(value, out color);
				terminal.set_color_foreground(color);
			}
		}

		private void on_vte_realize()
		{
			background_color = "white";
			foreground_color = "black";
		}

		public Terminal()
		{
			VScrollbar vsb;
			HBox hbox;

			terminal = new Vte.Terminal();
			terminal.set_size_request(100, 100); // stupid
			terminal.show_all();

			vsb = new VScrollbar(terminal.get_adjustment());
			hbox = new HBox(false, 0);

			hbox.pack_start(terminal, true, true, 0);
			hbox.pack_start(vsb, false, false, 0);

			this.add(hbox);

			terminal.window_title_changed.connect(on_window_title_changed);

			terminal.set_font_from_string_full("Monospace 9", TerminalAntiAlias.FORCE_ENABLE);

			terminal.realize.connect(on_vte_realize); /* colors can only be set on realize (lame) */

			/* TODO: add wrapper for fork_command_full() since this
			 * function is deprecated */
			terminal.fork_command(null, null, null, null, true, true, true);
		}

	}
}
