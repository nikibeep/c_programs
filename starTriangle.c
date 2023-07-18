#include <stdio.h>

int main() {
    int height, i, j, k;

    printf("Enter the height of the triangle: ");
    scanf("%d", &height);

    for (i = 1; i <= height; i++) {
        // Print spaces
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }

        // Print asterisks
        for (k = 1; k <= i; k++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
