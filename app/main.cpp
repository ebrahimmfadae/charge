#include <gtk/gtk.h>

int main(int argc, char **argv)
{
   GtkWidget *window;
   GtkBuilder *builder = NULL;

   gtk_init(&argc, &argv);

   builder = gtk_builder_new();

   if (gtk_builder_add_from_file(builder, "views/main.glade", NULL) == 0)
   {
      printf("gtk_builder_add_from_file FAILED\n");
      return 0;
   }

   window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

   gtk_builder_connect_signals(builder, NULL);

   gtk_widget_show_all(window);
   gtk_main();
   return 0;
}