#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 26

int matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void enqueue(Queue* q, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    int data = q->front->data;
    QueueNode* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

void push(Stack* s, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top;

    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        return -1;
    }

    int data = s->top->data;
    StackNode* temp = s->top;

    s->top = s->top->next;

    free(temp);
    return data;
}

int isStackEmpty(Stack* s) {
    return (s->top == NULL);
}

void bfs(int start) {
    Queue q = { NULL, NULL };

    visited[start] = 1;
    printf("Traversal order: %c ", start + 'A');
    enqueue(&q, start);

    while (!isQueueEmpty(&q)) {
        int v = dequeue(&q);

        for (int i = 0; i < n; i++) {
            if (matrix[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%c ", i + 'A');
                enqueue(&q, i);
            }
        }
    }

    // Display traversed vertices alphabetically
    printf("\nTraversed vertices alphabetically: ");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            printf("%c ", i + 'A');
        }
    }
}

void dfs(int start) {
    Stack s = { NULL };

    visited[start] = 1;
    printf("Traversal order: %c ", start + 'A');
    push(&s, start);

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

// Display traversed vertices alphabetically
printf("\nTraversed vertices alphabetically: ");
for (int i = 0; i < n; i++) {
    if (visited[i] == 1) {
        printf("%c ", i + 'A');
    }
}
}

int main() {
int choice, start;
char vertex;
printf("Enter the number of vertices: ");
scanf("%d", &n);

printf("Enter the adjacency matrix:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
    }
}
//print the adjacency matrix
printf("The adjacency matrix is:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}


while (1) {
    printf("\n1. Breadth First Search (BFS)\n2. Depth First Search (DFS)\n3. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 3) {
        break;
    }

    printf("Enter starting vertex (A-%c): ", 'A' + n - 1);
    scanf(" %c", &vertex);

    start = vertex - 'A';
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    if (choice == 1) {
        bfs(start);
    }
    else if (choice == 2) {
        dfs(start);
    }
    else {
        printf("Invalid choice\n");
    }
}

return 0;
}