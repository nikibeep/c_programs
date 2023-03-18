#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999999

int num_vertices;
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int mst_array[MAX_VERTICES];

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int min_key(int key[], bool mst_set[]) {
    int min = INF, min_index;
    for (int i = 0; i < num_vertices; i++) {
        if (mst_set[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the MST array by means of vertex name (alphabetical)
void print_mst_array_alphabet() {
    printf("\nMST Array:\n");
    for (int i = 1; i < num_vertices; i++) {
        printf("%c - %c\n", mst_array[i] + 'A', i + 'A');
    }
}

// Function to print the MST array by means of vertex name (numeric)
void print_mst_array_numeric() {
    printf("\nMST Array:\n");
    for (int i = 1; i < num_vertices; i++) {
        printf("%d - %d\n", mst_array[i] + 1, i + 1);
    }
}

// Function to implement Prim's algorithm for finding the minimum spanning tree
void prim_mst(int start_vertex) {
    int key[num_vertices];      // Key values used to pick minimum weight edge in cut
    bool mst_set[num_vertices]; // To represent set of vertices included in MST
    for (int i = 0; i < num_vertices; i++) {
        key[i] = INF;
        mst_set[i] = false;
    }
    key[start_vertex] = 0; // Always include first vertex in MST
    mst_array[0] = -1;     // First node is always root of MST
    for (int i = 0; i < num_vertices - 1; i++) {
        int u = min_key(key, mst_set);
        mst_set[u] = true;
        for (int v = 0; v < num_vertices; v++) {
            if (adjacency_matrix[u][v] && mst_set[v] == false && adjacency_matrix[u][v] < key[v]) {
                mst_array[v] = u;
                key[v] = adjacency_matrix[u][v];
            }
        }
    }
}

// Main function
int main() {
    printf("Enter the number of vertices (maximum 100): ");
    scanf("%d", &num_vertices);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    prim_mst(0);
    print_mst_array_alphabet();
    print_mst_array_numeric();

    return 0;
}
