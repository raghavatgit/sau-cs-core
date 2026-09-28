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
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void bfsComponent(Graph* graph, int startVertex, int compId, bool visited[], int component[]) {
    Queue q;
    initQueue(&q);

    visited[startVertex] = true;
    component[startVertex] = compId;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        Node* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->dest;
            if (!visited[v]) {
                visited[v] = true;
                component[v] = compId;
                enqueue(&q, v);
            }
            temp = temp->next;
        }
    }
}

void findConnectedComponents(Graph* graph) {
    bool visited[MAX] = {false};
    int component[MAX] = {0};
    int totalComponents = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            totalComponents++;
            bfsComponent(graph, i, totalComponents, visited, component);
        }
    }

    printf("\n=== Vertex to Component Assignment ===\n");
    printf("----------------------------------------\n");
    printf(" Vertex  | Assigned Component Number    \n");
    printf("----------------------------------------\n");
    for (int i = 0; i < graph->V; i++) {
        printf("   %2d    | Component %d\n", i, component[i]);
    }
    printf("----------------------------------------\n");

    printf("\n=== Connected Components List ===\n");
    for (int c = 1; c <= totalComponents; c++) {
        printf("Component %d: { ", c);
        for (int i = 0; i < graph->V; i++) {
            if (component[i] == c) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }

    printf("\n=== Connectivity Result ===\n");
    printf("Total Connected Components: %d\n", totalComponents);
    if (totalComponents == 1) {
        printf("Verdict: The graph is CONNECTED.\n");
    } else {
        printf("Verdict: The graph is DISCONNECTED.\n");
    }
}

int main() {
    int V, E;

    printf("========================================================\n");
    printf("   DAA Lab 7 - Problem 3: Connected Components (BFS)    \n");
    printf("========================================================\n");

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

    return 0;
}
