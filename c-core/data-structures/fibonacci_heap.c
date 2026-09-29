#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct FibNode {
    int key;
    int degree;
    bool marked;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
} FibNode;

typedef struct {
    FibNode *min;
    int n;
} FibHeap;
