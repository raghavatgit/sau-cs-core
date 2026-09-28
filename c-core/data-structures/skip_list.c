#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 6
#define PROBABILITY 0.5

typedef struct SkipNode {
    int key;
    struct SkipNode **forward;
} SkipNode;

typedef struct {
    int level;
    SkipNode *header;
} SkipList;

SkipNode* create_skip_node(int level, int key) {
    SkipNode *node = (SkipNode*)malloc(sizeof(SkipNode));
    node->key = key;
    node->forward = (SkipNode**)malloc(sizeof(SkipNode*) * (level + 1));
    for (int i = 0; i <= level; i++) node->forward[i] = NULL;
    return node;
}

SkipList* create_skip_list() {
    SkipList *list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = create_skip_node(MAX_LEVEL, INT_MIN);
    return list;
}
