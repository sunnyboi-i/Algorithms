# Multidimensional Fenwick Tree (Binary Indexed Tree)

## Overview
This project implements a **3D Fenwick Tree (Binary Indexed Tree)**, which supports efficient updates and range sum queries in a three-dimensional space. The problem models a scenario where value in specific cell could have been changed, then asked for the value in the range.

## Features
- **Supports updates (`Add`) in `O(log^3 N)`**
- **Efficient range sum queries (`PrefixSum`) in `O(log^3 N)`**
- **Handles 3D range sum queries efficiently**
- **Memory-efficient representation using a Fenwick Tree**

## Problem Statement
Given **cube of size `N × N × N`**, divided into **1 × 1 × 1** sub-cubes. The following operations are possible:

1. **Values appear or disappear in a specific sub-cube.**
2. **Query is made for the number of values in a subregion of the cube.**
3. **The observation ends.**

## Input Format
- **First line:** A single integer `N` (`1 ≤ N ≤ 128`), the size of the cubic space.
- **Next lines:** Queries, with three possible formats:
  - `1 x y z k` — **Modify value** at position `(x, y, z)` by `k` (`-20000 ≤ k ≤ 20000`).
  - `2 x1 y1 z1 x2 y2 z2` — **Count values** in the region:
    ```
    x1 ≤ x ≤ x2
    y1 ≤ y ≤ y2
    z1 ≤ z ≤ z2
    ```
  - `3` — **End the program** (appears only once, as the last input).

### Constraints
- **Coordinates (`x, y, z`)**: `0 ≤ x, y, z < N`
- **Queries (`m`)**: At most `10^6` queries.

## Output Format
For each **range sum query** (`2 x1 y1 z1 x2 y2 z2`), output a single integer — the total number of stars in the given region.

## Implementation Details
- **`Add(x, y, z, value)`** updates the tree at position `(x, y, z)`.
- **`PrefixSum(x, y, z)`** computes the sum from `(0,0,0)` to `(x, y, z)`.
- **Range sum queries** are computed using an **inclusion-exclusion principle**.

## Complexity Analysis
- **Update (`Add`)**: `O(log^3 N)`
- **Query (`PrefixSum`)**: `O(log^3 N)`

## Example

#### **Input**
2 \
2 1 1 1 1 1 1 \
1 0 0 0 1 \
1 0 1 0 3 \
2 0 0 0 0 0 0 \
2 0 0 0 0 1 0 \
1 0 1 0 -2 \
2 0 0 0 1 1 1 \
3

#### **Output**
0 \
1 \
4 \
2 
