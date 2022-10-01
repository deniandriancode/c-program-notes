#include <ncurses.h>

WINDOW *create_newwin (int, int, int, int);
void destroy_win (WINDOW *);

int
main (int argc, char *argv[])
{
        WINDOW *win;
        int height, width;
        int starty, startx;
        int ch;

        initscr ();

        cbreak ();
        keypad (stdscr, TRUE);
        curs_set (0);
        noecho ();

        height = 10;
        width = 30;
        starty = (LINES - height) / 2;
        startx = (COLS - width) / 2;
        refresh ();

        win = create_newwin (height, width, starty, startx);
/*337402336393*/
        while ((ch = getch ()) != KEY_F(1)) {
                switch (ch) {
                        case KEY_LEFT:
                                destroy_win (win);
                                win = create_newwin (height, --width, starty, startx);
                                break;
                        case KEY_RIGHT:
                                destroy_win (win);
                                win = create_newwin (height, ++width, starty, startx);
                                break;
                        case KEY_UP:
                                destroy_win (win);
                                win = create_newwin (--height, width, starty, startx);
                                break;
                        case KEY_DOWN:
                                destroy_win (win);
                                win = create_newwin (++height, width, starty, startx);
                                break;
                        case 393:
                                destroy_win (win);
                                win = create_newwin (height, width, starty, --startx);
                                break;
                        case 402:
                                destroy_win (win);
                                win = create_newwin (height, width, starty, ++startx);
                                break;
                        case 337:
                                destroy_win (win);
                                win = create_newwin (height, width, --starty, startx);
                                break;
                        case 336:
                                destroy_win (win);
                                win = create_newwin (height, width, ++starty, startx);
                                break;
                }
        }

        endwin ();
        return 0;
}

WINDOW*
create_newwin (int height, int width,
               int starty, int startx)
{
        WINDOW *localwin;
        localwin = newwin (height, width, starty, startx);
        box (localwin, 0, 0);
        wrefresh (localwin);

        return localwin;
}

void
destroy_win (WINDOW *localwin)
{
        wborder (localwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        wrefresh (localwin);
        delwin (localwin);
}
