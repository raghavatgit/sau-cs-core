/* CLOSEST_PAIR_POINTS Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} closest_pair_points_t;

closest_pair_points_t* closest_pair_points_create(size_t cap) {
    closest_pair_points_t *s = malloc(sizeof(closest_pair_points_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void closest_pair_points_free(closest_pair_points_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    closest_pair_points_t *inst = closest_pair_points_create(16);
    if (inst) {
        printf("closest_pair_points initialized successfully.\n");
        closest_pair_points_free(inst);
    }
    return 0;
}
