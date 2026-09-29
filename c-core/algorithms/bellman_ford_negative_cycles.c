#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int u, v, weight;
} GraphEdge;

bool bellman_ford(int V, int E, GraphEdge edges[], int src, int dist[]) {
    for (int i = 0; i < V; i++) dist[i] = 1000000;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            if (dist[u] != 1000000 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        if (dist[edges[j].u] != 1000000 && dist[edges[j].u] + edges[j].weight < dist[edges[j].v]) {
            return false; // Negative cycle detected
        }
    }
    return true;
}
