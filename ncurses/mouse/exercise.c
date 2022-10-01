#include <ncurses.h>

int
main (int argc, char *argv[])
{
        initscr ();
        clear ();
        cbreak ();
        noecho ();
        curs_set (1);
        keypad (stdscr, TRUE);

        mousemask (ALL_MOUSE_EVENTS, NULL);

        while (1) {
                int c = getch ();
                MEVENT event;
                switch (c) {
                        case KEY_MOUSE:
                                if (getmouse (&event) == OK) {
                                        if (event.bstate & BUTTON1_CLICKED)
                                                printw ("Clicked\n");
                                        if (event.bstate & BUTTON1_PRESSED)
                                                printw ("Pressed\n");
                                        if (event.bstate & BUTTON1_DOUBLE_CLICKED)
                                                printw ("Double Clicked\n");
                                }
                                break;
                        case 10:
                                printw ("Enter\n");
                                break;
                }
                if (c == 113)
                        break;
        }

        getch ();

        endwin ();

        return 0;
}
