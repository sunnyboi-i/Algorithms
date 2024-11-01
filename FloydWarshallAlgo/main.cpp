#include <cstdint>
#include <iostream>
#include <vector>

struct Graph {
  std::vector<std::vector<int32_t>> adj;
  int32_t size;

  Graph(int32_t num) {
    adj.resize(num, std::vector<int32_t>(num));
    size = num;
  }

  void insert_edge(std::vector<std::vector<int32_t>> adj_m) { adj = adj_m; }

  void FloydWarshall() {
    std::vector<std::vector<int32_t>> res(size, std::vector<int32_t>(size, 0));
    for (int32_t i = 0; i < size; ++i) {
      for (int32_t j = 0; j < size; ++j) {
        res[i][j] = adj[i][j];
      }
    }
    for (int32_t k = 0; k < size; ++k) {
      for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
          res[i][j] = res[i][j] || (res[i][k] && res[k][j]);
        }
      }
    }
    for (int32_t i = 0; i < size; ++i) {
      for (int32_t j = 0; j < size; ++j) {
        std::cout << res[i][j] << ' ';
      }
      std::cout << '\n';
    }
  }
};

int main() {
  int32_t size = 0;
  std::cin >> size;
  Graph gr(size);
  std::vector<std::vector<int32_t>> adj(size, std::vector<int32_t>(size, 0));
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j) {
      int32_t bit = 0;
      std::cin >> bit;
      adj[i][j] = bit;
    }
  }
  gr.insert_edge(adj);
  gr.FloydWarshall();
}
