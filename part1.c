#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include<stdbool.h> 

GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget	*button1;
GtkWidget	*label1;
GtkWidget	*label2;
GtkWidget	*cost;
GtkWidget	*electrode;
GtkWidget	*slag;
GtkWidget	*syn;
GtkWidget	*out;
GtkWidget	*confirm;
GtkWidget	*taken;
GtkWidget	*output;
GtkWidget	*watt;
GtkWidget	*waste;
GtkWidget	*volume;
GtkWidget	*large;
GtkWidget	*radio1;
GtkWidget	*temperature;
GtkWidget	*radio2;
GtkWidget	*radio3;
GtkWidget	*r1;
GtkWidget	*r2;
GtkWidget	*r3;
GtkWidget	*r4;
GtkWidget	*check1;
GtkWidget	*spin1;
GtkWidget	*spin2;
GtkWidget	*spin3;
GtkWidget	*switch1;
GtkWidget	*combo1;
GtkWidget	*entry1;
GtkWidget	*frame1;
GtkWidget	*frame2;
GtkWidget	*frame3;
GtkWidget	*frame4;
GtkBuilder	*builder; 
GtkListStore	*liststore1;
GtkAdjustment	*adjustment2;

int gas=1, elec=1, option;
gdouble val;

G_MODULE_EXPORT void	on_button1_clicked(GtkButton *b);
G_MODULE_EXPORT void	on_r1_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_r2_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_r3_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_r4_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_radio1_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_radio2_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_radio3_toggled(GtkRadioButton *b);
G_MODULE_EXPORT void	on_check1_toggled(GtkCheckButton *b);
G_MODULE_EXPORT void	on_combo1_changed(GtkComboBox *c);
G_MODULE_EXPORT void	on_entry1_changed(GtkEntry *e);
G_MODULE_EXPORT void	on_switch1_state_set (GtkSwitch *s);
G_MODULE_EXPORT void	on_confirm_clicked (GtkButton *b);


int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv); // init Gtk
//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
	builder = gtk_builder_new_from_file ("part1.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	confirm = GTK_WIDGET(gtk_builder_get_object(builder, "confirm"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
	label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
	electrode = GTK_WIDGET(gtk_builder_get_object(builder, "electrode"));
	slag = GTK_WIDGET(gtk_builder_get_object(builder, "slag"));
	syn = GTK_WIDGET(gtk_builder_get_object(builder, "syn"));
	out = GTK_WIDGET(gtk_builder_get_object(builder, "out"));
	taken = GTK_WIDGET(gtk_builder_get_object(builder, "taken"));
	temperature = GTK_WIDGET(gtk_builder_get_object(builder, "temperature"));
	output = GTK_WIDGET(gtk_builder_get_object(builder, "output"));
	volume = GTK_WIDGET(gtk_builder_get_object(builder, "volume"));
	waste = GTK_WIDGET(gtk_builder_get_object(builder, "waste"));
	cost = GTK_WIDGET(gtk_builder_get_object(builder, "cost"));
	watt = GTK_WIDGET(gtk_builder_get_object(builder, "watt"));
	large = GTK_WIDGET(gtk_builder_get_object(builder, "large"));
	r1 = GTK_WIDGET(gtk_builder_get_object(builder, "r1"));
	r2 = GTK_WIDGET(gtk_builder_get_object(builder, "r2"));
	r3 = GTK_WIDGET(gtk_builder_get_object(builder, "r3"));
	r4 = GTK_WIDGET(gtk_builder_get_object(builder, "r4"));
	radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
	radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
	radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
	check1 = GTK_WIDGET(gtk_builder_get_object(builder, "check1"));
	switch1 = GTK_WIDGET(gtk_builder_get_object(builder, "switch1"));
	combo1 = GTK_WIDGET(gtk_builder_get_object(builder, "combo1"));
	entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
	spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin1"));
	spin2 = GTK_WIDGET(gtk_builder_get_object(builder, "spin2"));
	spin3 = GTK_WIDGET(gtk_builder_get_object(builder, "spin3"));
	frame1 = GTK_WIDGET(gtk_builder_get_object(builder, "frame1"));
	frame2 = GTK_WIDGET(gtk_builder_get_object(builder, "frame2"));
	frame3 = GTK_WIDGET(gtk_builder_get_object(builder, "frame3"));
	frame4 = GTK_WIDGET(gtk_builder_get_object(builder, "frame4"));
	liststore1 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));
	adjustment2 = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "adjustment2"));

	GdkColor color;
	color.red = 0xcccc;
	color.green = 0xcccc;
	color.blue = 0xd900;
	gtk_widget_modify_bg(GTK_WIDGET(window), GTK_STATE_NORMAL, &color);

	color.red = 0xaaaa;
	color.green = 0xaaaa;
	color.blue = 0xeeee;
	gtk_widget_modify_bg(frame1, GTK_STATE_NORMAL, &color);

	color.red = 0xaaaa;
	color.green = 0xeeee;
	color.blue = 0xaaaa;
	gtk_widget_modify_bg(frame2, GTK_STATE_NORMAL, &color);

	color.red = 0xeeee;
	color.green = 0xaaaa;
	color.blue = 0xaaaa;
	gtk_widget_modify_bg(frame3, GTK_STATE_NORMAL, &color);

	color.red = 0xeeee;
	color.green = 0xeeee;
	color.blue = 0xaaaa;

	gtk_widget_modify_bg(frame4, GTK_STATE_NORMAL, &color);
	gtk_widget_show(window);
	gtk_main();
	
	return EXIT_SUCCESS;
	}

void	on_combo1_changed(GtkComboBox *c){
	option = gtk_combo_box_get_active(c);
	switch(option){
		case 0:	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio1),TRUE);
				gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r1),TRUE);
				break;
		case 1:	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio1),TRUE);
				gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r2),TRUE);
				break;
		case 2:	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio2),TRUE);
				gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE);
				break;
		case 3:	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio3),TRUE);
				gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r4),TRUE);
				break;
		case 4:	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio2),TRUE);
				gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE);
				break;
		default:gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio3),TRUE);break;
	}
}

void	on_button1_clicked (GtkButton *b) {
	char tmp[128],final[10],something[10],vol[10],slag1[10],taken1[10],output1[10];
	val = gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin1));
	sprintf(something, "$%d", (int)gas*90*(int)val);
	gtk_label_set_text(GTK_LABEL(cost), (const gchar* ) something);
	sprintf(final, "%d kW", (int) elec*(int)val);
	gtk_label_set_text(GTK_LABEL(watt), (const gchar* ) final);
	sprintf(vol, "%dk cubic inches", (int)val/2+1);
	gtk_label_set_text(GTK_LABEL(volume), (const gchar* ) vol);
	sprintf(slag1, "%dk tonnes", 4*(int)val/5);
	sprintf(output1, "%dk litres", (int)val/5+1);
	gtk_label_set_text(GTK_LABEL(output), (const gchar* ) output1);
	gtk_label_set_text(GTK_LABEL(slag), (const gchar* ) slag1);
	sprintf(taken1, "%d minutes", 10*(int)val/(5*elec*gas));
	gtk_label_set_text(GTK_LABEL(taken), (const gchar* ) taken1);
	}

void	on_confirm_clicked (GtkButton *b) {
	char pressure[10],temper[10],outflow[10];
	gdouble val1 = gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin2));
	gdouble val2 = gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin3));
	sprintf(pressure, "%d000 psi", 4*(int)val1/5);
	gtk_label_set_text(GTK_LABEL(syn), (const gchar* ) pressure);
	sprintf(temper, "%d°C", (int)val2*gas*30);
	gtk_label_set_text(GTK_LABEL(temperature), (const gchar* ) temper);
	sprintf(outflow, "%d kg/minute",12*(int)val1/5*(int)val2);
	gtk_label_set_text(GTK_LABEL(out), (const gchar* ) outflow);
}

void	on_r1_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(electrode), (const gchar* ) "Copper and");
		elec = 1;
	}
}

void	on_r2_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(electrode), (const gchar* ) "Tungsten and");
		elec = 2;
	}
}

void	on_r3_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(electrode), (const gchar* ) "Hafnium and");
		elec = 3;
	}
}
	

void	on_r4_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(electrode), (const gchar* ) "Zirconium and");
		elec = 4;
	}
}
	

void	on_radio1_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	gboolean *neon, *argon, *krypton;
	if (T){
		gtk_label_set_text(GTK_LABEL(label1), (const gchar* ) "Neon Used");
		gas = 1;
	}
}
	
void	on_radio2_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(label1), (const gchar* ) "Argon Used");
		gas = 2;
	}
}

void	on_radio3_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T){
		gtk_label_set_text(GTK_LABEL(label1), (const gchar* ) "Krypton Used");
		gas = 3;
	}
}

void	on_switch1_state_set (GtkSwitch *s) {
	gboolean T = gtk_switch_get_active(s);
	if (T) gtk_label_set_text(GTK_LABEL(waste), (const gchar* ) "Disposed!");
	else gtk_label_set_text(GTK_LABEL(waste), (const gchar* ) "");
}
	
void	on_entry1_changed(GtkEntry *e) {
	char tmp[128];
	sprintf(tmp, "on %s", gtk_entry_get_text(e));
	gtk_label_set_text(GTK_LABEL(label2), (const gchar* ) tmp);
}
