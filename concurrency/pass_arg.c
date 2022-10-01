#include <stdio.h>
#include <pthread.h>

void *thread_fn (void *);

int
main (int argc, char *argv[])
{
        pthread_t t1, t2;
        int i, j;
        i = 1;
        j = 2;

        pthread_create (&t1, NULL, thread_fn, &i);
        pthread_create (&t2, NULL, thread_fn, &j);

        pthread_join (t1, NULL);
        pthread_join (t2, NULL);

        printf ("In main thread\n");
        
        return 0;
}

void*
thread_fn (void *arg)
{
        printf ("I am thread #%d\n", *(int *)arg);
        return NULL;
}
