#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
    initscr ();
    if (!has_colors ()) {
        printf ("Your terminal does not support color\n");
        exit (1);
    }
    start_color ();
    
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);
    
    getch ();
    
    endwin ();
    
    return 0;
}
