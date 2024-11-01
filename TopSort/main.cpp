#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct Graph {
  int32_t size;
  std::vector<std::vector<int32_t>> adj;
  std::vector<int32_t> color;
  std::vector<int32_t> parent;
  std::vector<bool> visited;
  std::vector<int32_t> top_sorted;
  int32_t pt1 = -1;
  int32_t pt2 = -1;
  Graph(int32_t num) {
    size = num;
    adj.resize(num);
    color.resize(num, 0);
    parent.resize(num, -1);
    visited.resize(num, 0);
  }

  void insert_edge(int32_t pt1, int32_t pt2) { adj[pt1].push_back(pt2); }

  bool DFS_b(int32_t vertex) {
    color[vertex] = 1;
    for (uint32_t i = 0; i < adj[vertex].size(); ++i) {
      if (color[adj[vertex][i]] == 0) {
        parent[adj[vertex][i]] = vertex;
        if (DFS_b(adj[vertex][i])) {
          return true;
        }
      } else if (color[adj[vertex][i]] == 1) {
        pt2 = vertex;
        pt1 = adj[vertex][i];
        return true;
      }
    }
    color[vertex] = 2;
    return false;
  }
  void DFS_v(int32_t vertex) {
    visited[vertex] = true;
    for (uint32_t i = 0; i < adj[vertex].size(); ++i) {
      if (!visited[adj[vertex][i]]) {
        DFS_v(adj[vertex][i]);
      }
    }
    top_sorted.push_back(vertex);
  }

  bool hasNoCycle() {
    for (int32_t i = 0; i < size; ++i) {
      if (color[i] == 0 && DFS_b(i)) {
        break;
      }
    }
    if (pt1 == -1) {
      return true;
    }
    return false;
  }
  void topological_sort() {
    if (hasNoCycle()) {
      top_sorted.clear();
      for (int32_t i = 0; i < size; ++i) {
        if (!visited[i]) {
          DFS_v(i);
        }
      }
      std::reverse(top_sorted.begin(), top_sorted.end());
      for (uint32_t j = 0; j < top_sorted.size(); ++j) {
        std::cout << top_sorted[j] + 1 << ' ';
      }
      return;
    }
    std::cout << -1;
    return;
  }
};

int main() {
  int32_t size = 0;
  int32_t edges = 0;
  std::cin >> size >> edges;
  Graph gr(size);
  int32_t pt1 = 0;
  int32_t pt2 = 0;
  for (int i = 0; i < edges; ++i) {
    std::cin >> pt1 >> pt2;
    gr.insert_edge(pt1 - 1, pt2 - 1);
  }
  gr.topological_sort();
}
