#include <ncurses.h>
#include <string>
#include "Editor.h"

void curses_init ();

int
main (int argc, char *argv[])
{
        Editor ed;
        std::string fn = "";

        if (argc > 1) {
                fn = argv[1];
                ed = Editor (fn);
        } else {
                ed = Editor ();
        }

        curses_init ();
        while (ed.getMode () != 'x') {
                ed.updateStatus ();
                ed.printStatusLine ();
                ed.printBuff ();
                int input =  getch ();
                ed.handleInput (input);
        }

        refresh ();
        endwin ();

        return 0;
}

void
curses_init ()
{
        initscr ();
        cbreak ();
        noecho ();
        keypad (stdscr, true);
}
