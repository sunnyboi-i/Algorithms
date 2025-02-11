# String Reduction Algorithm

This repository contains an implementation of an algorithm to solve the **string reduction problem**. The problem involves concatenating a sequence of words by removing the longest prefix of the next word that matches the suffix of the current result. 

## Problem Description


- Given two words `S` and `T`, the result of the reduction is the concatenation of `S` and `T`, with the longest prefix of `T` that matches a suffix of `S` removed.
- For example, if `S = "banana"` and `T = "nana"`, the result is `"banana"` with the overlapping part removed.

The goal is to process a sequence of words in order, applying the reduction operation iteratively, and output the final merged word.

## Implementation Details

### Key Components

1. **Prefix Function (`Pref`)**:
   - Computes the longest prefix that is also a suffix for a given string.
   - Used to find the overlapping region between two strings.

2. **Substring Extraction (`Substring`)**:
   - Extracts substrings from the input, delimited by spaces.

3. **Result Construction (`Result`)**:
   - Iteratively applies the reduction operation to merge the words into a single string.

4. **Main Function**:
   - Reads the input, processes the words, and outputs the final merged string.

### Algorithm Steps

1. **Input**:
   - The number of words `n`.
   - A sequence of `n` words separated by spaces.

2. **Processing**:
   - Start with the first word as the initial result.
   - For each subsequent word, compute the longest prefix that matches a suffix of the current result using the prefix function.
   - Append the non-overlapping part of the word to the result.

3. **Output**:
   - The final merged string after applying the reduction operation to all words.

## Input and Output Format

### Input Format

The input consists of:
1. The first line contains an integer `n` (1 ≤ n ≤ 10^5), representing the number of words.
2. The second line contains `n` words separated by spaces. Each word consists of lowercase English letters.

#### Example Input
3
banana nana nanaba
#### Example Output
bananaba

#### Example Input
4
papa pama mama mapapa

#### Example Output
papamamapapa
