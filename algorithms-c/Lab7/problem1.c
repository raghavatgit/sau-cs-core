#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

#define WHITE 0
#define GRAY  1
#define BLACK 2

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void bfs(int adj[MAX][MAX], int V, int src) {
    int color[MAX];
    int d[MAX];
    int parent[MAX];

    for (int u = 0; u < V; u++) {
        color[u] = WHITE;
        d[u] = INF;
        parent[u] = -1;
    }

    color[src] = GRAY;
    d[src] = 0;
    parent[src] = -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, src);

    printf("\n=== BFS Traversal Order ===\n");
    printf("Visited: ");

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                if (color[v] == WHITE) {
                    color[v] = GRAY;
                    d[v] = d[u] + 1;
                    parent[v] = u;
                    enqueue(&q, v);
                }
            }
        }
        color[u] = BLACK;
    }
    printf("\n\n");

    printf("--------------------------------------------------\n");
    printf(" Vertex | Color    | Distance from Src | Parent \n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        printf("   %2d   | %-8s | ", i, color[i] == BLACK ? "BLACK" : (color[i] == GRAY ? "GRAY" : "WHITE"));
        if (d[i] == INF) {
            printf("%-17s | ", "INF (Unreachable)");
        } else {
            printf("%-17d | ", d[i]);
        }
        if (parent[i] == -1) {
            printf("%-6s\n", "NIL");
        } else {
            printf("%-6d\n", parent[i]);
        }
    }
    printf("--------------------------------------------------\n");
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};

    printf("==================================================\n");
    printf("   DAA Lab 7 - Problem 1: BFS (Adjacency Matrix)   \n");
    printf("==================================================\n");

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter edges (u v) [0-indexed, 0 to %d]:\n", V - 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        } else {
            printf("Invalid edge (%d, %d). Skipped.\n", u, v);
        }
    }

    int src;
    printf("Enter starting source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    if (src < 0 || src >= V) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    bfs(adj, V, src);

    return 0;
}
