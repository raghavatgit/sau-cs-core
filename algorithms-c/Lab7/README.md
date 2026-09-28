# DAA Lab 7: Graph Algorithms 1 - Solutions Guide

This repository contains standard, modular C implementations for all 5 problems of **Lab 7 (Graph Algorithms 1)**, tailored to B.Tech 2nd Year CSE standards (CLRS pseudocode alignment, custom Queue and Stack structs, clear terminal output).

---

## Files Overview

| File | Problem Description | Key Concepts / Data Structures |
|---|---|---|
| [`problem1.c`](problem1.c) | **BFS using Adjacency Matrix** | Adjacency Matrix `adj[V][V]`, CLRS colors (`WHITE`, `GRAY`, `BLACK`), FIFO Queue, distance `d[]`, predecessor `parent[]` |
| [`problem2.c`](problem2.c) | **BFS using Adjacency List** | Linked-list Adjacency List `Node* adjLists[]`, Directed/Undirected support, FIFO Queue, hop distances |
| [`problem3.c`](problem3.c) | **Connected Components using BFS** | BFS from unvisited nodes, component ID assignment, grouped component display, graph connectivity check |
| [`problem4.c`](problem4.c) | **DFS using Adjacency List** | **Both** implementations: (1) Recursive DFS with CLRS discovery & finish timestamps ($d, f$), and (2) Iterative DFS with explicit `Stack` struct |
| [`problem5.c`](problem5.c) | **Connected Components & Cycle Detection using DFS** | Component labeling via DFS, back-edge detection in undirected graphs ($v \text{ visited and } v \neq \text{parent}$) |

---

## Compilation Instructions (GCC)

To compile all solutions:

```bash
gcc -Wall -Wextra -o problem1.exe problem1.c
gcc -Wall -Wextra -o problem2.exe problem2.c
gcc -Wall -Wextra -o problem3.exe problem3.c
gcc -Wall -Wextra -o problem4.exe problem4.c
gcc -Wall -Wextra -o problem5.exe problem5.c
```

---

## Quick Testing Examples

### 1. Problem 1: BFS with Adjacency Matrix
**Sample Input:**
```text
4
4
0 1
0 2
1 2
2 3
0
```
**Expected Output:**
- Traversal order: `0 1 2 3`
- Distance table showing $d[0]=0, d[1]=1, d[2]=1, d[3]=2$.

---

### 2. Problem 2: BFS with Adjacency List
**Sample Input:**
```text
0
4
3
0 1
1 2
2 3
0
```
*(0 = Undirected, 4 vertices, 3 edges)*

---

### 3. Problem 3: Connected Components (BFS)
**Sample Input:**
```text
6
3
0 1
1 2
3 4
```
**Expected Output:**
- Component 1: `{ 0 1 2 }`
- Component 2: `{ 3 4 }`
- Component 3: `{ 5 }`
- Verdict: `The graph is DISCONNECTED.`

---

### 4. Problem 4: DFS (Recursive + Explicit Stack)
**Sample Input:**
```text
4
4
0 1
0 2
1 2
2 3
0
```
**Output Highlights:**
- Recursive DFS with Discovery ($d$) and Finishing ($f$) timestamps.
- Iterative DFS with custom explicit `Stack`.

---

### 5. Problem 5: Cycle Detection & Components (DFS)
**Sample Input (Graph with a Cycle):**
```text
5
4
0 1
1 2
2 0
3 4
```
**Expected Output:**
- Components: `{ 0 1 2 }`, `{ 3 4 }`
- Cycle Status: `YES, the graph contains at least one cycle!` (Back-edge identified).
