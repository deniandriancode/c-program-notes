#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define WINDOW_HEIGHT 20
#define WINDOW_WIDTH 30

WINDOW *create_win (int, int, int, int);
void create_out_win (int, int, int, int);

int
main (int argc, char *argv[])
{
    WINDOW *win;
    int starty, startx;
    int ch;
    
    initscr ();
    if (!has_colors ()) {
        printf ("Your terminal does not support color.\n");
        exit (1);
    }
    start_color ();
    init_pair (1, COLOR_BLUE, COLOR_BLACK);
    
    cbreak ();
    noecho ();
    
    starty = (LINES - WINDOW_HEIGHT) / 2;
    startx = (COLS - WINDOW_WIDTH) / 2;
    refresh ();
    
    win = create_win (starty, startx, WINDOW_HEIGHT, WINDOW_WIDTH);
    create_out_win (starty, startx, WINDOW_HEIGHT, WINDOW_WIDTH);
    keypad (win, TRUE);

    wrefresh (win);
    scrollok (win, TRUE);
    wsetscrreg (win, 0, 100);

    while (1) {
        ch = wgetch (win);
        int y, x;
        getyx (win, y, x);
        switch (ch) {
            case KEY_UP:
                if (y == 0)
                    wscrl (win, -1);
                y -= 1;
                wmove (win, y, x);
                break;
            case KEY_RIGHT:
                x += 1;
                wmove (win, y, x);
                break;
            case KEY_DOWN:
                int win_y, win_x;
                getmaxyx (win, win_y, win_x);
                if (y == win_y - 1)
                    scroll (win);
                y += 1;
                wmove (win, y, x);
                break;
            case KEY_LEFT:
                x -= 1;
                wmove (win, y, x);
                break;
            case KEY_BACKSPACE:
                mvwdelch (win, y, --x);
                break;
            default:
                waddch (win, ch);
        }
        wrefresh (win);
        if (ch == KEY_F (3))
            break;
    }
    
    endwin ();
    
    return 0;
}

WINDOW*
create_win (int starty, int startx,
            int height, int width)
{
    WINDOW *win = newwin (height, width, starty, startx);
    wrefresh (win);
    return win;
}

void
create_out_win (int starty, int startx,
                int height, int width)
{
    WINDOW *out_win = newwin (height + 5, width + 6, starty - 2, startx - 3);
    box (out_win, 0, 0);
    wrefresh (out_win);
}
