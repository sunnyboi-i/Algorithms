# Ford-Fulkerson Algorithm

## Description
The **Ford-Fulkerson algorithm** is a method used to compute the maximum flow in a flow network. It uses depth-first search (DFS) to find augmenting paths and increases the flow until no more augmenting paths exist.

This repository contains an implementation of the Ford-Fulkerson algorithm in C++.

## How algorithm works
1. Start with an initial flow of 0.
2. While there exists an augmenting path from the **source** to the **sink**:
   - Find the maximum possible flow in this path.
   - Augment the flow along the path.
3. Repeat until no more augmenting paths exist.

The algorithm runs in **O(E * max_flow)** time complexity in the worst case.

## Implementation Details
- The implementation uses an adjacency list representation of the graph.
- Each edge has a residual edge that helps in computing the remaining capacity.
- The algorithm employs **Depth-First Search (DFS)** to find augmenting paths.

## Code Explanation
The provided C++ code does the following:
- Reads the number of vertices and edges.
- Constructs a directed graph with given capacities.
- Runs the **Ford-Fulkerson** method to compute the maximum flow.
- Outputs the result.

### Data Structures
- **`Edge`**: Represents a directed edge with residual capacity.
- **`Graph`**: Manages vertices, edges, and DFS-based augmentation.

### Key Functions
- **`insert_edge(int from, int to, int cap)`**: Adds edges with forward and residual capacities.
- **`DFS(int src, int flow)`**: Finds an augmenting path using DFS.
- **`FordFulkerson()`**: Computes the maximum flow using iterative DFS calls.

### Input format
<number_of_vertices> <number_of_edges> \
<from> <to> <capacity> \
<from> <to> <capacity> \
... \
<from> <to> <capacity>

### Output format
<Max flow>

## Complexity Analysis

- **Time Complexity**: O(E * max_flow) in the worst case.  
- **Space Complexity**: O(V + E) due to adjacency list representation.
