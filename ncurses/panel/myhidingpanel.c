#include <panel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_SIZE 4
#define HEIGHT 25
#define WIDTH 55

#define KEY_TAB 9
/* move panel
   hiding and showing panel
 */
void init_wins (WINDOW **);
void init_panels (PANEL **, WINDOW **);
void print_mid (WINDOW *, char *, int);

int
main (int argc, char *argv[])
{
        WINDOW *wins[ITEM_SIZE];
        PANEL *panels[ITEM_SIZE];
        PANEL *top;
        int ch;
        int current;

        initscr ();
        if (!has_colors ()) {
                printf ("Your terminal does not support color\n");
                exit (1);
        }
        start_color ();

        init_pair (1, COLOR_RED, COLOR_BLACK);
        init_pair (2, COLOR_GREEN, COLOR_BLACK);
        init_pair (3, COLOR_BLUE, COLOR_BLACK);
        init_pair (4, COLOR_YELLOW, COLOR_BLACK);
        refresh ();

        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);
        curs_set (0);

        init_wins (wins);
        init_panels (panels, wins);

        update_panels ();
        attron (COLOR_PAIR (4));
        mvprintw (LINES - 2, 0, "Use tab to browse through the windows (F3 to exit)");
        attroff (COLOR_PAIR (4));
        doupdate ();

        current = ITEM_SIZE - 1;
        top = panels[current];
        current--;
        while ((ch = getch ()) != KEY_F (3)) {
                int pos_y, pos_x;
                WINDOW *top_win = panel_window (top);
                getbegyx (top_win, pos_y, pos_x);
                switch (ch) {
                        case KEY_TAB:
                                current++;
                                if (current == ITEM_SIZE)
                                        current = 0;
                                top = (PANEL *) panel_userptr (top);
                                top_panel (top);
                                break;
                        case KEY_BTAB:
                                current--;
                                if (current < 0)
                                        current = ITEM_SIZE + current;
                                top = (PANEL *) panel_userptr (panels[current]);
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
                        case 116: /* t letter */
                                if (panel_hidden (top))
                                        show_panel (top);
                                else
                                        hide_panel (top);
                                break;
                }
                update_panels ();
                doupdate ();
        }

        endwin ();
        return 0;
}

void
init_wins (WINDOW **wins)
{
        int height, width;
        int starty, startx;
        int y, x;
        int i;

        height = HEIGHT;
        width = WIDTH;
        getmaxyx (stdscr, y, x);
        starty = (y - height) / 2;
        startx = (x - width) / 2;

        char label[80] = "Quick brown fox";
        for (i = 0; i < ITEM_SIZE; i++) {
                wins[i] = newwin (height, width, starty - i, startx + i);
                box (wins[i], 0, 0);
                print_mid (wins[i], label, i + 1);
                mvwaddch (wins[i], 4, 0, ACS_LTEE);
                mvwhline (wins[i], 4, 1, 0, width - 2);
                mvwaddch (wins[i], 4, width - 1, ACS_RTEE);
                wrefresh (wins[i]);
        }
}

void
init_panels (PANEL **panels, WINDOW **wins)
{
        int i, j;
        for (i = 0; i < ITEM_SIZE; i++) {
                panels[i] = new_panel (wins[i]);
        }
        for (i = 0; i < ITEM_SIZE; i++) {
                if (i == ITEM_SIZE - 1)
                        set_panel_userptr (panels[i], panels[0]);
                else
                        set_panel_userptr (panels[i], panels[i + 1]);
        }
}

void
print_mid (WINDOW *win, char *label, int color)
{
        int starty, startx;
        int height, width;
        int color_c = color % 4 == 0 ? 4 : color % 4;
        getmaxyx (win, height, width);
        starty = 2;
        startx = (width - strlen (label)) / 2;
        wattron (win, COLOR_PAIR (color_c));
        mvwprintw (win, starty, startx, "%s", label);
        wattroff (win, COLOR_PAIR (color_c));
}
