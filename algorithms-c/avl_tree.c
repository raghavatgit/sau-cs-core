/*
 * AVL Tree Balance Rotations
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

static int height(AVLNode* n) {
    return n ? n->height : 0;
}

static int max_val(int a, int b) {
    return a > b ? a : b;
}

AVLNode* right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max_val(height(y->left), height(y->right)) + 1;
    x->height = max_val(height(x->left), height(x->right)) + 1;
    return x;
}
