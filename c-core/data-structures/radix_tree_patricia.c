#include <stdio.h>
#include <stdlib.h>

typedef struct PatriciaNode {
    int bit_index;
    unsigned int key;
    struct PatriciaNode *left, *right;
} PatriciaNode;
