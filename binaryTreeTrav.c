#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new binary tree node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function for inorder tree traversal
void inorder(struct node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Function for preorder tree traversal
void preorder(struct node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Function for postorder tree traversal
void postorder(struct node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    // Create the root node
    int data;
    printf("Enter the data for root node: ");
    scanf("%d", &data);
    struct node* root = newNode(data);

    // Ask the user to add more nodes
    char ch;
    do {
        printf("Do you want to add more nodes (y/n)? ");
        scanf(" %c", &ch);
        if (ch == 'y') {
            printf("Enter the data: ");
            scanf("%d", &data);

            // Traverse the tree to find the appropriate position to insert the new node
            struct node* current = root;
            while (1) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = newNode(data);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = newNode(data);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    } while (ch == 'y');

    // Perform inorder traversal of the tree
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Perform preorder traversal of the tree
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Perform postorder traversal of the tree
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
