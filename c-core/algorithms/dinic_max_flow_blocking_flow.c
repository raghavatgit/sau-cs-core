#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 500
#define INF 1000000000

int capacity[MAX_VERTICES][MAX_VERTICES];
int flow[MAX_VERTICES][MAX_VERTICES];
int level[MAX_VERTICES];
int ptr[MAX_VERTICES];

int bfs(int s, int t, int n) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    int queue[MAX_VERTICES];
    int q_head = 0, q_tail = 0;
    queue[q_tail++] = s;

    while (q_head < q_tail) {
        int v = queue[q_head++];
        for (int to = 0; to < n; to++) {
            if (level[to] == -1 && capacity[v][to] - flow[v][to] > 0) {
                level[to] = level[v] + 1;
                queue[q_tail++] = to;
            }
        }
    }
    return level[t] != -1;
}
