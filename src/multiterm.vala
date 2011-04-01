using Gtk;
using MultiTerm;

static int main(string[] args)
{
	Gtk.init(ref args);
	
	Window win = new Window();
	win.destroy.connect(Gtk.main_quit);
	win.set_default_size(640, 480);
	win.allow_grow = true;
	win.allow_shrink = true;
	
	MultiTerm.Notebook nb = new MultiTerm.Notebook(4);
	nb.show_all();
	
	win.add(nb);
	win.show_all();
	
	Gtk.main();
	
	return 0;
}
