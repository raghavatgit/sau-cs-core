#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[100];
int in_degree[100];
int queue[100];
int topo[100];
int front = 0, rear = -1;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    in_degree[v]++;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        in_degree[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int count = 0;
    while (front <= rear) {
        int u = queue[front++];
        topo[count++] = u;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                queue[++rear] = v;
            }
            temp = temp->next;
        }
    }

    if (count < V) {
        printf("Graph contains a cycle! Topological ordering is not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}
