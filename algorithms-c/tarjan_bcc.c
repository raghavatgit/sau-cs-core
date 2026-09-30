/* TARJAN_BCC Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} tarjan_bcc_t;

tarjan_bcc_t* tarjan_bcc_create(size_t cap) {
    tarjan_bcc_t *s = malloc(sizeof(tarjan_bcc_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void tarjan_bcc_free(tarjan_bcc_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    tarjan_bcc_t *inst = tarjan_bcc_create(16);
    if (inst) {
        printf("tarjan_bcc initialized successfully.\n");
        tarjan_bcc_free(inst);
    }
    return 0;
}
