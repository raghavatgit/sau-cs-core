/* BLOOM_FILTER Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} bloom_filter_t;

bloom_filter_t* bloom_filter_create(size_t cap) {
    bloom_filter_t *s = malloc(sizeof(bloom_filter_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void bloom_filter_free(bloom_filter_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    bloom_filter_t *inst = bloom_filter_create(16);
    if (inst) {
        printf("bloom_filter initialized successfully.\n");
        bloom_filter_free(inst);
    }
    return 0;
}
