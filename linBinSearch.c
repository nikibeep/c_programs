#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int linSearch(int a[], int n, int key);
int binSearch(int a[], int n, int key);

int main() {
    // Randomly generate an array of size n
    int n = 10;
    int a[n];
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    // Sort the array
    int j;
    int temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    //print sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Menu driven program
    int choice;
    int key;
    int index;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search    2. Binary Search    3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                index = linSearch(a, n, key);
                if (index == -1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n", index);
                break;
            case 2:
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                index = binSearch(a, n, key);
                if (index == -1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n", index);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Linear search function
int linSearch(int a[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Step %d: Checking element a[%d] = %d\n", i+1, i, a[i]);
        if (a[i] == key) {
            printf("Step %d: Found key %d at index %d\n", i+1, key, i);
            return i;
        }
    }
    printf("Key not found\n");
    return -1;
}

// Binary search function
int binSearch(int a[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int mid;
    int steps = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        steps++;
        printf("Step %d: Checking element a[%d] = %d\n", steps, mid, a[mid]);
        if (a[mid] == key) {
            printf("Step %d: Found key %d at index %d\n", steps, key, mid);
            return mid;
        }
        else if (a[mid] < key) {
            low = mid + 1;
            printf("Step %d: Key %d is greater than element a[%d] = %d, moving to the right\n", steps, key, mid, a[mid]);
        }
        else {
            high = mid - 1;
            printf("Step %d: Key %d is less than element a[%d] = %d, moving to the left\n", steps, key, mid, a[mid]);
        }
    }
    printf("Key not found\n");
    return -1;
}
