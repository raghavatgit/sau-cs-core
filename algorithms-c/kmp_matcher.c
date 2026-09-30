/* KMP_MATCHER Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} kmp_matcher_t;

kmp_matcher_t* kmp_matcher_create(size_t cap) {
    kmp_matcher_t *s = malloc(sizeof(kmp_matcher_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void kmp_matcher_free(kmp_matcher_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    kmp_matcher_t *inst = kmp_matcher_create(16);
    if (inst) {
        printf("kmp_matcher initialized successfully.\n");
        kmp_matcher_free(inst);
    }
    return 0;
}
