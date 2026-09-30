/* INTROSORT Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} introsort_t;

introsort_t* introsort_create(size_t cap) {
    introsort_t *s = malloc(sizeof(introsort_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void introsort_free(introsort_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    introsort_t *inst = introsort_create(16);
    if (inst) {
        printf("introsort initialized successfully.\n");
        introsort_free(inst);
    }
    return 0;
}
