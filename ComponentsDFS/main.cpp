#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct Graph {
  int32_t size;
  std::vector<std::vector<int32_t>> adj;
  std::vector<bool> visited;
  std::vector<std::vector<int32_t>> components;
  std::vector<int32_t> component;

  Graph(int32_t num) {
    size = num;
    adj.resize(num);
    visited.resize(num, 0);
  }

  void insert_edge(int32_t pt1, int32_t pt2) {
    adj[pt1].push_back(pt2);
    adj[pt2].push_back(pt1);
  }

  void DFS(int32_t vertex) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (uint32_t i = 0; i < adj[vertex].size(); ++i) {
      if (visited[adj[vertex][i]] == 0) {
        DFS(adj[vertex][i]);
      }
    }
  }

  void component_build() {
    for (uint32_t i = 0; i < size; ++i) {
      if (visited[i] == 0) {
        component.clear();
        DFS(i);
        components.push_back(component);
      }
    }
  }
  void printComponent() {
    std::cout << components.size() << ' ';
    for (uint32_t i = 0; i < components.size(); ++i) {
      std::cout << "\n" << components[i].size() << "\n";
      for (uint32_t j = 0; j < components[i].size(); ++j) {
        std::cout << components[i][j] + 1 << ' ';
      }
    }
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
  gr.component_build();
  gr.printComponent();
}
