#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjLists;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjLists = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfsComponent(Graph* graph, int u, int compId, bool visited[], int component[]) {
    visited[u] = true;
    component[u] = compId;

    Node* temp = graph->adjLists[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            dfsComponent(graph, v, compId, visited, component);
        }
        temp = temp->next;
    }
}

void findConnectedComponents(Graph* graph) {
    bool visited[MAX] = {false};
    int component[MAX] = {0};
    int totalComponents = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            totalComponents++;
            dfsComponent(graph, i, totalComponents, visited, component);
        }
    }

    printf("\n=== Connected Components (via DFS) ===\n");
    printf("Total Connected Components: %d\n", totalComponents);
    for (int c = 1; c <= totalComponents; c++) {
        printf("Component %d: { ", c);
        for (int i = 0; i < graph->V; i++) {
            if (component[i] == c) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }

    if (totalComponents == 1) {
        printf("Verdict: The graph is CONNECTED.\n");
    } else {
        printf("Verdict: The graph is DISCONNECTED.\n");
    }
}

bool dfsCycleCheck(Graph* graph, int u, int parentNode, bool visited[], int* cycleU, int* cycleV) {
    visited[u] = true;

    Node* temp = graph->adjLists[u];
    while (temp != NULL) {
        int v = temp->dest;

        if (!visited[v]) {
            if (dfsCycleCheck(graph, v, u, visited, cycleU, cycleV)) {
                return true;
            }
        } else if (v != parentNode) {
            *cycleU = u;
            *cycleV = v;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void detectCycle(Graph* graph) {
    bool visited[MAX] = {false};
    int cycleU = -1, cycleV = -1;
    bool hasCycle = false;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(graph, i, -1, visited, &cycleU, &cycleV)) {
                hasCycle = true;
                break;
            }
        }
    }

    printf("\n=== Cycle Detection Result ===\n");
    if (hasCycle) {
        printf("Cycle Status : YES, the graph contains at least one cycle!\n");
        printf("Evidence     : Back-edge discovered between vertex %d and vertex %d.\n", cycleU, cycleV);
    } else {
        printf("Cycle Status : NO, the graph is acyclic (contains NO cycles).\n");
    }
    printf("==================================================\n");
}

int main() {
    int V, E;

    printf("===============================================================\n");
    printf("  DAA Lab 7 - Problem 5: Components & Cycle Detection (DFS)     \n");
    printf("===============================================================\n");

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX) {
        printf("Invalid vertex count.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        printf("Invalid edge count.\n");
        return 1;
    }

    Graph* graph = createGraph(V);

    printf("Enter edges (u v) [0-indexed, 0 to %d]:\n", V - 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            addEdge(graph, u, v);
        } else {
            printf("Invalid edge (%d, %d). Skipped.\n", u, v);
        }
    }

    findConnectedComponents(graph);
    detectCycle(graph);

    return 0;
}
