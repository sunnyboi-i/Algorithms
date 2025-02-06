# Bipartite Matching

## Description
This algorithm solves a **farm tiling problem** using **bipartite matching**. It determines the **minimum cost** required to cover all barn tiles (`*`) in a grid using two types of coverings with different costs.

The problem is modeled as a **graph**, where barn tiles are treated as nodes, and valid tiling placements are represented as edges. **Depth-First Search (DFS) based bipartite matching** is used to find the optimal tiling configuration.

## How algorithm works
1. Parse the input grid and construct a **graph representation**:
   - Each barn tile (`*`) is a node.
   - Edges connect adjacent barn tiles, forming a bipartite graph.
2. If the **cost of placing two small tiles** is cheaper than a large tile, compute the direct cost.
3. Otherwise, use **DFS-based bipartite matching**:
   - Attempt to match each node using DFS.
   - Keep track of matched nodes in an auxiliary array.
   - Compute the final cost based on the number of matched pairs.

## Implementation Details
- **Graph Representation**:
  - Each barn tile is assigned a unique ID.
  - An adjacency list is used to store valid connections.
  - Nodes are partitioned into two sets (checkerboard pattern).

- **Matching Process**:
  - Unvisited nodes are explored using **DFS**.
  - If a matching is found, the node is marked as visited.
  - The algorithm continues until all possible matchings are found.

## Code Explanation
The C++ program performs the following steps:
1. **Reads Input**:
   - Grid dimensions (`height × width`).
   - Costs of **placing one large tile** (`cst1`) and **two small tiles** (`cst2`).
   - Grid representation (barn layout).
2. **Constructs the Graph**:
   - Identifies barn tiles (`*`).
   - Creates **edges** between adjacent barn tiles.
3. **Computes the Minimum Tiling Cost**:
   - If placing two small tiles is cheaper than a large tile, compute cost directly.
   - Otherwise, use **bipartite matching** via DFS to find the optimal pairing.

### Data Structures
- **`Edge`**: Represents an edge between two barn tiles.
- **`Graph`**: Manages adjacency lists, DFS-based matching, and cost calculation.

### Key Functions
- **`insert_edge(vector<string> farm)`**: Constructs the bipartite graph from the farm grid.
- **`DFS(int at)`**: Finds an augmenting path in the bipartite graph.
- **`match()`**: Computes the optimal tiling cost using DFS-based matching.

### Input format
<height> <width> <cst1> <cst2> \
<row_1> \
<row_2> \
...
<row_height>

Where:

- '*' represents a barn tile.
- . represents an empty space.

### Output format
The output consists of a single integer representing the minimum tiling cost.

## Complexity Analysis

- **Time Complexity**: O(V + E) in the worst case.  
- **Space Complexity**: O(V + E) due to adjacency list representation.  

### Example input:
2 3 3 2 \
.** \
.*.

### Example output:
5

