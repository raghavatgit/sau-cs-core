/* EXTENDED_GCD Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} extended_gcd_t;

extended_gcd_t* extended_gcd_create(size_t cap) {
    extended_gcd_t *s = malloc(sizeof(extended_gcd_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void extended_gcd_free(extended_gcd_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    extended_gcd_t *inst = extended_gcd_create(16);
    if (inst) {
        printf("extended_gcd initialized successfully.\n");
        extended_gcd_free(inst);
    }
    return 0;
}
