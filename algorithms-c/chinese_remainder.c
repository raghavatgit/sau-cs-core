/* CHINESE_REMAINDER Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} chinese_remainder_t;

chinese_remainder_t* chinese_remainder_create(size_t cap) {
    chinese_remainder_t *s = malloc(sizeof(chinese_remainder_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void chinese_remainder_free(chinese_remainder_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    chinese_remainder_t *inst = chinese_remainder_create(16);
    if (inst) {
        printf("chinese_remainder initialized successfully.\n");
        chinese_remainder_free(inst);
    }
    return 0;
}
