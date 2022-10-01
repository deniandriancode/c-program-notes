#include <ncurses.h>

int
main (int argc, char *argv[])
{
        int y, x;

        initscr ();
        cbreak ();
        noecho ();

        getyx (stdscr, y, x);
        printw ("y : %d\nx : %d", y, x);
        refresh ();

        getch ();

        endwin ();

        return 0;
}
