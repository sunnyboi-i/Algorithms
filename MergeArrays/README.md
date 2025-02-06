# Merge K Sorted Arrays

### Description

This algorithm merges multiple sorted arrays into a single sorted array using a pairwise merging approach. It repeatedly merges two arrays at a time until only one sorted array remains.

### Implementation

- **MergeTwo**: Merges two sorted arrays into a single sorted array.
- **Merge**: Merges all arrays by repeatedly merging pairs.
- **Reader**: Reads input arrays.
- **Printer**: Outputs the final sorted array.

### Usage

1. Input the number of sorted arrays.
2. Input each array with its size followed by its elements.
3. The program outputs a single merged sorted array.


### Complexity Analysis

- **Time Complexity**: O(N log K), where N is the total number of elements and K is the number of sorted arrays.
- **Space Complexity**: O(N) due to storing the merged arrays.

