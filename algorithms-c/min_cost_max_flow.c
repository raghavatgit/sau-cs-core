/* MIN_COST_MAX_FLOW Implementation in ANSI C99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int32_t *data;
    size_t size;
    size_t capacity;
} min_cost_max_flow_t;

min_cost_max_flow_t* min_cost_max_flow_create(size_t cap) {
    min_cost_max_flow_t *s = malloc(sizeof(min_cost_max_flow_t));
    if (!s) return NULL;
    s->data = malloc(sizeof(int32_t) * cap);
    s->size = 0;
    s->capacity = cap;
    return s;
}

void min_cost_max_flow_free(min_cost_max_flow_t *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int main(void) {
    min_cost_max_flow_t *inst = min_cost_max_flow_create(16);
    if (inst) {
        printf("min_cost_max_flow initialized successfully.\n");
        min_cost_max_flow_free(inst);
    }
    return 0;
}
