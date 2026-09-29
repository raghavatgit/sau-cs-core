/*
 * Kosaraju SCC Two-Pass Algorithm
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX_V 256

static int adj[MAX_V][MAX_V];
static int radj[MAX_V][MAX_V];
static int adj_cnt[MAX_V];
static int radj_cnt[MAX_V];
static bool visited[MAX_V];
static int finish_stack[MAX_V];
static int stack_top = 0;

void dfs_order(int u) {
    visited[u] = true;
    for (int i = 0; i < adj_cnt[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs_order(v);
    }
    finish_stack[stack_top++] = u;
}
