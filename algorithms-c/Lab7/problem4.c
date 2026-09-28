#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

#define WHITE 0
#define GRAY  1
#define BLACK 2

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

int timer = 0;

void dfsVisitRecursive(Graph* graph, int u, int color[], int d[], int f[], int parent[]) {
    timer++;
    d[u] = timer;
    color[u] = GRAY;
    printf("%d ", u);

    Node* temp = graph->adjLists[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (color[v] == WHITE) {
            parent[v] = u;
            dfsVisitRecursive(graph, v, color, d, f, parent);
        }
        temp = temp->next;
    }

    color[u] = BLACK;
    timer++;
    f[u] = timer;
}

void dfsRecursive(Graph* graph, int startVertex) {
    int color[MAX];
    int d[MAX];
    int f[MAX];
    int parent[MAX];

    for (int i = 0; i < graph->V; i++) {
        color[i] = WHITE;
        d[i] = 0;
        f[i] = 0;
        parent[i] = -1;
    }

    timer = 0;
    printf("\n=== Recursive DFS Traversal ===\n");
    printf("Visited: ");

    dfsVisitRecursive(graph, startVertex, color, d, f, parent);

    for (int i = 0; i < graph->V; i++) {
        if (color[i] == WHITE) {
            dfsVisitRecursive(graph, i, color, d, f, parent);
        }
    }
    printf("\n\n");

    printf("----------------------------------------------------------\n");
    printf(" Vertex | Color | Discovery (d) | Finish (f) | Parent (pi)\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < graph->V; i++) {
        printf("   %2d   | BLACK |      %2d       |     %2d     | ", i, d[i], f[i]);
        if (parent[i] == -1) {
            printf("%-6s\n", "NIL");
        } else {
            printf("%-6d\n", parent[i]);
        }
    }
    printf("----------------------------------------------------------\n");
}

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void dfsIterative(Graph* graph, int startVertex) {
    bool visited[MAX] = {false};
    Stack s;
    initStack(&s);

    printf("\n=== Iterative DFS Traversal (Explicit Stack) ===\n");
    printf("Visited: ");

    push(&s, startVertex);

    while (!isStackEmpty(&s)) {
        int u = pop(&s);

        if (!visited[u]) {
            visited[u] = true;
            printf("%d ", u);

            Node* temp = graph->adjLists[u];
            while (temp != NULL) {
                if (!visited[temp->dest]) {
                    push(&s, temp->dest);
                }
                temp = temp->next;
            }
        }
    }

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            push(&s, i);
            while (!isStackEmpty(&s)) {
                int u = pop(&s);
                if (!visited[u]) {
                    visited[u] = true;
                    printf("%d ", u);
                    Node* temp = graph->adjLists[u];
                    while (temp != NULL) {
                        if (!visited[temp->dest]) {
                            push(&s, temp->dest);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
    }
    printf("\n\n");
}

int main() {
    int V, E;

    printf("========================================================\n");
    printf("   DAA Lab 7 - Problem 4: DFS (Adjacency List)          \n");
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

    int start;
    printf("Enter starting source vertex (0 to %d): ", V - 1);
    scanf("%d", &start);

    if (start < 0 || start >= V) {
        printf("Invalid start vertex!\n");
        return 1;
    }

    dfsRecursive(graph, start);
    dfsIterative(graph, start);

    return 0;
}
