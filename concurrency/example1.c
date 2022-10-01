#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_fn (void *);

int
main (int argc, char *argv[])
{
        pthread_t threads[4];
        int id1 = 1;
        int id2 = 2;
        int id3 = 3;
        int id4 = 4;

        int i;

        for (i = 0; i < 4; i++) {
                pthread_create (&threads[i], NULL, thread_fn, &i);
        }

        pthread_join (threads[2], NULL);
        pthread_join (threads[0], NULL);
        pthread_join (threads[1], NULL);
        pthread_join (threads[3], NULL);

        printf ("Main thread\n");

        return 0;
}

void*
thread_fn (void *args_th)
{
        int *args_int = (int *) args_th;
        printf ("Thread number %d\n", *args_int);

        return NULL;
}
