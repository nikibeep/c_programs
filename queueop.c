#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int front, rear, size;
    int elements[MAX_SIZE];
};

void enqueue(struct Queue *q, int x) {
    if (q->size == MAX_SIZE) {
        printf("Error: Queue is full\n");
        return;
    }
    q->elements[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

int dequeue(struct Queue *q) {
    if (q->size == 0) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int x = q->elements[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return x;
}

int main() {
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 0;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeued item: %d\n", dequeue(&q));
    printf("Dequeued item: %d\n", dequeue(&q));
    return 0;
}