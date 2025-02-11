# Minimum Spanning Tree (MST) Algorithm

Minimum Spanning Tree (MST) algorithm using Kruskal's approach. The algorithm is implemented in C++ and utilizes a Union-Find data structure to efficiently manage and merge disjoint sets.

## Overview

The Minimum Spanning Tree (MST) of a connected, undirected graph is a subset of the graph's edges that connects all the vertices together, without any cycles, and with the minimum possible total edge weight. Kruskal's algorithm is a greedy algorithm that builds the MST by sorting all the edges in the graph in increasing order of their weight and then adding the smallest edge to the MST if it does not form a cycle.

## Implementation Details

### Union-Find Data Structure

The Union-Find data structure is used to keep track of the connected components of the graph. It supports two main operations:

- **Find**: Determines which subset a particular element is in.
- **Union**: Merges two subsets into a single subset.

### Graph Representation

The graph is represented using an adjacency list, where each vertex maps to a list of its adjacent edges. The edges are stored in a vector, and the graph class provides methods to insert edges and retrieve neighbors.

### Kruskal's Algorithm

The algorithm works as follows:

1. **Sort all edges**: All edges of the graph are sorted in non-decreasing order of their weight.
2. **Initialize Union-Find**: A Union-Find data structure is initialized with all vertices as separate subsets.
3. **Add edges to MST**: The smallest edge is picked and added to the MST if it does not form a cycle. This is repeated until there are `V-1` edges in the MST, where `V` is the number of vertices.

## Code Structure

- **UnionFind**: A template class that implements the Union-Find data structure.
- **Edge**: A struct that represents an edge in the graph, containing two vertices and a weight.
- **Graph**: A template class that represents the graph and provides methods to insert edges and compute the MST.
- **main**: The main function reads input, constructs the graph, and computes the MST.

## Usage

To use the algorithm, provide the following input:

1. The number of vertices and edges in the graph.
2. For each edge, provide the source vertex, destination vertex, and weight.

The program will output the total weight of the MST.

### Input Format

The input consists of the following:

1. The first line contains two integers:
   - `V`: The number of vertices in the graph.
   - `E`: The number of edges in the graph.
2. The next `E` lines describe the edges of the graph. Each line contains three integers:
   - `u`: The source vertex of the edge.
   - `v`: The destination vertex of the edge.
   - `w`: The weight of the edge.
### Output Format

The output is a single integer representing the total weight of the Minimum Spanning Tree (MST).



## Complexity Analysis

### Time Complexity

The time complexity of Kruskal's algorithm is dominated by the following steps:

1. **Sorting the edges**: Sorting `E` edges takes **O(E log E)** time.
2. **Union-Find operations**: Each `Find` and `Union` operation in the Union-Find data structure takes nearly constant time due to path compression and union by rank. For `E` edges, this results in **O(E α(V))** time, where `α(V)` is the inverse Ackermann function (very small and practically constant).

Thus, the overall time complexity is:

O(ElogE + Ealpha(V))

In most cases, this simplifies to:
O(ElogE)

### Space Complexity

The space complexity is determined by the storage requirements for the graph and the Union-Find data structure:

1. **Graph representation**: The adjacency list and edge list require **O(V + E)** space.
2. **Union-Find data structure**: The `id` and `arr` maps in the Union-Find structure require **O(V)** space.

Thus, the overall space complexity is:
O(V + E)


#### Example Input
4 5 \
0 1 10 \
0 2 6 \
0 3 5 \
1 3 15 \
2 3 4 

#### Example Output
19


