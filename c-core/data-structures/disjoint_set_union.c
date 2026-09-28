#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int count;
} DSU;

DSU* dsu_create(int n) {
    DSU *dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->rank = (int*)malloc(n * sizeof(int));
    dsu->count = n;
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
    return dsu;
}

int dsu_find(DSU *dsu, int i) {
    if (dsu->parent[i] != i) {
        dsu->parent[i] = dsu_find(dsu, dsu->parent[i]);
    }
    return dsu->parent[i];
}

void dsu_union(DSU *dsu, int x, int y) {
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
        dsu->count--;
    }
}
