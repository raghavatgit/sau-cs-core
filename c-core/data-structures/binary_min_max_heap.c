#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} MinHeap;

MinHeap* create_min_heap(size_t capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void min_heap_insert(MinHeap *heap, int val) {
    if (heap->size == heap->capacity) return;
    size_t idx = heap->size++;
    heap->data[idx] = val;

    while (idx > 0) {
        size_t parent = (idx - 1) / 2;
        if (heap->data[idx] < heap->data[parent]) {
            swap(&heap->data[idx], &heap->data[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

int min_heap_extract(MinHeap *heap) {
    if (heap->size == 0) return -1;
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    size_t idx = 0;
    while (2 * idx + 1 < heap->size) {
        size_t left = 2 * idx + 1;
        size_t right = 2 * idx + 2;
        size_t smallest = left;

        if (right < heap->size && heap->data[right] < heap->data[left]) {
            smallest = right;
        }

        if (heap->data[smallest] < heap->data[idx]) {
            swap(&heap->data[idx], &heap->data[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }

    return root;
}
