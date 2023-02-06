#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
  int top;
  int data[MAX_SIZE];
};

void push(struct Stack *s, int item) {
  if (s->top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  s->data[++s->top] = item;
}

int pop(struct Stack *s) {
  if (s->top == -1) {
    printf("Stack Underflow\n");
    return -1;
  }
  return s->data[s->top--];
}

int is_empty(struct Stack *s) {
  return s->top == -1;
}

struct Queue {
  struct Stack *stack1;
  struct Stack *stack2;
};

void enqueue(struct Queue *q, int item) {
  push(q->stack1, item);
}

int dequeue(struct Queue *q) {
  if (is_empty(q->stack2)) {
    while (!is_empty(q->stack1)) {
      push(q->stack2, pop(q->stack1));
    }
  }
  return pop(q->stack2);
}

int main() {
  struct Stack *stack1 = (struct Stack *)malloc(sizeof(struct Stack));
  stack1->top = -1;
  struct Stack *stack2 = (struct Stack *)malloc(sizeof(struct Stack));
  stack2->top = -1;
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->stack1 = stack1;
  queue->stack2 = stack2;
  
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  
  free(stack1);
  free(stack2);
  free(queue);
  return 0;
}
