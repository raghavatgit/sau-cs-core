#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dest, weight;
} GraphEdge;

int compare_edges(const void *a, const void *b) {
    return ((GraphEdge*)a)->weight - ((GraphEdge*)b)->weight;
}
