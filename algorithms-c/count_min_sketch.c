/* COUNT_MIN_SKETCH Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} count_min_sketch_t;

count_min_sketch_t* count_min_sketch_create(size_t cap) {
    count_min_sketch_t *s = malloc(sizeof(count_min_sketch_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void count_min_sketch_free(count_min_sketch_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    count_min_sketch_t *inst = count_min_sketch_create(16);
    if (inst) {
        printf("count_min_sketch initialized successfully.\n");
        count_min_sketch_free(inst);
    }
    return 0;
}
