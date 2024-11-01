#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

struct Graph {
  std::vector<std::vector<int32_t>> adj;
  std::vector<int32_t> tin;
  std::vector<int32_t> min_time;
  std::vector<bool> visited;
  std::set<int32_t> art_p;
  int32_t timer;

  Graph(int32_t num) {
    adj.resize(num);
    tin.assign(num, -1);
    min_time.assign(num, -1);
    visited.assign(num, false);
    timer = 0;
  }

  void insert_edge(int32_t pt1, int32_t pt2) {
    adj[pt1].push_back(pt2);
    adj[pt2].push_back(pt1);
  }

  void dfs(int32_t pt1, int32_t pt2 = -1) {
    visited[pt1] = true;
    tin[pt1] = min_time[pt1] = timer++;
    int32_t children = 0;
    for (int32_t vrt : adj[pt1]) {
      if (vrt == pt2) continue;

      if (visited[vrt]) {
        min_time[pt1] = std::min(min_time[pt1], tin[vrt]);
      } else {
        dfs(vrt, pt1);
        min_time[pt1] = std::min(min_time[pt1], min_time[vrt]);
        if (min_time[vrt] >= tin[pt1] && pt2 != -1) {
          art_p.insert(pt1);
        }
        children++;
      }
    }
    if (pt2 == -1 && children > 1) {
      art_p.insert(pt1);
    }
  }

  void find_art_p() {
    for (int32_t i = 0; i < adj.size(); ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
  }
};

int main() {
  int32_t size = 0;
  int32_t edges = 0;
  std::cin >> size >> edges;

  Graph graph(size);

  for (int32_t i = 0; i < edges; ++i) {
    int32_t pt1 = 0;
    int32_t pt2 = 0;
    std::cin >> pt1 >> pt2;
    pt1 -= 1;
    pt2 -= 1;
    graph.insert_edge(pt1, pt2);
  }

  graph.find_art_p();

  std::cout << graph.art_p.size() << std::endl;
  for (int32_t point : graph.art_p) {
    std::cout << point + 1 << std::endl;
  }
}
