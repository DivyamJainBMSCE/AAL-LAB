#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7  // Number of edges

// Edge structure
struct Edge {
    int src, dest, weight;
};

// Graph with E edges
struct Graph {
    struct Edge edge[E];
};

int parent[V];

// Find set of an element i (basic find without path compression)
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
void unionSet(int u, int v) {
    int uroot = find(u);
    int vroot = find(v);
    parent[uroot] = vroot;
}

// Compare edges by weight for qsort
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    struct Edge result[V];  // Store MST result
    int e = 0;              // Edge count in result
    int i = 0;

    // Initialize disjoint sets
    for (int v = 0; v < V; v++)
        parent[v] = v;

    // Sort edges by weight
    qsort(graph->edge, E, sizeof(graph->edge[0]), compareEdges);

    while (e < V - 1 && i < E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(x, y);
        }
    }

    // Print MST
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

// Main function
int main() {
    struct Graph graph;

    // Sample graph edges (src, dest, weight)
    graph.edge[0] = (struct Edge){0, 1, 10};
    graph.edge[1] = (struct Edge){0, 2, 6};
    graph.edge[2] = (struct Edge){0, 3, 5};
    graph.edge[3] = (struct Edge){1, 3, 15};
    graph.edge[4] = (struct Edge){2, 3, 4};
    graph.edge[5] = (struct Edge){1, 2, 25};
    graph.edge[6] = (struct Edge){3, 4, 2};

    printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");
    kruskalMST(&graph);

    return 0;
}
