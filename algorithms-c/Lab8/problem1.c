#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];
int stack[100];
int top = -1;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (visited[v] == 1) {
            return 1;
        }
        if (visited[v] == 0) {
            if (dfs(v)) {
                return 1;
            }
        }
        temp = temp->next;
    }
    visited[u] = 2;
    stack[++top] = u;
    return 0;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int hasCycle = 0;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) {
        printf("Cycle detected! Topological ordering is not possible.\n");
    } else {
        printf("Topological Order: ");
        while (top >= 0) {
            printf("%d ", stack[top--]);
        }
        printf("\n");
    }

    return 0;
}
