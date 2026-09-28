#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
    size_t size;
} DoublyList;

DoublyList* create_list() {
    DoublyList *list = (DoublyList*)malloc(sizeof(DoublyList));
    list->head = (DNode*)malloc(sizeof(DNode));
    list->tail = (DNode*)malloc(sizeof(DNode));
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->head->prev = NULL;
    list->tail->next = NULL;
    list->size = 0;
    return list;
}

void list_push_back(DoublyList *list, int val) {
    DNode *node = (DNode*)malloc(sizeof(DNode));
    node->data = val;
    node->prev = list->tail->prev;
    node->next = list->tail;
    list->tail->prev->next = node;
    list->tail->prev = node;
    list->size++;
}
