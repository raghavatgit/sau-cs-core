/* TREAP Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} treap_t;

treap_t* treap_create(size_t cap) {
    treap_t *s = malloc(sizeof(treap_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void treap_free(treap_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    treap_t *inst = treap_create(16);
    if (inst) {
        printf("treap initialized successfully.\n");
        treap_free(inst);
    }
    return 0;
}
