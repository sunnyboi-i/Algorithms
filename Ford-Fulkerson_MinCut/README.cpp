# Ford-Fulkerson Algorithm with Min-Cut

## Description
The **Ford-Fulkerson algorithm** is used to compute the maximum flow in a flow network. This implementation extends the algorithm to also determine the **minimum cut**, which is the set of edges that, if removed, would disconnect the source from the sink.

This repository contains an optimized C++ implementation of the **Ford-Fulkerson algorithm with Min-Cut**.

## How algorithm works
1. Start with an initial flow of 0.
2. While there exists an augmenting path from the **source** to the **sink**:
   - Find the maximum possible flow in this path.
   - Augment the flow along the path.
3. Repeat until no more augmenting paths exist.
4. Identify the **Min-Cut**:
   - Perform a DFS to determine the reachable vertices.
   - Collect edges that cross from the reachable set to the non-reachable set.

The algorithm runs in **O(E * max_flow)** time complexity in the worst case.

## Implementation Details
- The implementation uses an adjacency list representation of the graph.
- Each edge has a residual edge to track the remaining capacity.
- **Depth-First Search (DFS)** is used for both flow augmentation and Min-Cut computation.

## Code Explanation
The provided C++ code does the following:
- Reads the number of vertices and edges.
- Constructs a directed graph with given capacities.
- Runs **Ford-Fulkerson** to compute the maximum flow.
- Computes the **Min-Cut** by identifying edges that separate the source and sink.
- Outputs the number of edges in the Min-Cut and the maximum flow value.

### Data Structures
- **`Edge`**: Represents a directed edge with a residual counterpart.
- **`Graph`**: Manages vertices, edges, DFS-based augmentation, and Min-Cut determination.

### Key Functions
- **`insert_edge(int from, int to, int cap, int position)`**: Adds edges with forward and residual capacities.
- **`DFS(int src, int flow)`**: Finds an augmenting path using DFS.
- **`FordFulkerson()`**: Computes the maximum flow using iterative DFS calls.
- **`MinCut()`**: Determines the minimum cut by identifying separating edges.

### Input format
<number_of_vertices> <number_of_edges> \
<from> <to> <capacity> \
<from> <to> <capacity> \
... \
<from> <to> <capacity>

### Output format
<number_of_edges_in_min_cut> <max_flow_value>
<list_of_edge_positions>


### Complexity Analysis

- **Time Complexity**: O(E * max_flow) in the worst case.  
- **Space Complexity**: O(V + E) due to adjacency list representation.
