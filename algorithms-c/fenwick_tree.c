/*
 * Fenwick Tree (Binary Indexed Tree)
 * Point update: O(log n), Range query: O(log n)
 */
#include <stdio.h>

#define BIT_MAX 1024
static int tree[BIT_MAX];

void bit_update(int idx, int delta, int n) {
    for (; idx <= n; idx += idx & -idx) {
        tree[idx] += delta;
    }
}

int bit_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree[idx];
    }
    return sum;
}
