# Transitive Closure using Floyd-Warshall Algorithm

## Description
This program computes the **transitive closure** of a **directed graph** using the **Floyd-Warshall Algorithm**.  
The transitive closure of a graph indicates whether there is a path between any two vertices.

## How the Algorithm Works

1. **Graph Representation:**
   - The graph is stored as an **adjacency matrix**.
   - Each cell `(i, j)` contains:
     - `1` if there is a direct edge from `i` to `j`.
     - `0` otherwise.

2. **Floyd-Warshall Algorithm:**
   - The adjacency matrix is copied into a result matrix.
   - The algorithm iterates over all possible intermediate nodes `k`:
     - If there is a path from `i → k` and `k → j`, then a path exists from `i → j`.
   - The final matrix represents the transitive closure.

3. **Output Format:**
   - The matrix of transitive closure:
     - `1` if a path exists between two nodes.
     - `0` otherwise.

## Input Format
- The first line contains **one integer**:
  - **`size`** (number of vertices).
- The next `size` lines contain `size` space-separated integers (0 or 1),  
  representing the **adjacency matrix** of the graph.

## Output Format
- The `size × size` matrix representing the **transitive closure**.

## Example

### **Input:**

4 \
1 1 0 0 \
0 1 1 0 \
1 0 1 0 \
0 0 1 1

### **Output:**

1 1 1 0 \
1 1 1 0 \
1 1 1 0 \
1 1 1 1 
