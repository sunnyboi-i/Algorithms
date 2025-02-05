# Dijkstra's Shortest Path Algorithm

## Description
This algorithm efficiently computes the shortest path from a given **start vertex** to all other vertices in a **weighted undirected graph** using **Dijkstra’s algorithm**.

## How the Algorithm Works

1. **Graph Representation:**
   - The graph is stored as an **adjacency list** using an unordered map.
   - Each edge contains:
     - **`pt1`**: Source vertex.
     - **`pt2`**: Destination vertex.
     - **`wg`**: Edge weight.

2. **Dijkstra's Algorithm:**
   - Utilizes a **priority queue (min-heap)** to always expand the nearest vertex first.
   - Maintains a **distance map** initialized with a large value (`2009000999`).
   - Iterates through all neighbors of the current vertex:
     - If a shorter path is found, it updates the distance and pushes the vertex into the priority queue.

3. **Visitor Pattern for Tracking Distances:**
   - The `VisitorD` class tracks:
     - **Visited vertices**.
     - **Shortest distance to each vertex**.
     - **Ancestor relationships** (previous node in the shortest path).

## Input Format
- The first integer **`num`** represents the number of test cases.
- For each test case:
  - Two integers: **`size`** (number of vertices) and **`edges`** (number of edges).
  - **`edges`** lines, each containing:
    - **`from`** (start vertex)
    - **`to`** (end vertex)
    - **`weight`** (cost of the edge)
  - A final integer **`start`** (starting vertex for Dijkstra's algorithm).

## Output Format
- A single line containing the shortest distances from **`start`** to all other vertices.

## Complexity Analysis
- **Time Complexity:** O((V + E) log V), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V + E) for storing the graph and distance array.

