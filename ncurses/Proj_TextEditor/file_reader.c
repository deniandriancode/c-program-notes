#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define BUFFER_SIZE 1000

int
main (int argc, char *argv[])
{       
        FILE *fp;
        char *buffer;
        chtype *mystr;
        buffer = (char *) malloc (sizeof (char *) * BUFFER_SIZE);
        mystr = (chtype *) malloc (sizeof (chtype *) * BUFFER_SIZE);
        int x;

        initscr ();
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        fp = fopen ("myfile.txt", "r");
        if (!fp)
                return 1;

        addch ('e');

        /*while (fgets (buffer, BUFFER_SIZE, fp) != NULL) {*/
                /*printw ("%s", buffer);*/
        /*}*/

        refresh ();
        inchstr (mystr);
        getchar ();

        endwin ();
        fclose (fp);
        free (buffer);

        printf ("%s", (char *) mystr);

        return 0;
}
