# Longest Valid Parentheses Subsequence

## Description
This algorithm finds the **length of the longest valid parentheses subsequence** in a given string.  
A valid subsequence consists of properly matched opening `'('` and closing `')'` parentheses.

## How the Algorithm Works

- The algorithm uses **two traversal passes** (left-to-right and right-to-left) to determine the longest valid subsequence.
- It maintains two counters:
  - **`left_pt`**: Counts opening parentheses `'('`.
  - **`right_pt`**: Counts closing parentheses `')'`.
- It iterates through the string:
  - If parentheses are balanced, the maximum valid subsequence length is updated.
  - If one type of parentheses exceeds the other, counters are reset.
- The function `Subsequence()` calls `Traverse()` twice:
  - **Left-to-right pass:** Ensures forward balancing.
  - **Right-to-left pass:** Ensures backward balancing.

## Input Format
- A single string consisting of `'('` and `')'` characters.

## Output Format
- A single integer representing the length of the longest valid parentheses subsequence.

## Complexity Analysis
- **Time Complexity:** O(N), where N is the length of the string.
- **Space Complexity:** O(1).

