/* FIBONACCI_HEAP Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} fibonacci_heap_t;

fibonacci_heap_t* fibonacci_heap_create(size_t cap) {
    fibonacci_heap_t *s = malloc(sizeof(fibonacci_heap_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void fibonacci_heap_free(fibonacci_heap_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    fibonacci_heap_t *inst = fibonacci_heap_create(16);
    if (inst) {
        printf("fibonacci_heap initialized successfully.\n");
        fibonacci_heap_free(inst);
    }
    return 0;
}
