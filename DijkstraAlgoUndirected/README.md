# Dijkstra's Shortest Path Algorithm with Infection Check

## Description
This algorithm computes the shortest path in a weighted, undirected graph using **Dijkstra’s algorithm**. Additionally, it determines if the shortest path from a start vertex to an end vertex is "safe" by comparing it against paths leading to "infected" nodes.

## How the Algorithm Works

1. **Graph Representation:**
   - The graph is stored as an **adjacency list**, where each entry contains pairs of (neighboring vertex, edge weight).
   - A **distance vector** keeps track of the shortest known distance to each vertex, initialized to infinity (`INT64_MAX`).

2. **Dijkstra's Algorithm:**
   - Uses a **priority queue (min-heap)** to explore the vertex with the smallest current distance.
   - Updates distances to neighboring vertices if a shorter path is found via the current vertex.

3. **Infected Nodes Handling:**
   - A set of "infected" nodes is stored separately.
   - After running Dijkstra’s algorithm, the shortest distance to any infected node is compared with the distance to the destination.
   - The result determines if reaching the destination is "safe" (`-1` if not safe, or the shortest path distance if safe).

## Input Format
- Three integers:
  - **`size`**: Number of vertices.
  - **`edges`**: Number of edges.
  - **`num`**: Number of infected nodes.
- Next **`num`** lines contain one integer each, listing the infected nodes (1-based index).
- Next **`edges`** lines contain three integers each:
  - **`from`** (start vertex of the edge)
  - **`to`** (end vertex of the edge)
  - **`weight`** (cost of the edge)
- Two final integers:
  - **`begin`** (starting vertex)
  - **`end`** (destination vertex)

## Output Format
- A single integer:
  - The shortest path distance from **`begin`** to **`end`** if it's "safe".
  - `-1` if the path is considered "unsafe" due to proximity to infected nodes.

## Complexity Analysis
- **Time Complexity:** O((V + E) log V), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V + E) for storing the graph and the distance/visited vectors.

## Example Usage

### **Input**
6 5 1 \
6 \
1 2 20 \
2 3 2 \
3 4 1 \
2 5 1 \
5 6 3 \
4 1 \

## **Output**
23
