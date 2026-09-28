#include <stdio.h>
#include <stdlib.h>

void kahn_topological_sort(int n, int adj[100][100], int in_degree[100]) {
    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                if (--in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
}
