/*
 * Bellman-Ford Shortest Path Algorithm
 * Time Complexity: O(V * E)
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int u, v, w;
} Edge;

bool bellman_ford(int num_vertices, int num_edges, Edge edges[], int src, int dist[]) {
    for (int i = 0; i < num_vertices; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= num_vertices - 1; i++) {
        for (int j = 0; j < num_edges; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < num_edges; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return false; // Negative weight cycle exists
        }
    }
    return true;
}
