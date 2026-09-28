# SAU CS Core: Advanced Algorithms & Object-Oriented Software Engineering

A repository documenting theoretical computer science foundations, algorithm design, and software architecture implementations from the South Asian University curriculum.

---

## Covered Curriculums

### 1. Design & Analysis of Algorithms in C (`algorithms-c/`)
Production C implementations with asymptotic complexity proofs:
- **Dynamic Programming**:
  - Matrix Chain Multiplication (MCM) with parenthesization memoization.
  - Longest Common Subsequence (LCS) and reconstruction.
- **Greedy Paradigm**:
  - Huffman Coding tree synthesis with optimal variable-length prefix codes.
  - Fractional Knapsack selection.
  - Single-Source Shortest Paths (Dijkstra algorithm).
  - Minimum Spanning Trees (Prim and Kruskal algorithms).
- **Advanced Graph Algorithms**:
  - Floyd-Warshall All-Pairs Shortest Paths with negative weight tracking.
  - Bellman-Ford algorithm with negative cycle detection.
  - Ford-Fulkerson Maximum Network Flow with residual capacity augmentation.

### 2. Object-Oriented Architecture in Java (`oop-java/`)
Enterprise-grade Java implementations following strict SOLID design principles:
- **Banking & ATM Transaction Engine**: Multi-tiered domain model with balance invariants, transactional rollbacks, and concurrent account validation.
- **University Management System**: Clean service-layer and model separation (`UniversityManager`, `UniversityApp`) with course scheduling, enrollment limits, and custom exception hierarchies.

---

## Directory Layout

```
sau-cs-core/
|-- algorithms-c/         # C implementations for DAA labs 6, 7, and 8
|   |-- Lab6/             # Dynamic Programming (MCM, LCS)
|   |-- Lab7/             # Greedy Algorithms (Huffman, Dijkstra, MST)
|   |-- Lab8/             # Graph Flow & Cycles (Floyd-Warshall, Bellman-Ford, Ford-Fulkerson)
|-- oop-java/             # Enterprise Java OOP labs 1 through 6
|   |-- Lab5/             # Package architectures, model encapsulation, banking models
|   |-- Lab6/             # Multi-tier University Management & ATM service layer
|-- LICENSE               # MIT License
```

---

## Compilation

```bash
# C Algorithms
gcc -O3 -Wall algorithms-c/Lab8/problem1.c -o problem1
./problem1

# Java OOP Applications
javac oop-java/Lab6/Q2_University/src/university/app/UniversityApp.java
java -cp oop-java/Lab6/Q2_University/src university.app.UniversityApp
```

---

## License

This educational repository is open-sourced under the MIT License.
