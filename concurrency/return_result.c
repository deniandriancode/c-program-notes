#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_args {
        int a;
        double b;
};

struct thread_result {
        long x;
        double y;
};

void *thread_fn (void *);

int
main (int argc, char *argv[])
{
        pthread_t thread_raw;
        struct thread_args in = { .a = 10, .b = 3.141592653 };
        void *out_void;
        struct thread_result *out;

        pthread_create (&thread_raw, NULL, thread_fn, &in);
        pthread_join (thread_raw, &out_void);
        out = (struct thread_result *) out_void;
        printf("out -> x = %ld\tout -> b = %f\n", out->x, out->y);
        free (out);

        return 0;
}

void*
thread_fn (void *args_void)
{
        struct thread_args *args = args_void;
        struct thread_result *res = malloc (sizeof (struct thread_result *));

        res->x = 10 + args->a;
        res->y = args->a * args->b;

        return res;
}
