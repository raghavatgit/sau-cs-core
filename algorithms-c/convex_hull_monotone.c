/* CONVEX_HULL_MONOTONE Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} convex_hull_monotone_t;

convex_hull_monotone_t* convex_hull_monotone_create(size_t cap) {
    convex_hull_monotone_t *s = malloc(sizeof(convex_hull_monotone_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void convex_hull_monotone_free(convex_hull_monotone_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    convex_hull_monotone_t *inst = convex_hull_monotone_create(16);
    if (inst) {
        printf("convex_hull_monotone initialized successfully.\n");
        convex_hull_monotone_free(inst);
    }
    return 0;
}
