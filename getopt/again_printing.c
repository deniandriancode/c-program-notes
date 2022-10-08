#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int
main (int argc, char **argv)
{
        int left = 0;
        int right = 0;
        int c;

        opterr = 0;
        while ((c = getopt (argc, argv, "lr")) != -1) {
                switch (c) {
                        case 'l':
                                left = 1;
                                break;
                        case 'r':
                                right = 1;
                                break;
                        case '?':
                                return 1;
                        default:
                                abort ();
                }
        }

        if (left)
                printf ("Left side\n");
        if (right)
                printf ("Right side\n");

        return 0;
}
