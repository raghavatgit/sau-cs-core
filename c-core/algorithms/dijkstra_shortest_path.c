#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100

typedef struct Edge {
    int to;
    int weight;
    struct Edge *next;
} Edge;

Edge* adj[MAX_V];
int dist[MAX_V];

void add_edge(int u, int v, int w) {
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;
}
