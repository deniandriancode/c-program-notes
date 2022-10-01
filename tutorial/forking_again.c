#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void do_work ();

int
main (int argc, char *argv[])
{
        do_work ();
        wait (NULL);
        printf ("Main function\n");
        return 0;
}

void
do_work ()
{
        pid_t pid = fork ();
        if (pid < 0) {
                fprintf (stderr, "Fork failed\n");
                exit (1);
        } else if (pid == 0) {
                printf ("Child here\n");
        } else if (pid == 1) {
                printf ("Parent here\n");
        }
}
