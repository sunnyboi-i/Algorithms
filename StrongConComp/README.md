# Strongly Connected Components Finder

This repository contains an implementation of **Kosaraju’s algorithm** to find the **strongly connected components** in a directed graph. The algorithm efficiently identifies SCCs using depth-first search (DFS) and graph transposition.

## Problem Description

A **strongly connected component** of a directed graph is a maximal subset of
vertices such that every pair of vertices is mutually reachable. This means that
for any two vertices **u** and **v** in the same strongly connected component, there exists a path from **u** to **v** and a path from **v** to **u**.

### Algorithm Overview

Kosaraju's algorithm consists of two main DFS traversals:

1. **First DFS (Ordering Phase)**:
   - Perform a **DFS** on the original graph, recording the vertices in order of their finishing times.
   
2. **Graph Transposition**:
   - Reverse all edges in the graph.

3. **Second DFS (Component Identification Phase)**:
   - Process nodes in decreasing order of finishing time from the first DFS.
   - Each DFS traversal in the transposed graph discovers strongly connected
     component.

## Implementation Details

### Key Components

1. **Graph Representation**:
   - The graph is represented using adjacency lists (`adj` for the original graph, `adj_t` for the transposed graph).
   - Uses an array `components` to store the strongly connected component index for each vertex.

2. **DFS Traversals**:
   - `DFS1`: Performs the first DFS to determine the processing order.
   - `DFS2`: Runs DFS on the transposed graph to identify strongly connected
     componentss.

3. **Component Assignment**:
   - A counter is used to label each strongly connected component.

4. **Main Function**:
   - Reads the input graph, executes the strongly connected component algorithm,
     and prints the number of strongly connected componentss along with their assignments.

## Input and Output Format

### Input Format

- The first line contains two integers:
  - `size` (number of vertices)
  - `numberOfEdges` (number of directed edges).
- The next `numberOfEdges` lines contain two integers `pt1` and `pt2`, representing a directed edge from `pt1` to `pt2`.
- Nodes are 1-based indexed.

### Output Format

- The first line contains an integer representing the **number of strongly
  connected componentss**.
- The second line contains `size` integers, where the `i-th` integer represents
  the strongly connected component index (1-based) of node `i`.

## Complexity Analysis

- **First DFS**: **O(V + E)**
- **Graph Transposition**: **O(V + E)**
- **Second DFS**: **O(V + E)**
- **Total Complexity**: **O(V + E)**


#### Example Input:
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

#### Example Output:
2
1 2 2 1 1 2 2 2 2 1
