#include <stdio.h>
#include <stdlib.h>

typedef struct SplayNode {
    int key;
    struct SplayNode *left, *right;
} SplayNode;
