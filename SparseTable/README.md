# Sparse Table for Range Minimum Queries

## Overview
This project implements a **Sparse Table**, a data structure that efficiently answers **range minimum queries (RMQ)** and finds the **second minimum** in a given range. It preprocesses an array in `O(N log N)` time, allowing for constant-time `O(1)` queries.

## Features
- **Preprocessing in `O(N log N)`**
- **Query in `O(1)`** for range minimum
- **Finds the second smallest element** in a given range
- **Supports multiple queries efficiently**

## Implementation Details
- The **Sparse Table** is built using dynamic programming.
- The **Min function** finds the minimum in `O(1)` using precomputed values.
- The **MinIndex function** finds the index of the minimum element in a given range.
- The **SecondStat function** finds the second smallest element in the range.

## Complexity Analysis
- **Preprocessing:** `O(N log N)`
- **Query:** `O(1)`


## Usage

### Input Format
1. **First line:** Two integers:
   - `N` — number of elements in the array
   - `Q` — number of queries
2. **Second line:** `N` integers representing the array
3. **Next `Q` lines:** Each line contains two integers:
   - `L R` — query range `[L, R]` (1-based index)

### Output Format
For each query, output the **second smallest element** in the given range.

### Example

#### **Input**

10 3 \
1 2 3 4 5 6 7 8 9 10 \
1 2 \
1 10 \
2 7

## **Output**
2 \
2 \
3
