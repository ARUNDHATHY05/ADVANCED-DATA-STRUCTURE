#include <stdio.h>
#include <limits.h>

#define MAX 20

void prim(int n, int cost[MAX][MAX], int t[MAX - 1][2], int* totalCost) {
    int near[MAX];
    int min, u, v;

    // Initialize near array and t array
    for (int i = 1; i < n; i++) {
        near[i] = 0;
    }

    // Start with the first vertex
    near[0] = 1;

    // Initialize totalCost
    *totalCost = 0;

    // Loop through n-1 times to find n-1 edges
    for (int i = 1; i < n; i++) {
        // Find the minimum cost edge
        min = INT_MAX;
        u = v = -1;  // Initialize u and v to invalid values

        for (int j = 0; j < n; j++) {
            if (near[j] != 0) {
                for (int k = 0; k < n; k++) {
                    if (near[k] == 0 && cost[j][k] != 0 && cost[j][k] < min) {
                        u = j;
                        v = k;
                        min = cost[j][k];
                    }
                }
            }
        }

        // If u and v are still invalid, no valid edge is found
        if (u == -1 || v == -1) {
            break;
        }

        // Store the edge in the result array t
        t[i - 1][0] = u;
        t[i - 1][1] = v;
        near[v] = 1;

        // Update totalCost
        *totalCost += min;
    }
}

int main() {
    int n, cost[MAX][MAX], t[MAX - 1][2], totalCost;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;  // Replace 0 with INT_MAX for non-existent edges
            }
        }
    }

    // Call the Prim's algorithm function
    prim(n, cost, t, &totalCost);

    // Display the minimum spanning tree
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0] + 1, t[i][1] + 1);
    }

    // Display the total minimum cost
    printf("Total Minimum Cost: %d\n", totalCost);

    return 0;
}
