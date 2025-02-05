# Anagram Substring Check

## Description
This algorithm checks whether a given string (`str_1`) is an anagram of any contiguous substring of another string (`str_2`).  
If such a substring exists, the program prints `"Yes"`; otherwise, it prints `"No"`.

## How the Algorithm Works

- A **hash map** stores character frequencies of `str_1`.
- The algorithm implements a **sliding window** approach to traverse `str_2`.
- A `matched` counter keeps track of how many characters are correctly matched.
- The **right pointer** (`right_pt`) expands the window.
- The **left pointer** (`left_pt`) shrinks the window when its size exceeds `str_1.length()`.
- **Matching condition**:  
  - If all characters from `str_1` match a substring in `str_2`, the program prints `"Yes"`.  
  - If no such match is found by the end of traversal, it prints `"No"`.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the length of `str_2`.
- **Space Complexity:** O(1) (Since the hash map stores at most 26 characters).

