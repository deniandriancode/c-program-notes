#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_in_middle (WINDOW *, int, int, int, char *);

int
main (int argc, char *argv[])
{
        initscr ();
        curs_set (0);

        if (has_colors () == FALSE) {
                endwin ();
                printf ("Your terminal doesn't support color");
                exit (1);
        }
        start_color ();

        print_in_middle (stdscr, LINES / 2, 0, 0, "Viola!! in color ..");

        getch ();

        endwin ();

        return 0;
}

void
print_in_middle (WINDOW *win, int starty,
                 int startx, int width, char *string)
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
        
        init_pair (1, COLOR_RED, COLOR_BLACK);
        attron (COLOR_PAIR(1));
        mvwprintw (win, y, x, "%s", string);
        attroff (COLOR_PAIR(1));

        init_pair (2, COLOR_BLUE, COLOR_BLACK);
        attron (COLOR_PAIR(2));
        mvwprintw (win, ++y, x, "This printed in blue");
        attroff (COLOR_PAIR(2));

        refresh ();
}
