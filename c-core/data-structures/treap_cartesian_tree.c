#include <stdio.h>
#include <stdlib.h>

typedef struct TreapNode {
    int key;
    int priority;
    struct TreapNode *left, *right;
} TreapNode;

TreapNode* new_treap_node(int key) {
    TreapNode *node = (TreapNode*)malloc(sizeof(TreapNode));
    node->key = key;
    node->priority = rand();
    node->left = node->right = NULL;
    return node;
}
