#include "liste.h"
#include "zadaci.h"

GtkWidget *listeW() {
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  GtkWidget *sidebar = gtk_stack_sidebar_new();
  GtkWidget *stack = gtk_stack_new();
  gtk_stack_set_transition_type(GTK_STACK(stack),
                                GTK_STACK_TRANSITION_TYPE_CROSSFADE);

  gtk_widget_set_size_request(sidebar, 300, 300);
  gtk_box_pack_start(GTK_BOX(box), sidebar, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), stack, FALSE, FALSE, 0);
  gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(sidebar), GTK_STACK(stack));

  struct lista *l = spisakfoldera("db");
  struct clan *folder = l->prvi;

  GtkWidget **redovi = malloc(l->duz * sizeof(GtkWidget *));
  while (folder) {
    GtkWidget *red = zadaciW(folder->ime);
    gtk_stack_add_titled(GTK_STACK(stack), red, folder->ime, folder->ime);
    folder = folder->sledeci;
  }

  return box;
}