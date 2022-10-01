#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *thread_fn (void *);

int
main (int argc, char *argv[])
{
        pthread_t thread;
        int create_err = pthread_create (&thread, NULL, thread_fn, NULL);
        if (!create_err) {
                pthread_join (thread, NULL);
                return 0;
        }
        fprintf ("%s\n", strerror (create_err), stderr);
        return 1;
}

void*
thread_fn (void *arg)
{
        printf ("Hello world\n");
        return 0;
}
