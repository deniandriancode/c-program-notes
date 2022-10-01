#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printLinkedList (struct node *);
void push (struct node *, int);
void prepend (struct node **, int);
int shift (struct node **);
int pop (struct node *);

void
printLinkedList (struct node *p)
{
    while (p != NULL)
    {
        printf ("%d\n", p->data);
        p = p->next;
    }
}

/* add item at the end of the list */
void
push (struct node *head,
      int value)
{
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (struct node *) malloc (sizeof (struct node));
    current->next->data = value;
    current->next->next = NULL;
}

/* add item at the beginning of the list */
void
prepend (struct node **head,
         int value)
{
    struct node *newItem = (struct node *) malloc (sizeof (struct node));
    newItem->data = value;
    newItem->next = *head;
    *head = newItem;
}

/* removing the first item */
int
shift (struct node **head)
{
    int shifted;
    struct node *nextItem = (struct node *) malloc (sizeof (struct node));
    nextItem = (*head)->next;
    shifted = (*head)->data;
    free (*head);
    *head = nextItem;
    return shifted;
}

/* removing the last item */
int
pop (struct node *head)
{
    int poped;
    struct node *current = (struct node *) malloc (sizeof (struct node));
    current = head;
    while (current->next->next != NULL)
    {
        printf ("%d -- ", current->data);
        current = current->next;
    }
    poped = current->next->data;
    free (current->next);
    current->next = NULL;
    return poped;
}

int
main (int argc,
      char **argv)
{
    /* initialize nodes */
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    /* allocate memory */
    one = malloc (sizeof (struct node));
    two = malloc (sizeof (struct node));
    three = malloc (sizeof (struct node));

    /* assign data values */
    one->data = 1;
    two->data = 2;
    three->data = 3;

    /* connect nodes */
    one->next = two;
    two->next = three;
    three->next = NULL;

    /* save the first address in head */
    head = one;

    /*printLinkedList (head);*/
    prepend (&head, 99);
    /*printLinkedList (head);*/
    /*printf ("\n");*/
    int d = shift (&head);
    /*printf ("%d\n\n", d);*/
    push (head, 55);
    pop (head);
    printLinkedList (head);

    return 0;
}
