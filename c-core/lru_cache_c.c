/*
 * LRU Cache in Pure C99
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct LRUNode {
    int key;
    int value;
    struct LRUNode* prev;
    struct LRUNode* next;
} LRUNode;

typedef struct {
    int capacity;
    int count;
    LRUNode* head;
    LRUNode* tail;
} LRUCacheC;
