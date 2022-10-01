#include <stdio.h>
#include <ncurses.h>

#define BUFFER_SIZE 5000

int
main (int argc, char *argv[])
{
        FILE *fp;
        char content[BUFFER_SIZE];
        int ch;

        initscr ();
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        fp = fopen ("myfile.txt", "r");
        do {
                fgets (content, BUFFER_SIZE, fp);
        } while (fgets (content, BUFFER_SIZE, fp) != NULL);
        printw ("%s", content);
        refresh ();

        while (1) {
               ch = getch ();
               switch (ch) {
                        case KEY_UP:
                               break;
                        case KEY_DOWN:
                               break;
               }

               refresh ();

               if (ch == KEY_F (3))
                       break;
        }

        endwin ();

        return 0;
}
