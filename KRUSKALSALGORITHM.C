#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int parent[MAX];

typedef struct {
    int u, v, w;
} Edge;

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

void kruskal(int V, int E, Edge edges[]) {
    int i, u, v;
    int mincost = 0;

    for (i = 0; i < V; i++) {
        parent[i] = i;
    }

    qsort(edges, E, sizeof(Edge), compare);

    printf("Minimum Spanning Tree Edges:\n");

    for (i = 0; i < E; i++) {
        u = edges[i].u;
        v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d %d %d\n", u + 1, v + 1, edges[i].w); // Adjust vertices to be 1-based
            mincost += edges[i].w;
            union_(u, v);
        }
    }

    printf("Total Weight of the Minimum Spanning Tree: %d\n", mincost);
}

int main() {
    int V, E, i;
    printf("Enter the number of vertices and edges (V E): ");
    scanf("%d %d", &V, &E);

    Edge edges[MAX];

    printf("Enter the edges and weights (u v w) one by one:\n");
    for (i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--; // Adjust vertices to be 0-based
        edges[i].v--;
    }

    kruskal(V, E, edges);

    return 0;
}
