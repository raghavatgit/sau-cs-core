/* AHO_CORASICK Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} aho_corasick_t;

aho_corasick_t* aho_corasick_create(size_t cap) {
    aho_corasick_t *s = malloc(sizeof(aho_corasick_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void aho_corasick_free(aho_corasick_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    aho_corasick_t *inst = aho_corasick_create(16);
    if (inst) {
        printf("aho_corasick initialized successfully.\n");
        aho_corasick_free(inst);
    }
    return 0;
}
