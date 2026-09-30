/* RADIX_SORT_LSD Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} radix_sort_lsd_t;

radix_sort_lsd_t* radix_sort_lsd_create(size_t cap) {
    radix_sort_lsd_t *s = malloc(sizeof(radix_sort_lsd_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void radix_sort_lsd_free(radix_sort_lsd_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    radix_sort_lsd_t *inst = radix_sort_lsd_create(16);
    if (inst) {
        printf("radix_sort_lsd initialized successfully.\n");
        radix_sort_lsd_free(inst);
    }
    return 0;
}
