# Negative Cycle Detection Algorithm

This repository contains an implementation of the **Negative Cycle Detection** algorithm using the **Bellman-Ford** approach. The algorithm is implemented in C++ and is designed to detect whether a given directed graph contains a negative cycle. If a negative cycle is found, the program outputs the cycle; otherwise, it outputs "NO".

## Overview

A **negative cycle** in a graph is a cycle whose edges sum to a negative value. Detecting such cycles is crucial in applications like financial modeling, where negative cycles can represent arbitrage opportunities, or in network routing, where they can cause infinite loops.

The Bellman-Ford algorithm is used to detect negative cycles by relaxing all edges repeatedly and checking for improvements in the shortest path estimates. If a further improvement is possible after `V-1` iterations (where `V` is the number of vertices), a negative cycle exists.

## Implementation Details

### Graph Representation

The graph is represented using an **adjacency matrix**, where `adj[i][j]` represents the weight of the edge from vertex `i` to vertex `j`. If there is no edge, the weight is set to `100000` (a large value representing infinity).

### Key Components

1. **Graph Structure**:
   - `size`: Number of vertices in the graph.
   - `edges_c`: Number of edges in the graph.
   - `edges`: A list of all edges, where each edge is represented as a triplet `{u, v, w}` (source, destination, weight).
   - `parent`: A vector to store the parent of each vertex in the shortest path tree.
   - `dist`: A vector to store the shortest distance from the source to each vertex.

2. **Edge Counting**:
   - The `count_edges` function counts the number of edges in the graph and populates the `edges` vector.

3. **Cycle Detection**:
   - The `detectCycle` function implements the Bellman-Ford algorithm to detect negative cycles. If a negative cycle is found, it outputs "YES" along with the cycle; otherwise, it outputs "NO".

## Input and Output Format

### Input Format

The input consists of the following:

1. The first line contains a single integer:
   - `V`: The number of vertices in the graph.
2. The next `V` lines describe the adjacency matrix of the graph. Each line contains `V` integers:
   - `adj[i][j]`: The weight of the edge from vertex `i` to vertex `j`. If there is no edge, the weight is `100000`.

### Output Format

The output is one of the following:

1. If a negative cycle is detected:
   - The first line contains "YES".
   - The second line contains the number of vertices in the cycle.
   - The third line contains the vertices of the cycle in order.

2. If no negative cycle is detected:
   - The output is "NO".

## Complexity Analysis

### Time Complexity

The time complexity of the Bellman-Ford algorithm is: O(V * E)
where:
- `V` is the number of vertices.
- `E` is the number of edges.

In this implementation:
- Counting edges takes **O(V²)** time.
- Detecting the cycle takes **O(V \cdot E)** time.

Thus, the overall time complexity is:
O(V * E)

### Space Complexity

The space complexity is determined by the storage requirements for the graph and auxiliary data structures:
- The adjacency matrix requires **O(V²)** space.
- The `edges` vector requires **O(E)** space.
- The `parent` and `dist` vectors require **O(V)** space each.

Thus, the overall space complexity is:
O(V^2 + E)


#### Example Input
4 \
100000 -1 100000 100000 \
100000 100000 -1 100000 \
100000 100000 100000 -1 \
-1 100000 100000 100000

#### Example Output

YES \
4 \
1 2 3 4

