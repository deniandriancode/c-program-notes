#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof (a) / sizeof (a[0]))
#define CTRL_D 4

char *choices[] = {
	"Choice 1",
	"Choice 2",
	"Choice 3",
	"Choice 4",
	"Choice 5",
	"Choice 6",
	"Choice 7",
	"Exit"
};

char *desc_choices[] = {
	"No 1",
	"No 2",
	"No 3",
	"No 4",
	"No 5",
	"No 6",
	"No 7",
	"Exit the program"
};

int
main (int argc, char *argv[])
{
  	ITEM **my_items;
	MENU *my_menu;
	ITEM *cur_item;
	int c;
	int n_choices, i;

	initscr ();
	if (!has_colors ()) {
	  	printf ("Your terminal does not support color\n");
		exit (0);
	}
	start_color ();
	cbreak ();
	noecho ();
	keypad (stdscr, TRUE);

	init_pair (1, COLOR_RED, COLOR_BLACK);
	init_pair (2, COLOR_GREEN, COLOR_BLACK);
	init_pair (3, COLOR_MAGENTA, COLOR_BLACK);

	n_choices = ARRAY_SIZE (choices);
	my_items = (ITEM **) calloc (n_choices + 1, sizeof (ITEM *));
	for (i = 0; i < n_choices; i++)
	  	my_items[i] = new_item (choices[i], desc_choices[i]);
	my_items[n_choices] = (ITEM *) NULL;
	item_opts_off (my_items[3], O_SELECTABLE);
	item_opts_off (my_items[6], O_SELECTABLE);

	my_menu = new_menu ((ITEM **) my_items);

	set_menu_fore (my_menu, COLOR_PAIR (1) | A_REVERSE);
	set_menu_back (my_menu, COLOR_PAIR (2));
	set_menu_grey (my_menu, COLOR_PAIR (3));

	post_menu (my_menu);
	refresh ();

	while ((c = getch ()) != KEY_F (2)) {
	  	switch (c) {
		  	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10:
			  	move (20, 0);
				clrtoeol ();
				mvprintw (20, 0, "Item selected is : %s", item_name (current_item (my_menu)));
				pos_menu_cursor (my_menu);
				break;
		}
	}
	unpost_menu (my_menu);
	for (i = 0; i < n_choices; i++)
	  	free_item (my_items[i]);
	free_menu (my_menu);
	endwin ();
	
	return 0;
}
