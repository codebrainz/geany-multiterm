using Gtk;
using Pango;
using Vte;

namespace MultiTerm
{
	public class Notebook : Gtk.Notebook
	{
		private Button add_button;

		private void on_tab_label_close_clicked(int tab_num)
		{
			if (this.get_n_pages() > 1)
				this.remove_terminal(tab_num);
		}

		private void on_add_button_style_set()
		{
			int w, h;
			Gtk.icon_size_lookup_for_settings(add_button.get_settings(),
											  IconSize.MENU,
											  out w, out h);
			add_button.set_size_request(w+2, h+2);
		}

		public void add_terminal()
		{
			TabLabel label;
			ITerminal term;

			term = new ShellTerminal();

			label = new TabLabel();
			label.show_all();
			label.close_clicked.connect(on_tab_label_close_clicked);
			label.set_data<ITerminal>("terminal", term);

			term.set_data<TabLabel>("label", label);
			term.show_all();

			this.append_page(term, label);

			this.set_tab_reorderable(term, true);

			/* TODO: check if this is depracated */
			this.set_tab_label_packing(term, true, true, PackType.END);
		}

		public void remove_terminal(int tab_num)
		{
			this.remove_page(tab_num);
		}

		public class Notebook(uint initial_terms=1)
		{
			Image img;
			RcStyle style;

			for (uint i=0; i < initial_terms; i++)
				add_terminal();

			style = new RcStyle();
			style.xthickness = 0;
			style.ythickness = 0;

			add_button = new Button();
			add_button.modify_style(style);
			add_button.relief = ReliefStyle.NONE;
			add_button.focus_on_click = false;
			add_button.set_border_width(2);
			add_button.set_tooltip_text("New terminal");
			img = new Image.from_stock(Gtk.Stock.ADD, Gtk.IconSize.MENU);
			add_button.add(img);
			add_button.clicked.connect(add_terminal);
			add_button.show_all();
			add_button.style_set.connect(on_add_button_style_set);
			this.set_action_widget(add_button, PackType.END);
		}
	}
}
