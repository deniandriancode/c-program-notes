#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct set {
    int key;
    int data;
};

void init ();
int hash_function (int);
void display (struct set *);
void insert (struct set *, int, int);
int remove_element (struct set *, int);

struct set *hashtable;

/* initialize hashtable */
void
init ()
{
    hashtable = (struct set *) malloc (SIZE * sizeof (struct set));
    int i;
    for (i = 0; i < SIZE; i++)
    {
        hashtable[i].key = 0;
        hashtable[i].data = 0;
    }
}

/* hash function */
int
hash_function (int key)
{
    return (key % SIZE);
}

/* print the hashtable */
void
display (struct set *hashtable_i)
{
    int i;
    printf ("Start\n");
    for (i = 0; i < SIZE; i++)
    {
        printf ("%d -> %d\n", hashtable_i[i].key, hashtable_i[i].data);
    }
    printf ("End\n\n");
}

/* insert an element */
void
insert (struct set *hashtable_i, int key, int data)
{
    int index = hash_function (key);
    if (hashtable_i[index].data == 0)
    {
        hashtable_i[index].key = key;
        hashtable_i[index].data = data;
    }
    else if (hashtable_i[index].key == key)
        hashtable_i[index].data = data;
}

/* remove an element */
int
remove_element (struct set *hashtable_i, int key)
{
    int index = hash_function (key);
    int result;
    if (hashtable_i[index].data == 0)
        printf ("%d does not exists\n");
    else
    {
        result = hashtable_i[index].data;
        hashtable_i[index].key = 0;
        hashtable_i[index].data = 0;
    }
    return result;
}

/* main driver function */
void
hashtable_demo ()
{
    init ();
    display (hashtable);
    insert (hashtable, 1, 100);
    insert (hashtable, 2, 200);
    insert (hashtable, 3, 300);
    insert (hashtable, 4, 400);
    display (hashtable);
    remove_element (hashtable, 1);
    display (hashtable);
}
