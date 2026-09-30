/* CENTROID_DECOMP Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} centroid_decomp_t;

centroid_decomp_t* centroid_decomp_create(size_t cap) {
    centroid_decomp_t *s = malloc(sizeof(centroid_decomp_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void centroid_decomp_free(centroid_decomp_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    centroid_decomp_t *inst = centroid_decomp_create(16);
    if (inst) {
        printf("centroid_decomp initialized successfully.\n");
        centroid_decomp_free(inst);
    }
    return 0;
}
