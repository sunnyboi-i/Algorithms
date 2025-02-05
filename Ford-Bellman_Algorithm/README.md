# Bellman-Ford Algorithm in C++

This program implements the **Bellman-Ford algorithm** for finding the shortest paths from a single source vertex to all other vertices in a **weighted directed graph**.

## Description

The **Bellman-Ford algorithm** is used for computing shortest paths in a weighted graph. Unlike Dijkstra's algorithm, it can handle graphs with **negative weight edges**. It works in **O(V × E)** time complexity, where `V` is the number of vertices and `E` is the number of edges.

### Steps:
1. Initialize distances from the source to all vertices as **infinity** (`30000` in this implementation) except the source, which is set to `0`.
2. **Relax all edges** |V| - 1 times.
3. Check for **negative weight cycles**: If an edge can still be relaxed, a negative cycle exists.

---

### **Input Format**
- The first line contains two integers:
- p1: Number of vertices.
- p2: Number of edges.
- The next p2 lines contain three integers:
- from: Start vertex of the edge.
- to: End vertex of the edge.
- weight: Weight of the edge.
### **Output Format**
If there is a negative weight cycle, the program does not output anything.
Otherwise, it prints the shortest distances from the source (vertex 0) to all vertices.

## Complexity Analysis

The Bellman-Ford algorithm has a time complexity of **O(V × E)** because:

- It iterates **(V - 1) times** over all **E edges** to relax them.
- In the worst case, the algorithm performs **V × E** operations.
- Worst Case **O(V × E)** 
- Best Case  **O(E)** (if all edges are relaxed in the first pass)


## Example Input:
5 7 \
1 2 6 \
1 3 7 \
2 4 5 \
2 3 8 \
3 4 -3 \
4 5 9 \
5 3 2 
## Example Output
0 6 7 4 13
