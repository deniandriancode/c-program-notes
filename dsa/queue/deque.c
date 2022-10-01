#include <stdio.h>

#define MAX 10

void addFront (int *, int, int *, int *);
void addRear (int *, int, int *, int *);
int delFront (int *, int *, int *);
int delRear (int *, int *, int *);
void display (int *);
int count (int *);
int isfull (int *, int *);
int isempty (int *, int *);

int
main (int argc,
      char **argv)
{
    /* Types of Deque
     * 1. input restricted deque
     * 2. output restricted deque*/
    return 0;
}

void
addFront (int *arr,
          int value,
          int *front,
          int *rear)
{
    int i, c, k;
    if (isfull (front, rear))
        return;

    if (*front == -1)
    {
        *front = *rear = 0;
        arr[*front] = value;
        return;
    }

    if (*rear != MAX - 1)
    {
        c = count (arr);
        k = *rear + 1;
        for (i = 1; i <= c; i++)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = value;
        *front = k;
        (*rear)++;
    }
    else
    {
        (*front)--;
        arr[*front] = value;
    }
}

void
addRear (int *arr,
         int value,
         int *front,
         int *rear)
{
    int i, k;
    
    if (isfull (front, rear))
        return;

    if (*rear == -1)
    {
        *front = *rear = 0;
        (*rear)++;
        arr[*rear] = value;
    }
    
    if (*rear == MAX - 1)
    {
        for (i = *front - 1; i < *rear; i++)
        {
            k = i;
            if (i == MAX - 1)
                arr[k] = 0;
            else
                arr[k] = arr[i + 1];
        }
        (*front)--;
        (*rear)--;
    }
    (*rear)++;
    arr[*rear] = value;
}

int
delFront (int *arr,
          int *front,
          int *rear)
{
    if (isempty (front, rear))
        return 0;

    int item = arr[*front];
    arr[*front] = 0;

    if (*front == *rear)
        *front = *rear = -1;
    else
        (*front)++;

    return item;
}

int delRear (int *arr,
             int *front,
             int *rear)
{
    if (isempty (front, rear))
        return 0;

    int item = arr[*rear];
    arr[*rear] = 0;
    
    if (*front == *rear)
        *front = *rear = -1;
    else
        (*rear)--;

    return item;
}

void
display (int *arr)
{
    int i;

    printf("\n front: ");
    for (i = 0; i < MAX; i++)
    {
        printf(" %d", arr[i]);
    }
    printf(" :rear\n");
}

int
count (int *arr)
{
    int c = 0, i;

    for (i = 0; i < MAX; i++)
    {
        if (arr[i] != 0)
            c++;
    }
    return c;
}

int
isfull (int *front, int *rear)
{
    if (*front == 0 && *rear == MAX - 1)
    {
        printf ("Deque is full\n");
        return 1;
    }
    return 0;
}

int
isempty (int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf ("Deque is empty\n");
        return 1;
    }
    else if (*front == *rear)
    {
        printf ("Deque is empty\n");
        return 1;
    }
    return 0;
}
