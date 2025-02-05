# Graph Cycle Detection

## Description
This algorithm detects cycles in a **directed graph** using **Depth-First Search (DFS)**. If a cycle is found, it outputs the cycle; otherwise, it reports that no cycle exists.

## How the Algorithm Works

1. **Graph Representation:**
   - The graph is stored as an **adjacency list**.
   - A **color** array is used to track visited nodes.
   - A **parent** array helps reconstruct the cycle.

2. **Depth-First Search (DFS):**
   - The function `DFS(vertex)` explores all adjacent nodes.
   - If a back edge is found (a node visited but still in recursion), a cycle is detected.

3. **Cycle Detection:**
   - The function `hasCycle()` iterates through all nodes:
     - If a node is unvisited, a new DFS traversal starts.
     - If a cycle is found, the nodes forming the cycle are extracted.

4. **Output Format:**
   - If no cycle exists, output **"NO"**.
   - If a cycle is found:
     - Print **"YES"**.
     - Output the vertices forming the cycle (1-based index).

## Input
- The first line contains two integers:
  - **`size`** (number of vertices).
  - **`edges`** (number of edges).
- The next **`edges`** lines contain two integers **`pt1`** and **`pt2`**, representing a directed edge from `pt1` to `pt2`.

## Output
- **"NO"** if no cycle exists.
- **"YES"** followed by the cycle (1-based index) if a cycle is found.

## Example
### **Input:**

4 4 \
1 2 \
2 3 \
3 4 \
4 2

### **Output:***
YES \
2 3 4


## Complexity Analysis

- **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V + E) for storing the adjacency list and auxiliary arrays.
