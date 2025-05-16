#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST and total weight
void printMST(int parent[], int graph[V][V]) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];  // Add weight of edge to total weight
    }
    printf("Total weight of MST: %d\n", totalWeight);  // Print total weight
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];     // Stores MST
    int key[V];        // Minimum weight edge
    bool mstSet[V];    // Included in MST?

    // Initialize keys and MST set
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // Pick the minimum key vertex not in MST
        mstSet[u] = true;             // Add it to the MST

        // Update the key and parent values for the adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    primMST(graph);

    return 0;
}
