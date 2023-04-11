#include <stdio.h>
#include <stdlib.h>

#define M 3

struct node {
    int n; // number of keys in node
    int keys[M-1]; // array of keys
    struct node *p[M]; // array of pointers to child nodes
};

struct node *root = NULL;

void insert_key(int key);
void split_node(struct node *x, int i);
void insert(struct node *x, int key);
void print_tree(struct node *x, int level);
struct node *new_node();
int search(int key);

int main() {
    int choice, key;

    while(1) {
        printf("\n1. Insert\n2. Search\n3. Print\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert_key(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key))
                    printf("Key found\n");
                else
                    printf("Key not found\n");
                break;
            case 3:
                print_tree(root, 0);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void insert_key(int key) {
    if (root == NULL) {
        root = new_node();
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == M-1) {
            struct node *s = new_node();
            s->p[0] = root;
            split_node(s, 0);
            root = s;
        }
        insert(root, key);
    }
}

void split_node(struct node *x, int i) {
    struct node *z = new_node();
    struct node *y = x->p[i];
    z->n = M/2 - 1;
    for (int j = 0; j < M/2 - 1; j++)
        z->keys[j] = y->keys[j + M/2];
    if (y->p[0]) {
        for (int j = 0; j < M/2; j++)
            z->p[j] = y->p[j + M/2];
    }
    y->n = M/2 - 1;
    for (int j = x->n; j >= i+1; j--)
        x->p[j+1] = x->p[j];
    x->p[i+1] = z;
    for (int j = x->n - 1; j >= i; j--)
        x->keys[j+1] = x->keys[j];
    x->keys[i] = y->keys[M/2 - 1];
    x->n++;
}

void insert(struct node *x, int key) {
    int i = x->n - 1;
    if (x->p[0]) {
        while (i >= 0 && key < x->keys[i])
            i--;
        i++;
        if (x->p[i]->n == M-1) {
            split_node(x, i);
            if (key > x->keys[i])
                i++;
        }
        insert(x->p[i], key);
    } else {
        while (i >= 0 && key < x->keys[i])
            x->keys[i+1] = x->keys[i--];
        x->keys[i+1] = key;
        x->n++;
    }
}

void print_tree(struct node *x, int level) {
    if (x) {
        printf("Level %d: ", level);
        for (int i = 0; i < x->n; i++)
            printf("%d ", x->keys[i]);
        printf("\n");
        for (int i = 0; i <= x->n; i++)
            print_tree(x->p[i], level + 1);
    }
}

struct node *new_node() {
    struct node *x = (struct node *) malloc(sizeof(struct node));
    x->n = 0;
    for (int i = 0; i < M; i++)
        x->p[i] = NULL;
    return x;
}

int search(int key) {
    struct node *x = root;
    int i = 0;
    while (x) {
        while (i < x->n && key > x->keys[i])
            i++;
        if (i < x->n && key == x->keys[i])
            return 1;
        x = x->p[i];
        i = 0;
    }
    return 0;
}