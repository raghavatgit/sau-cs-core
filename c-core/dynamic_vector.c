/*
 * Dynamic Vector Array in C
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Vector;

Vector vector_create(size_t initial_cap) {
    if (initial_cap == 0) initial_cap = 4;
    return (Vector){
        .data = (int*)malloc(initial_cap * sizeof(int)),
        .size = 0,
        .capacity = initial_cap
    };
}

void vector_push(Vector* v, int val) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

void vector_free(Vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = v->capacity = 0;
}
