#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) { return (a < b) ? a : b; }

void build_seg_tree(int *arr, int *tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build_seg_tree(arr, tree, 2 * node, start, mid);
    build_seg_tree(arr, tree, 2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
