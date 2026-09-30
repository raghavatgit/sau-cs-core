/* SPLAY_TREE Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} splay_tree_t;

splay_tree_t* splay_tree_create(size_t cap) {
    splay_tree_t *s = malloc(sizeof(splay_tree_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void splay_tree_free(splay_tree_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    splay_tree_t *inst = splay_tree_create(16);
    if (inst) {
        printf("splay_tree initialized successfully.\n");
        splay_tree_free(inst);
    }
    return 0;
}
