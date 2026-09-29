#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tree;
    int size;
} FenwickTree;

FenwickTree* create_fenwick_tree(int n) {
    FenwickTree *ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->tree = (int*)calloc(n + 1, sizeof(int));
    ft->size = n;
    return ft;
}

void fenwick_update(FenwickTree *ft, int i, int delta) {
    while (i <= ft->size) {
        ft->tree[i] += delta;
        i += i & (-i);
    }
}

int fenwick_query(FenwickTree *ft, int i) {
    int sum = 0;
    while (i > 0) {
        sum += ft->tree[i];
        i -= i & (-i);
    }
    return sum;
}
