/*
 * Kruskal Minimum Spanning Tree
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent[1024];
    int rank[1024];
} DSU;

void dsu_init(DSU* dsu, int n) {
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

int dsu_find(DSU* dsu, int i) {
    if (dsu->parent[i] == i) return i;
    return dsu->parent[i] = dsu_find(dsu, dsu->parent[i]);
}

void dsu_union(DSU* dsu, int x, int y) {
    int root_x = dsu_find(dsu, x);
    int root_y = dsu_find(dsu, y);
    if (root_x != root_y) {
        if (dsu->rank[root_x] < dsu->rank[root_y]) {
            dsu->parent[root_x] = root_y;
        } else if (dsu->rank[root_x] > dsu->rank[root_y]) {
            dsu->parent[root_y] = root_x;
        } else {
            dsu->parent[root_y] = root_x;
            dsu->rank[root_x]++;
        }
    }
}
