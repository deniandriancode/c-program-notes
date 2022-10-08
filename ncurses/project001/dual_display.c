#include <panel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 15
#define WIDTH 35

#define KEY_TAB 9

void print_box_title (WINDOW *, char *, chtype);
void create_sub_win (WINDOW *, chtype);

int
main (int argc, char *argv[])
{
        PANEL *left_panel;
        PANEL *right_panel;
        WINDOW *left_win;
        WINDOW *right_win;
        PANEL *top;

        int starty, startx;
        int ch;

        initscr ();
        if (!has_colors ()) {
                printf ("Your terminal does not support color.\n");
                exit (1);
        }
        start_color ();
        init_pair (1, COLOR_BLUE, COLOR_BLACK);
        init_pair (2, COLOR_GREEN, COLOR_BLACK);
        init_pair (3, COLOR_BLACK, COLOR_BLUE);
        init_pair (4, COLOR_BLACK, COLOR_GREEN);

        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);
        refresh ();

        starty = (LINES - HEIGHT) / 2;
        startx = (COLS - WIDTH) / 2;

        left_win = newwin (HEIGHT, WIDTH, starty, startx - (WIDTH / 2) - 2);
        right_win = newwin (HEIGHT, WIDTH, starty, startx + (WIDTH / 2) + 2);
        print_box_title (left_win, "Blue Panel", COLOR_PAIR (1));
        print_box_title (right_win, "Green Panel", COLOR_PAIR (2));
        
        create_sub_win (left_win, COLOR_PAIR (3));
        create_sub_win (right_win, COLOR_PAIR (4));

        box (left_win, 0, 0);
        box (right_win, 0, 0);
        keypad (left_win, TRUE);
        keypad (right_win, TRUE);

        left_panel = new_panel (left_win);
        right_panel = new_panel (right_win);

        set_panel_userptr (left_panel, right_panel);
        set_panel_userptr (right_panel, left_panel);

        update_panels ();
        doupdate ();

        top = right_panel;
        while ((ch = getch ()) != KEY_F (2)) {
                int pos_y, pos_x;
                WINDOW *top_win = panel_window (top);
                getbegyx (top_win, pos_y, pos_x);
                switch (ch) {
                        case KEY_TAB:
                                top = (PANEL *) panel_userptr (top);
                                top_panel (top);
                                break;
                        case KEY_UP:
                                move_panel (top, --pos_y, pos_x);
                                break;
                        case KEY_LEFT:
                                move_panel (top, pos_y, --pos_x);
                                break;
                        case KEY_DOWN:
                                move_panel (top, ++pos_y, pos_x);
                                break;
                        case KEY_RIGHT:
                                move_panel (top, pos_y, ++pos_x);
                                break;
                }
                update_panels ();
                doupdate ();
        }

        endwin ();        

        return 0;
}

void
print_box_title (WINDOW *win, char *message, chtype color)
{
        int y, x;
        int center_x;
        int msg_len = strlen (message);
        getmaxyx (win, y, x);
        center_x = (x - msg_len) / 2;
        wattron (win, color);
        mvwprintw (win, 1, center_x, message);
        wattroff (win, color);
        wrefresh (win);
}

void
create_sub_win (WINDOW *win, chtype color)
{
        int y, x;
        int width;
        char msg[] = "                                                                                                                                                                                                                                                           ";
        getmaxyx (win, y, x);
        width = x - 10;
        WINDOW *child_win;
        child_win = derwin (win, y - 5, width, 3, (x - width) / 2);
        wattron (child_win, color);
        wprintw (child_win, msg);
        wattroff (child_win, color);
        wrefresh (child_win);
}
