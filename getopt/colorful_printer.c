/**
 * Print message with colorful text
 * */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define FG_BLACK 30
#define FG_RED 31
#define FG_GREEN 32
#define FG_YELLOW 33
#define FG_BLUE 34
#define FG_MAGENTA 35
#define FG_CYAN 36
#define FG_WHITE 37

#define BG_BLACK 40
#define BG_RED 41
#define BG_GREEN 42
#define BG_YELLOW 43
#define BG_BLUE 44
#define BG_MAGENTA 45
#define BG_CYAN 46
#define BG_WHITE 47

int
main (int argc, char **argv)
{
        /*printf ("\033[?25h");*/
        /*printf ("\033[32;40m");*/
        int f = 37;
        int b = 40;
        char *message = "nomsg";
        int ch;

        opterr = 0;

        while ((ch = getopt (argc, argv, "f:b:m:")) != -1) {
                switch (ch) {
                        case 'f':
                                if (strcmp (optarg, "black") == 0)
                                        f = FG_BLACK;
                                else if (strcmp (optarg, "red") == 0)
                                        f = FG_RED;
                                else if (strcmp (optarg, "green") == 0)
                                        f = FG_GREEN;
                                else if (strcmp (optarg, "yellow") == 0)
                                        f = FG_YELLOW;
                                else if (strcmp (optarg, "blue") == 0)
                                        f = FG_BLUE;
                                else if (strcmp (optarg, "magenta") == 0)
                                        f = FG_MAGENTA;
                                else if (strcmp (optarg, "cyan") == 0)
                                        f = FG_CYAN;
                                else if (strcmp (optarg, "white") == 0)
                                        f = FG_WHITE;
                                break;
                        case 'b':
                                if (strcmp (optarg, "red") == 0)
                                        b = BG_RED;
                                else if (strcmp (optarg, "green") == 0)
                                        b = BG_GREEN;
                                else if (strcmp (optarg, "yellow") == 0)
                                        b = BG_YELLOW;
                                else if (strcmp (optarg, "blue") == 0)
                                        b = BG_BLUE;
                                else if (strcmp (optarg, "magenta") == 0)
                                        b = BG_MAGENTA;
                                else if (strcmp (optarg, "cyan") == 0)
                                        b = BG_CYAN;
                                else if (strcmp (optarg, "white") == 0)
                                        b = BG_WHITE;
                                else if (strcmp (optarg, "white") == 0)
                                        b = BG_WHITE;
                                break;
                        case 'm':
                                message = optarg;
                                break;
                        case '?':
                                break;
                        default:
                                abort ();
                }
        }

        printf ("\033[%d;%dm", f, b);
        printf ("%s\n", message);
        printf ("\033[0m"); /* reset to normal */

        return 0;
}
