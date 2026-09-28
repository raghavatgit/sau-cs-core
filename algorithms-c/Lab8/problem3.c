#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[100];
struct Node* revAdj[100];
int visited[100];
int stack[100];
int top = -1;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void addRevEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = revAdj[u];
    revAdj[u] = newNode;
}

void dfs1(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            dfs1(v);
        }
        temp = temp->next;
    }
    stack[++top] = u;
}

void getTranspose(int V) {
    for (int u = 0; u < V; u++) {
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            addRevEdge(v, u);
            temp = temp->next;
        }
    }
}

void dfs2(int u) {
    visited[u] = 1;
    printf("%d ", u);
    struct Node* temp = revAdj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            dfs2(v);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        revAdj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    getTranspose(V);

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int sccCount = 0;
    printf("\nStrongly Connected Components:\n");
    while (top >= 0) {
        int u = stack[top--];
        if (!visited[u]) {
            sccCount++;
            printf("Component %d: ", sccCount);
            dfs2(u);
            printf("\n");
        }
    }
    printf("Total Strongly Connected Components: %d\n", sccCount);

    return 0;
}
