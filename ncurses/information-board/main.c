#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 40
#define WIDTH 130

int starty = 0;
int startx = 0;

char *infos[] = {
        "Overview",
        "Introduction",
        "Main",
        "Update",
        "Help",
        "Exit"
};
int n_infos = sizeof (infos) / sizeof (char *);

void print_menu (WINDOW *, int);
void print_info (WINDOW *, int);
void del_choice (WINDOW *, int);

int
main (int argc, char *argv[])
{
        WINDOW *main_win;
        WINDOW *info_win;
        int highlight = 1;
        int ch;

        initscr ();

        if (has_colors () == FALSE) {
                printf ("Your terminal doesn't support colors");
                endwin ();
                exit (1);
        }
        start_color ();
        mousemask (ALL_MOUSE_EVENTS, NULL);
        
        clear ();
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        starty = (LINES  - HEIGHT) / 2;
        startx = (COLS - WIDTH) / 2;

        init_pair (1, COLOR_YELLOW, COLOR_BLACK);

        main_win = newwin (HEIGHT, WIDTH, starty, startx);

        int subwin_height, subwin_width;
        subwin_height = 28;
        subwin_width = 120;
        starty = (HEIGHT - subwin_height) / 2 + n_infos + 2;
        startx = (COLS - subwin_width) / 2;
        info_win = newwin (subwin_height, subwin_width, starty, startx);
        refresh ();

        box (main_win, 0, 0);

        /* print title */
        char title[] = " INFO MENU ";
        int title_y = 0;
        int title_x = (WIDTH - strlen (title)) / 2;
        mvwprintw (main_win, title_y, title_x, "%s", title);

        mvwprintw (main_win, 2, 2, "Select the information you want to read :");
        wrefresh (main_win);
        wrefresh (info_win);
        print_menu (main_win, highlight);
        while (1) {
                ch = getch ();
                switch (ch) {
                        case KEY_UP:
                                del_choice (main_win, highlight);
                                if (highlight == 1)
                                        highlight = n_infos + 1;
                                print_menu (main_win, --highlight);
                                break;
                        case KEY_DOWN:
                                del_choice (main_win, highlight);
                                if (highlight == n_infos)
                                        highlight = 0;
                                print_menu (main_win, ++highlight);
                                break;
                        case 10:
                                print_info (info_win, highlight);
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
print_menu (WINDOW *win, int highlight)
{
        int i;
        int y, x;
        y = 4;
        x = 8;

        for (i = 0; i < n_infos; ++i) {
                if (highlight == i+1) {
                        wattron (win, COLOR_PAIR (1));
                        mvwprintw (win, y+i, x-2, "> ");
                }
                mvwprintw (win, y+i, x, infos[i]);
                wattroff (win, COLOR_PAIR (1));
        }
        wrefresh (win);
}

void
print_info (WINDOW *info_win, int highlight)
{
        int y, x;
        y = 2;
        x = 2;
        mvwprintw (info_win, y, x, "EElit odio eveniet facilis praesentium nam ex Sit suscipit facere aperiam modi accusantium Impedit perferendis aut in autem quisquam atque Aliquid a asperiores ea culpa unde? Qui reprehenderit aspernatur corpori slit odio eveniet facilis praesentium nam ex Sit suscipit facere aperiam modi accusantium Impedit perferendis aut in autem quisquam atque Aliquid a asperiores ea culpa unde? Qui reprehenderit aspernatur corporis");
        wrefresh (info_win);
}

void
del_choice (WINDOW *win, int highlight)
{
        int y = 4;
        int x = 6;
        mvwprintw (win, y + highlight - 1, x, " ");
        wrefresh (win);
}
