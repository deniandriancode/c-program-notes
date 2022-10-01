#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int empty(Queue *q);

void enqueue(Queue *q, int i) {
    Node *temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->item = i;
    temp->next = NULL;
    if (empty(q) != 0) {
        q->rear->next = temp;
    }
    else {
        q->front = temp;
    }
    q->rear = temp;
}

int dequeue(Queue *q) {
    int temp = -999;
    Node *temp2;
    if (empty(q) != 0) {
        temp = q->front->item;
        temp2 = q->front;
        q->front = q->front->next;
        free(temp2);
        if (q->front == NULL) q->rear = NULL;
    }
    else printf("ERROR, Queue empty, cannot dequeue\n");
    return temp;
}

int empty(Queue *q) {
    if (q->front == NULL) return 0;
    else return 1;
}

int main(int argc, char *argv[]) {
    Queue *q;
    int i;
    q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;

    for (i = 0; i < 10; i++) {
        enqueue(q, i);
    }
    while (empty(q) != 0) {
        i = dequeue(q);
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
