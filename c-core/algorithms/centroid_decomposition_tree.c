#include <stdio.h>

#define MAX_V 10000

int sz[MAX_V];
int removed[MAX_V];

void get_subtree_sizes(int v, int p, int adj_sz[], int adj[][100]) {
    sz[v] = 1;
    for (int i = 0; i < adj_sz[v]; i++) {
        int to = adj[v][i];
        if (to != p && !removed[to]) {
            get_subtree_sizes(to, v, adj_sz, adj);
            sz[v] += sz[to];
        }
    }
}
