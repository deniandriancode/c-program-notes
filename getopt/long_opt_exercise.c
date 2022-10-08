#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int is_verbose;

int
main (int argc, char **argv)
{
        char *message = "nomsg";
        int ch;

        while (1) {
                static struct option long_options[] = {
                        {"verbose", no_argument, &is_verbose, 1},
                        {"quiet", no_argument, &is_verbose, 0},
                        {"say", required_argument, 0, 's'},
                        {0, 0, 0, 0}
                };
                int option_index = 0;

                ch = getopt_long (argc, argv, "vqs:", long_options, &option_index);

                if (ch == -1)
                        break;
                switch (ch) {
                        case 's':
                                message = optarg;
                                break;
                }

        }

        printf ("%s\n", message);

        return 0;
}
