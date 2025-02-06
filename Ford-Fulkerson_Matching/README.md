# Ford-Fulkerson Algorithm for Maximum Bipartite Matching

## Description

This implementation of the **Ford-Fulkerson algorithm** finds the **maximum bipartite matching** in a given bipartite graph using **Depth-First Search (DFS)**. The algorithm constructs a flow network, applies the Ford-Fulkerson method to compute the maximum matching, and outputs the matched pairs.

## Implementation

- **Graph Structure**:  
  - Uses an adjacency list representation.
  - Stores directed edges with capacities.
  - Includes source and sink nodes for flow computation.

- **Algorithm Steps**:  
  1. **Graph Construction**:
     - Reads the bipartite graph.
     - Adds edges between left and right partition nodes.
     - Adds a source node connected to all left partition nodes.
     - Adds a sink node connected to all right partition nodes.

  2. **Ford-Fulkerson Algorithm**:
     - Uses DFS to find augmenting paths.
     - Augments flow along found paths.
     - Repeats until no more augmenting paths exist.

  3. **Output Matching**:
     - Extracts and prints matched pairs from the final flow values.

## Usage

### **Input Format**
1. Two integers representing the number of nodes in the left and right partitions.
2. For each left partition node:
   - A sequence of integers representing the right partition nodes it connects to (ending with `0`).

### **Example**

#### **Input**
2 2 \
1 2 0 \
2 0

This input implies, that from left partition vertex 1 is connected to vertex 2 from right partition, and vertex 2 from right partition is not connected to any vertex of right partition.

#### **Output**
2 \
1 1 \
2 2



## Complexity Analysis

- **Time Complexity**: O(E * V), where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V + E), used for adjacency lists and auxiliary storage.

This implementation efficiently finds the maximum matching in bipartite graphs using flow-based methods.

