#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue data structure
typedef struct queue {
    int items[MAX];
    int front;
    int rear;
} queue;

// Stack data structure
typedef struct stack {
    int items[MAX];
    int top;
} stack;

// Matrix data structure
int matrix[MAX][MAX];
int visited[MAX];
int n;

// Queue operations
void createQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Stack operations
void createStack(stack *s) {
    s->top = -1;
}

int isStackEmpty(stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s, int value) {
    if (s->top == MAX - 1)
        printf("Stack is full\n");
    else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(stack *s) {
    int item;
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        item = -1;
    } else {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}

// Breadth First Search (BFS)
void bfs(int vertex) {
    queue q;
    createQueue(&q);

    visited[vertex] = 1;
    printf("%c ", vertex + 'A');

    enqueue(&q, vertex);

    while (!isEmpty(&q)) {
        int v = dequeue(&q);

        for (int i = 0; i < n; i++) {
            if (matrix[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%c ", i + 'A');
                enqueue(&q, i);
            }
        }
    }
}

// Depth First Search (DFS)
void dfs(int vertex) {
    stack s;
    createStack(&s);

    visited[vertex] = 1;
    printf("%c ", vertex + 'A');

    push(&s, vertex);

    while (!isStackEmpty(&s)) {
        int v = pop(&s);

        for (int i = 0; i < n; i++) {
            if (matrix[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%c ", i + 'A');
                push(&s, i);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input matrix
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
    }
}

// Display matrix
printf("The adjacency matrix is:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}

// Display BFS and DFS traversal
printf("Enter the starting vertex for traversal: ");
int vertex;
scanf("%d", &vertex);

// Initialize visited array to 0
for (int i = 0; i < n; i++) {
    visited[i] = 0;
}

printf("BFS traversal: ");
bfs(vertex);
printf("\n");

// Reset visited array to 0
for (int i = 0; i < n; i++) {
    visited[i] = 0;
}

printf("DFS traversal: ");
dfs(vertex);
printf("\n");

return 0;
}
