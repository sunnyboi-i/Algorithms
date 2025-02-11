# Dynamic Connectivity Algorithm

This repository contains an implementation of a **Dynamic Connectivity Algorithm** using the **Union-Find (Disjoint Set Union)** data structure. The algorithm processes a sequence of operations on a graph, including **connectivity queries** and **edge additions (cuts)**, and answers whether two nodes are connected at specific points in time.

## Problem Description

Given an undirected graph with `n` nodes and `m` initial edges, the algorithm processes a sequence of operations:
1. **Cut**: Remove an edge between two nodes.
2. **Ask**: Query whether two nodes are connected.

The algorithm processes these operations in **reverse order** (starting from the last operation) to efficiently handle dynamic changes to the graph.

## Implementation Details

### Key Components

1. **Union-Find Data Structure**:
   - Supports two main operations:
     - **Find**: Determines the root of a node (with path compression for efficiency).
     - **Union**: Merges two sets by connecting their roots (with union by size for balancing).
   - Tracks the size of each component and the total number of components.

2. **Operation Processing**:
   - Operations are processed in reverse order:
     - **Cut**: Adds an edge between two nodes (since we're processing in reverse).
     - **Ask**: Checks if two nodes are connected and stores the result.

3. **Main Function**:
   - Reads the input, initializes the Union-Find structure, processes the operations, and outputs the results of the queries.

### Algorithm Steps

1. **Input**:
   - The number of nodes `n`, the number of initial edges `m`, and the number of operations `ops`.
   - The initial edges (not used in this implementation but provided for context).
   - The sequence of operations (`cut` or `ask`), each involving two nodes.

2. **Processing**:
   - Initialize the Union-Find structure with `n` nodes.
   - Process the operations in reverse order:
     - For `cut` operations, add an edge between the two nodes.
     - For `ask` operations, check if the two nodes are connected and store the result.

3. **Output**:
   - The results of the `ask` operations in the original order.

## Input and Output Format

### Input Format

The input consists of:
1. The first line contains three integers:
   - `n`: The number of nodes.
   - `m`: The number of initial edges.
   - `ops`: The number of operations.
2. The next `m` lines describe the initial edges (not used in this implementation).
3. The next `ops` lines describe the operations:
   - `cut u v`: Remove the edge between nodes `u` and `v`.
   - `ask u v`: Query whether nodes `u` and `v` are connected.

### Output Format

The output consists of the results of the `ask` operations in the original order, one per line:
- `YES` if the nodes are connected.
- `NO` if the nodes are not connected.


## Complexity Analysis

### Time Complexity

- **Union-Find Operations**:
  - **Find**: Nearly constant time due to path compression, **O(α(n))**, where `α(n)` is the inverse Ackermann function.
  - **Union**: Nearly constant time due to union by size, **O(α(n))**.

- Overall time complexity for `ops` operations: **O(ops * α(n))**.

### Space Complexity

- The space complexity is **O(n)**, where `n` is the number of nodes, due to the storage of the Union-Find arrays (`id` and `arr`).


#### Example Input
3 3 7
1 2
2 3
3 1
ask 3 3
cut 1 2
ask 1 2
cut 1 3
ask 2 1
cut 2 3
ask 3 1

#### Example Output
YES
YES
NO
NO

