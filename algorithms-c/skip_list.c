/* SKIP_LIST Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} skip_list_t;

skip_list_t* skip_list_create(size_t cap) {
    skip_list_t *s = malloc(sizeof(skip_list_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void skip_list_free(skip_list_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    skip_list_t *inst = skip_list_create(16);
    if (inst) {
        printf("skip_list initialized successfully.\n");
        skip_list_free(inst);
    }
    return 0;
}
