#include <stdio.h>

#define MAX_N 10000

int parent_node[MAX_N], depth_node[MAX_N], heavy[MAX_N], head[MAX_N], pos[MAX_N];
int cur_pos = 0;

int dfs_hld(int v, int p, int d, int adj_sz[], int adj[][100]) {
    int size = 1;
    int max_c_size = 0;
    parent_node[v] = p;
    depth_node[v] = d;
    heavy[v] = -1;
    for (int i = 0; i < adj_sz[v]; i++) {
        int c = adj[v][i];
        if (c != p) {
            int c_size = dfs_hld(c, v, d + 1, adj_sz, adj);
            size += c_size;
            if (c_size > max_c_size) {
                max_c_size = c_size;
                heavy[v] = c;
            }
        }
    }
    return size;
}
