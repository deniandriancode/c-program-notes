#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *square (void *);
int accum = 0;
pthread_mutex_t accum_mutex = PTHREAD_MUTEX_INITIALIZER;

int
main (int argc, char *argv[])
{
        int i ;
        pthread_t ths[20];
        for (i = 0; i < 20; i++) {
                pthread_create (&ths[i], NULL, square, (void *)(i + 1));
        }

        for (i = 0; i < 20; i++) {
                void *res;
                pthread_join (ths[i], &res);
        }

        printf ("accum : %d\n", accum);

        return 0;
}

void*
square (void *x)
{
        int xi = (int) x;
        int temp = xi * xi;

        pthread_mutex_lock (&accum_mutex);
        accum += temp;
        pthread_mutex_unlock (&accum_mutex);

        return NULL;
}
