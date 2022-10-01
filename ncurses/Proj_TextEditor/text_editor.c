#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char *argv[])
{
        FILE *fp;
        int file_size;

        initscr ();
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        clear ();
        endwin ();

        return 0;
}
