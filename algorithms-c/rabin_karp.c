/* RABIN_KARP Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} rabin_karp_t;

rabin_karp_t* rabin_karp_create(size_t cap) {
    rabin_karp_t *s = malloc(sizeof(rabin_karp_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void rabin_karp_free(rabin_karp_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    rabin_karp_t *inst = rabin_karp_create(16);
    if (inst) {
        printf("rabin_karp initialized successfully.\n");
        rabin_karp_free(inst);
    }
    return 0;
}
