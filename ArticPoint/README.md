# Articulation Points Finder

## Description
This algorithm finds **articulation points** (also known as cut vertices) in an **undirected graph**.  
An articulation point is a vertex that, when removed along with its edges, increases the number of connected components in the graph.

## How the algorithm works

- The graph is represented using an **adjacency list**.
- A **Depth-First Search (DFS)** is used to explore the graph.
- The algorithm maintains:
  - **`tin`**: Time of first visit for each vertex.
  - **`min_time`**: The lowest reachable time for each vertex.
  - **`visited`**: A boolean array to track visited nodes.
  - **`art_p`**: A set storing all articulation points.
- The **DFS traversal** updates `tin` and `min_time` values:
  - If a node has multiple **children in DFS tree** and is the root, it is an articulation point.
  - If a child node in DFS **cannot reach an earlier node**, its parent is an articulation point.

## Input Format
- The first line contains two integers **`size`** (number of vertices) and **`edges`** (number of edges).
- The next **`edges`** lines contain two integers **`pt1`** and **`pt2`** representing an undirected edge.

## Output Format
- First line: Number of articulation points.
- Following lines: The articulation points in **1-based indexing**.

## Complexity Analysis
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V) for storing graph information and DFS traversal data.

