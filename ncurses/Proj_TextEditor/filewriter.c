#include <stdio.h>

int
main (int argc, char *argv[])
{
        FILE *fp;
        int x;
        fp = fopen ("myfile.txt", "a");
        if (!fp)
                return 1;

        for (x = 0; x < 10; x++)
                fprintf (fp, "%d", x);

        fclose (fp);

        return 0;
}
