#include <stdio.h>
#include <stdbool.h>

#define V 6

bool bfs_flow(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V] = {false};
    int queue[V];
    int head = 0, tail = 0;
    queue[tail++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[tail++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}
