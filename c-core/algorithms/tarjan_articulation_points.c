#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1024

int adj[MAX_NODES][MAX_NODES];
int adj_size[MAX_NODES];
int disc[MAX_NODES];
int low[MAX_NODES];
int visited[MAX_NODES];
int is_articulation[MAX_NODES];
int timer = 0;

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int i = 0; i < adj_size[u]; i++) {
        int v = adj[u][i];
        if (v == parent) continue;
        if (visited[v]) {
            if (disc[v] < low[u]) low[u] = disc[v];
        } else {
            children++;
            dfs(v, u);
            if (low[v] < low[u]) low[u] = low[v];
            if (parent != -1 && low[v] >= disc[u]) is_articulation[u] = 1;
        }
    }
    if (parent == -1 && children > 1) is_articulation[u] = 1;
}
