#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int
main (int argc, char **argv)
{
        int west = 0;
        int east = 0;
        char *name = NULL;
        int c;

        opterr = 0;

        while ((c = getopt (argc, argv, "we:n:")) != -1) {
                if (c == '?') {
                        switch (optopt) {
                                case 'w':
                                        west = 1;
                                        break;
                                case 'e':
                                        east = 1;
                                        break;
                                default:
                                        abort ();
                        }
                } else if (c == 'n') {
                        name = optarg;
                }
        }

        printf ("Hello everybody my name is %s\n", name);
        if (east)
                printf ("The person is in the East side of the store.\n");
        else if (west)
                printf ("The person is in the West side of the store.\n");

        return 0;
}
