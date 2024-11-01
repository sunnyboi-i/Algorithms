#include <limits.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
struct Graph {
  int32_t size;
  int32_t edges_c;
  std::vector<std::vector<int32_t>> edges;
  std::vector<int32_t> parent;
  std::vector<int32_t> dist;

  Graph(int32_t num) {
    size = num;
    edges_c = 0;
    parent.resize(num, -1);
    dist.resize(num, 100000);
  }

  void count_edges(const std::vector<std::vector<int32_t>>& adj) {
    for (int32_t i = 0; i < size; ++i) {
      for (int32_t j = 0; j < size; ++j) {
        if (adj[i][j] != 100000) {
          edges_c += 1;
        }
      }
    }
    edges.reserve(edges_c);
    for (int32_t i = 0; i < size; ++i) {
      for (int32_t j = 0; j < size; ++j) {
        if (adj[i][j] != 100000) {
          int32_t weight = adj[i][j];
          edges.push_back({i, j, weight});
        }
      }
    }
  }

  void detectCycle() {
    dist[0] = 0;
    int32_t flag = 0;
    for (int32_t i = 0; i < size; i++) {
      flag = -1;
      for (int32_t j = 0; j < edges_c; j++) {
        if (dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]) {
          dist[edges[j][1]] =
              std::max(INT_MIN, dist[edges[j][0]] + edges[j][2]);
          parent[edges[j][1]] = edges[j][0];
          flag = edges[j][1];
        }
      }
    }

    if (flag == -1) {
      std::cout << "NO\n";
    } else {
      int32_t pt = flag;
      for (int32_t i = 0; i < size; ++i) {
        pt = parent[pt];
      }
      std::vector<int32_t> cycle;
      for (int32_t cur = pt;; cur = parent[cur]) {
        cycle.push_back(cur);
        if (cur == pt && cycle.size() > 1) {
          break;
        }
      }
      std::reverse(cycle.begin(), cycle.end());
      std::cout << "YES\n" << cycle.size() << "\n";
      for (auto it : cycle) {
        std::cout << it + 1 << " ";
      }
    }
  }
};

int main() {
  int32_t size = 0;
  std::cin >> size;
  Graph gr(size);
  std::vector<std::vector<int32_t>> adj_m(size,
                                          std::vector<int32_t>(size));
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j) {
      int32_t var = 0;
      std::cin >> var;
      adj_m[i][j] = var;
    }
  }
  gr.count_edges(adj_m);
  gr.detectCycle();
}

