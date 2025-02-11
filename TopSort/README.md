# Topological Sorting and Cycle Detection in a Directed Graph

This repository contains an implementation of a **topological sorting algorithm** for a directed graph. The program also detects cycles in the graph using **depth-first search (DFS)**.

## Problem Description

A **topological sort** of a directed graph is a linear ordering of its vertices such that for every directed edge **(u, v)**, vertex **u** appears before vertex **v** in the ordering. **Topological sorting is only possible for Directed Acyclic Graphs**.

### Key Features

- **Cycle Detection**:
  - Before attempting topological sorting, the algorithm checks for cycles in the graph.
  - If a cycle is found, sorting is **not possible**.

- **Topological Sorting**:
  - If no cycles exist, the graph is sorted using a **DFS-based topological sort**.

## Algorithm Details

### Cycle Detection Using DFS

1. Each node is assigned a color:
   - **White (0)** → Unvisited.
   - **Gray (1)** → Currently being visited.
   - **Black (2)** → Fully processed.
2. DFS is performed:
   - If a gray node is encountered again, it means a **cycle exists**.
   - If a cycle is detected, topological sorting is **not possible**.

### Topological Sorting Using DFS

1. Perform a **DFS** on the graph.
2. Append each fully processed node to a result list.
3. Reverse the result list to obtain a valid topological order.

## Implementation Details

### Key Components

1. **Graph Representation**:
   - The graph is represented using an adjacency list (`adj`).
   - Arrays `color` and `visited` help track DFS progress.

2. **DFS-based Cycle Detection (`DFS_b`)**:
   - Identifies back edges, indicating cycles.

3. **DFS-based Topological Sorting (`DFS_v`)**:
   - Generates a valid topological order for s.

4. **Main Execution (`topological_sort`)**:
   - If the graph contains a cycle, output `-1`.
   - Otherwise, print the topological ordering.

## Input and Output Format

### Input Format

- The first line contains two integers:
  - `size` → Number of vertices.
  - `edges` → Number of directed edges.
- The next `edges` lines contain two integers `pt1` and `pt2`, representing a directed edge from `pt1` to `pt2`.

### Output Format

- If the graph **contains a cycle**, output:
- If given graph is directed and acyclic then, output the **topological order**:


## Complexity Analysis

- **Cycle Detection (DFS)**: **O(V + E)**
- **Topological Sorting (DFS)**: **O(V + E)**
- **Total Complexity**: **O(V + E)** (optimal for sparse graphs)


#### Example Input:
6 6 \
1 2 \
3 2 \
4 2 \
2 5 \
6 5 \
4 6

#### Example Output:
4 6 3 1 2 5 

