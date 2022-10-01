#include <ncurses.h>

void destroy_win (WINDOW *);
WINDOW *create_newwin (int, int, int, int);

int
main (int argc,
      char *argv[])
{
	WINDOW *mywin;

	int startx, starty, width, height;
        int ch;

  	initscr ();
        cbreak ();

        keypad (stdscr, TRUE);
        curs_set (0);

        height = 3;
        width = 10;
        starty = (LINES - height) / 2;
        startx = (COLS - width) / 2;
        printw ("Press F3 to exit");
        refresh ();

        mywin = create_newwin (height, width, starty, startx);

        while ((ch = getch ()) != KEY_F(3)) {
                switch (ch) {
                        case KEY_LEFT:
                                destroy_win (mywin);
                                mywin = create_newwin (height, width, starty, --startx);
                                break;
                        case KEY_UP:
                                destroy_win (mywin);
                                mywin = create_newwin (height, width, --starty, startx);
                                break;
                        case KEY_RIGHT:
                                destroy_win (mywin);
                                mywin = create_newwin (height, width, starty, ++startx);
                                break;
                        case KEY_DOWN:
                                destroy_win (mywin);
                                mywin = create_newwin (height, width, ++starty, startx);
                                break;
                }
        }
  
	endwin ();
	return 0;
}

void
destroy_win (WINDOW *localwin)
{
        wborder (localwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        wrefresh (localwin);
        delwin (localwin);
}

WINDOW*
create_newwin (int height,
               int width,
               int starty,
               int startx)
{
        WINDOW *localwin;
        localwin = newwin (height, width, starty, startx);
        box (localwin, 0, 0);

        wrefresh (localwin);

        return localwin;
}
