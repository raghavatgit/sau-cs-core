/* HEAVY_LIGHT_DECOMP Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} heavy_light_decomp_t;

heavy_light_decomp_t* heavy_light_decomp_create(size_t cap) {
    heavy_light_decomp_t *s = malloc(sizeof(heavy_light_decomp_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void heavy_light_decomp_free(heavy_light_decomp_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    heavy_light_decomp_t *inst = heavy_light_decomp_create(16);
    if (inst) {
        printf("heavy_light_decomp initialized successfully.\n");
        heavy_light_decomp_free(inst);
    }
    return 0;
}
