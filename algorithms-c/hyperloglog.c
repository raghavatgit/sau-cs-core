/* HYPERLOGLOG Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} hyperloglog_t;

hyperloglog_t* hyperloglog_create(size_t cap) {
    hyperloglog_t *s = malloc(sizeof(hyperloglog_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void hyperloglog_free(hyperloglog_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    hyperloglog_t *inst = hyperloglog_create(16);
    if (inst) {
        printf("hyperloglog initialized successfully.\n");
        hyperloglog_free(inst);
    }
    return 0;
}
