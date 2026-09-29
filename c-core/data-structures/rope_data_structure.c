#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RopeNode {
    struct RopeNode *left, *right;
    char *str;
    int weight;
} RopeNode;

RopeNode* create_rope_leaf(const char* s) {
    RopeNode* node = (RopeNode*)malloc(sizeof(RopeNode));
    node->str = strdup(s);
    node->weight = strlen(s);
    node->left = node->right = NULL;
    return node;
}
