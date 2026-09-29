#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define V 6

bool dfs_flow(int rGraph[V][V], int s, int t, bool visited[], int parent[]) {
    visited[s] = true;
    if (s == t) return true;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            parent[v] = s;
            if (dfs_flow(rGraph, v, t, visited, parent)) return true;
        }
    }
    return false;
}
