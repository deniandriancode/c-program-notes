#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue*, int);
int dequeue(Queue*);
int isEmpty(Queue*);
int isFull(Queue*);
int peek(Queue*);
void display(Queue*);

int count = -1;

void enqueue(Queue *q, int item) {
    if (!isFull(q)) {
        q->items[++count] = item;
        if (isEmpty(q)) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear++;
        }
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        q->front++;
        count--;
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        }
    }
}

int peek(Queue *q) {
    return q->items[q->front];
}

int isEmpty(Queue *q) {
    if (q->rear == -1 && q->front == -1) {
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

int isFull(Queue *q) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

void display(Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
}

int main(int argc, char *argv[]) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    enqueue(q, 11);
    enqueue(q, 21);
    enqueue(q, 56);
    enqueue(q, 47);
    enqueue(q, 28);
    enqueue(q, 97);
    dequeue(q);
    display(q);
    printf("\n");
    return 0;
}
