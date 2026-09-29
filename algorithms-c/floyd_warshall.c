/*
 * Floyd-Warshall All-Pairs Shortest Path
 */
#include <stdio.h>

#define INF 1000000000
#define V_MAX 128

void floyd_warshall(int dist[V_MAX][V_MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
