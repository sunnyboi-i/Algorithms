#include <cstdint>
#include <iostream>
#include <vector>
struct Graph {
  int32_t size;
  int32_t verts;
  std::vector<int32_t> dist;
  std::vector<std::vector<int32_t> > edges;

  Graph(int32_t p1, int32_t p2) {
    size = p1;
    verts = p2;
    dist.resize(p1, 30000);
    edges.resize(p2, std::vector<int32_t>(3));
  }
  void insert_edge(int32_t from, int32_t to, int32_t weight) {
    edges.push_back({from, to, weight});
  }
  void FordBellman() {
    dist[0] = 0;
    for (int32_t i = 0; i < size - 1; ++i) {
      for (auto it : edges) {
        int32_t from = it[0];
        int32_t to = it[1];
        int32_t wgth = it[2];
        if (dist[from] != 30000 && dist[from] + wgth < dist[to]) {
          dist[to] = dist[from] + wgth;
        }
      }
    }
    for (auto it : edges) {
      int32_t from = it[0];
      int32_t to = it[1];
      int32_t wgth = it[2];
      if (dist[from] != 30000 && dist[from] + wgth < dist[to]) {
        return;
      }
    }
    for (int32_t i = 0; i < size; i++) {
      std::cout << dist[i] << ' ';
    }
  }
};

int main() {
  int32_t p1 = 0;
  int32_t p2 = 0;
  std::cin >> p1 >> p2;
  Graph gr(p1, p2);
  for (int32_t i = 0; i < p2; ++i) {
    int32_t from = 0;
    int32_t to = 0;
    int32_t weight = 0;
    std::vector<int32_t> edg;
    std::cin >> from >> to >> weight;
    gr.insert_edge(from - 1, to - 1, weight);
  }
  gr.FordBellman();
}
