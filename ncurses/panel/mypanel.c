#include <panel.h>

#define HEIGHT 5
#define WIDTH 15

int
main (int argc, char *argv[])
{
    WINDOW *wins[2];
    PANEL *panels[2];
    int starty, startx;
    int i;

    starty = 5;
    startx = 5;

    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);

    refresh ();

    wins[0] = newwin (HEIGHT, WIDTH, starty, startx);
    wins[1] = newwin (HEIGHT, WIDTH, starty + 2, startx + 2);

    panels[0] = new_panel (wins[0]);
    panels[1] = new_panel (wins[1]);

    for (i = 0; i < 2; i++) {
        box (wins[i], 0, 0);
    }

    update_panels ();

    doupdate ();


    getch ();
    endwin ();

    return 0;
}
