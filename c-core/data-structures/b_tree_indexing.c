#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 3 // Minimum degree (order)

typedef struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode *children[2 * T];
    int num_keys;
    bool is_leaf;
} BTreeNode;

BTreeNode* create_btree_node(bool is_leaf) {
    BTreeNode *node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->is_leaf = is_leaf;
    node->num_keys = 0;
    for (int i = 0; i < 2 * T; i++) node->children[i] = NULL;
    return node;
}

void split_child(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *z = create_btree_node(child->is_leaf);
    z->num_keys = T - 1;

    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = child->keys[j + T];
    }

    if (!child->is_leaf) {
        for (int j = 0; j < T; j++) {
            z->children[j] = child->children[j + T];
        }
    }

    child->num_keys = T - 1;

    for (int j = parent->num_keys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = z;

    for (int j = parent->num_keys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[T - 1];
    parent->num_keys++;
}
