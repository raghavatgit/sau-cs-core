/*
 * Segment Tree with Lazy Propagation
 */
#include <stdio.h>

#define MAX_N 1024
static int tree[MAX_N * 4];
static int lazy[MAX_N * 4];

void push_down(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
