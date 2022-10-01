#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
        pid_t pid = fork ();
        if (pid < 0) {
                fprintf (stderr, "Fork failed\n");
                return 1;
        } else if (pid == 0) {
                printf ("I'm the child\n");
        } else {
                wait (NULL);
                printf ("Child complete\n");
        }

        printf ("Hello World\n");
        
        return 0;
}
