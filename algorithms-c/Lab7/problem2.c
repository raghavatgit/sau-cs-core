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
    int isDirected;
    Node** adjLists;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->isDirected = isDirected;
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

    if (!graph->isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
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

void bfs(Graph* graph, int startVertex) {
    bool visited[MAX] = {false};
    int dist[MAX];
    for (int i = 0; i < graph->V; i++) {
        dist[i] = -1;
    }

    Queue q;
    initQueue(&q);

    visited[startVertex] = true;
    dist[startVertex] = 0;
    enqueue(&q, startVertex);

    printf("\n=== BFS Traversal Sequence ===\n");
    printf("Order: ");

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                dist[adjVertex] = dist[currentVertex] + 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n\n");

    printf("----------------------------------------\n");
    printf(" Vertex | Visited | Shortest Hop Count   \n");
    printf("----------------------------------------\n");
    for (int i = 0; i < graph->V; i++) {
        printf("   %2d   | %-7s | ", i, visited[i] ? "YES" : "NO");
        if (dist[i] == -1) {
            printf("Unreachable\n");
        } else {
            printf("%d hops\n", dist[i]);
        }
    }
    printf("----------------------------------------\n");
}

void printGraph(Graph* graph) {
    printf("\n--- Adjacency List Representation ---\n");
    for (int v = 0; v < graph->V; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("-> NULL\n");
    }
}

int main() {
    int V, E, choice;

    printf("==================================================\n");
    printf("   DAA Lab 7 - Problem 2: BFS (Adjacency List)     \n");
    printf("==================================================\n");

    printf("Choose graph type:\n");
    printf("  0 - Undirected Graph\n");
    printf("  1 - Directed Graph\n");
    printf("Enter choice (0 or 1): ");
    scanf("%d", &choice);
    int isDirected = (choice == 1) ? 1 : 0;

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

    Graph* graph = createGraph(V, isDirected);

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

    printGraph(graph);

    int start;
    printf("\nEnter starting source vertex (0 to %d): ", V - 1);
    scanf("%d", &start);

    if (start < 0 || start >= V) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    bfs(graph, start);

    return 0;
}
