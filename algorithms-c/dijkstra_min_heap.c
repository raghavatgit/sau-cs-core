/*
 * Dijkstra Shortest Path with Binary Min-Heap
 * Time Complexity: O((V + E) log V)
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 512

typedef struct {
    int v;
    int weight;
} HeapNode;

typedef struct {
    HeapNode data[MAX_VERTICES * 4];
    int size;
} MinHeap;

void heap_push(MinHeap* h, int v, int w) {
    int i = h->size++;
    h->data[i] = (HeapNode){v, w};
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent].weight <= h->data[i].weight) break;
        HeapNode tmp = h->data[parent];
        h->data[parent] = h->data[i];
        h->data[i] = tmp;
        i = parent;
    }
}
