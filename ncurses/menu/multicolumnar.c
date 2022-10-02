#include <menu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define ARRAY_SIZE(a) (sizeof (a) / sizeof (a[0]))
#define CTRL_D 4

char *choices[] = {
        "Choice 1", "Choice 2", "Choice 3", "Choice 4", "Choice 5",
	"Choice 6", "Choice 7", "Choice 8", "Choice 9", "Choice 10",
	"Choice 11", "Choice 12", "Choice 13", "Choice 14", "Choice 15",
	"Choice 16", "Choice 17", "Choice 18", "Choice 19", "Choice 20",
        "Exit",
	(char *) NULL
};

void print_in_middle (WINDOW *,
                      int, int, int,
                      char *, chtype);

int
main (int argc, char *argv[])
{
        ITEM **my_items;
        ITEM *cur_item;
        MENU *my_menu;
        WINDOW *my_menu_win;
        int c;
        int n_choices, i;

        initscr ();
        if (!has_colors ()) {
                printf ("Your terminal does not support color\n");
                exit (0);
        }
        start_color ();
        init_pair (1, COLOR_YELLOW, COLOR_BLACK);
	init_pair (2, COLOR_CYAN, COLOR_BLACK);
        cbreak ();
        noecho ();
        curs_set (0);
        keypad (stdscr, TRUE);

        n_choices = ARRAY_SIZE (choices);
        my_items = (ITEM **) calloc (n_choices + 1, sizeof (ITEM *));

        for (i = 0; i < n_choices; i++)
                my_items[i] = new_item (choices[i], choices[i]);
        my_items[n_choices] = (ITEM *) NULL;

        my_menu = new_menu ((ITEM **)my_items);
        my_menu_win = newwin (10, 40, 4, 4);
        keypad (my_menu_win, TRUE);

        set_menu_win (my_menu, my_menu_win);
        set_menu_sub (my_menu, derwin (my_menu_win, 6, 38, 3, 1));
	set_menu_format (my_menu, 5, 3);

        set_menu_mark (my_menu, " * ");

        box (my_menu_win, 0, 0);

        print_in_middle (my_menu_win, 1, 0, 40, "My Menu", COLOR_PAIR (1));

        mvwaddch (my_menu_win, 2, 0, ACS_LTEE);
        mvwhline (my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch (my_menu_win, 2, 39, ACS_RTEE);

        post_menu (my_menu);
        wrefresh (my_menu_win);

	attron (COLOR_PAIR (2));
	mvprintw (LINES - 2, 0, "Use PageUp and PageDown to scroll down or up a page of items");
	mvprintw (LINES - 1, 0, "Arrow key to navigate (F2 to exit)");
	attroff (COLOR_PAIR (2));
        refresh ();

        while ((c = getch ()) != KEY_F (2)) {
                switch (c) {
                        case KEY_DOWN:
                                menu_driver (my_menu, REQ_DOWN_ITEM);
                                break;
                        case KEY_UP:
                                menu_driver (my_menu, REQ_UP_ITEM);
                                break;
			case KEY_RIGHT:
			  	menu_driver (my_menu, REQ_RIGHT_ITEM);
				break;
			case KEY_LEFT:
			  	menu_driver (my_menu, REQ_LEFT_ITEM);
				break;
			case KEY_NPAGE:
			  	menu_driver (my_menu, REQ_SCR_DPAGE);
				break;
			case KEY_PPAGE:
			  	menu_driver (my_menu, REQ_SCR_UPAGE);
				break;
                }
                wrefresh (my_menu_win);
        }

        unpost_menu (my_menu);
        free_menu (my_menu);
        for (i = 0; i < n_choices; i++)
                free_item (my_items[i]);

        endwin ();
        return 0;
}

void
print_in_middle (WINDOW *win,
                int starty, int startx, int width,
                char *string, chtype color)
{
        int length, x, y;
        float temp;

        if (win == NULL)
                win = stdscr;
        getyx (win, y, x);
        if (startx != 0)
                x = startx;
        if (starty != 0)
                y = starty;
        if (width == 0)
                width = 80;

        length = strlen (string);
        temp = (width - length) / 2;
        x = startx + (int) temp;
        wattron (win, color);
        mvwprintw (win, y, x, "%s", string);
        wattroff (win, color);
        refresh ();
}
