#include <stdio.h>

int
main (int argc, char *argv[])
{
        FILE *fp;
        int content;
        int i;
        fp = fopen ("myfile.txt", "r");
        if (!fp)
                return 1;

        while ((content = fgetc (fp)) != EOF) {
                printf ("%c", content);
        }
        printf ("\n");

        fclose (fp);

        return 0;
}
