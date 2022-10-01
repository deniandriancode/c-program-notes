#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

void print_menu (WINDOW *, int);
void del_choice (WINDOW *, int);
void print_choice (WINDOW *, int);

char *choices[] = {
        "1. Javascript",
        "2. Python",
        "3. Ruby",
        "4. C++",
        "5. Rust"
};
int choice_size = sizeof (choices) / sizeof (char *);

int
main (int argc, char *argv[])
{
        WINDOW *menu_win;
        int height, width;
        int starty, startx;
        int ch;
        int highlight = 1;

        initscr ();
        curs_set (0);

        if (has_colors () == FALSE) {
                endwin ();
                printf ("Your terminal doesn't support color\n");
                exit (1);
        }
        start_color ();
        init_pair (1, COLOR_BLUE, COLOR_BLACK);
        init_pair (2, COLOR_GREEN, COLOR_BLACK);
        init_pair (3, COLOR_YELLOW, COLOR_BLACK);

        cbreak ();
        noecho ();

        height = 30;
        width = 80;
        starty = (LINES - height) / 2;
        startx = (COLS - width) / 2;

        menu_win = newwin (height, width, starty, startx);
        keypad (menu_win, TRUE);

        refresh ();

        box (menu_win, 0, 0);
        wrefresh (menu_win);

        print_menu (menu_win, highlight);
        while (1) {
                ch = wgetch (menu_win);
                switch (ch) {
                        case KEY_UP:
                                del_choice (menu_win, highlight);
                                if (highlight == 1)
                                        highlight = choice_size + 1;
                                print_menu (menu_win, --highlight);
                                break;
                        case KEY_DOWN:
                                del_choice (menu_win, highlight);
                                if (highlight == choice_size)
                                        highlight = 0;
                                print_menu (menu_win, ++highlight);
                                break;
                        case 10:
                                print_choice (menu_win, highlight);
                                break;
                }
                if (ch == 10)
                        break;
        }

        getch ();
        endwin ();

        return 0;
}

void
print_menu (WINDOW *menu_win, int highlight)
{
        int i;
        int y_i, x_i;
        int y, x;
        y_i = 1;
        x_i = 2;
        y = 3;
        x = 8;

        wattron (menu_win, COLOR_PAIR(1));
        mvwprintw (menu_win, y_i, x_i, "Choose your programming language :");
        wattroff (menu_win, COLOR_PAIR (1));
        for (i = 0; i < 5; i++) {
                if (i + 1 == highlight) {
                        wattron (menu_win, COLOR_PAIR (2));
                        mvwprintw (menu_win, y+i, x-2, ">");
                }
                mvwprintw (menu_win, y+i, x, "%s", choices[i]);
                wattroff (menu_win, COLOR_PAIR (2));
        }

        wrefresh (menu_win);
}

void
del_choice (WINDOW *menu_win, int prev_hl)
{
        int y, x;
        y = 3;
        x = 8;

        mvwprintw (menu_win, prev_hl+y-1, x-2, " ");
}

void
print_choice (WINDOW *menu_win, int highlight)
{
        int y, x;
        y = 4 + choice_size;
        x = 2;

        mvwprintw (menu_win, y, x, "                                                              ");
        wattron (menu_win, COLOR_PAIR (3));
        switch (highlight) {
                case 1:
                        mvwprintw (menu_win, y, x, "Seems like you do web development alot");
                        break;
                case 2:
                        mvwprintw (menu_win, y, x, "How do you clean your data?");
                        break;
                case 3:
                        mvwprintw (menu_win, y, x, "Server is busy lately yea");
                        break;
                case 4:
                        mvwprintw (menu_win, y, x, "Just don't over do with that template");
                        break;
                case 5:
                        mvwprintw (menu_win, y, x, "What's up buddy? Just don't forget to return to the owner");
                        break;
        }
        wattroff (menu_win, COLOR_PAIR (3));

        wrefresh (menu_win);
}
