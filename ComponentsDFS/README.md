# Connected Components Finder in an Undirected Graph

## Description
This algorithm finds all **connected components** in an **undirected graph** using **Depth-First Search (DFS)**.  
A connected component is a maximal set of vertices such that there is a path between any two vertices in the set.

## How the Algorithm Works

1. **Graph Representation:**
   - The graph is stored as an **adjacency list**.
   - A **visited** array tracks which nodes have been explored.

2. **Depth-First Search (DFS):**
   - The function `DFS(vertex)` traverses all connected nodes of a component.
   - The **current component** is stored in a temporary vector.

3. **Building Connected Components:**
   - The function `component_build()` iterates through all nodes:
     - If a node is unvisited, a new DFS traversal starts.
     - The discovered component is stored in `components`.

4. **Output Format:**
   - The number of connected components.
   - For each component:
     - The number of vertices.
     - The vertices (1-based index).

## Input Format
- The first line contains two integers:
  - **`size`** (number of vertices).
  - **`edges`** (number of edges).
- The next **`edges`** lines contain two integers **`pt1`** and **`pt2`**, representing an **undirected edge**.

## Output Format
- First line: Number of connected components.
- Each component:
  - Number of vertices.
  - List of vertices in **1-based index**.

## Complexity Analysis
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V + E) for storing the graph and visited array.

## Example usage ##

## Example input ##
**First line contains N, M, where N is number of vertices, M number of edges, following M lines contains pairs, where each line represent edge.**

10 19 \
1 4 \
7 8 \
5 10 \
8 9 \
9 6 \
2 6 \
6 2 \
3 8 \
9 2 \
7 2 \
9 7 \
4 5 \
3 6 \
7 3 \
6 7 \
10 8 \
10 1 \
2 9 \
2 7
## Example output ##
**First line contains K, number of connected components, and following line, for each vertex writes number of connected component to which vertex belongs to.** 

2 \ 
1 2 2 1 1 2 2 2 2 1
