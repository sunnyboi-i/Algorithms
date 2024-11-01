#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

struct Graph {
  int64_t size;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> adj;
  std::vector<int64_t> dist;
  std::vector<bool> visited;
  std::unordered_set<int64_t> infectedSet;

  Graph(int64_t num, int64_t infected_num) {
    size = num;
    adj.resize(num);
    visited.resize(num, false);
    dist.resize(num, INT64_MAX);
  }

  void insert_edge(int64_t from, int64_t to, int64_t weight) {
    adj[from].push_back({to, weight});
    adj[to].push_back({from, weight});
  }

  void get_inf(std::vector<int64_t>& vir) {
    infectedSet.insert(vir.begin(), vir.end());
  }

  void Djikstra(int64_t begin, int64_t end) {
    std::priority_queue<std::pair<int64_t, int64_t>,
                        std::vector<std::pair<int64_t, int64_t>>,
                        std::greater<std::pair<int64_t, int64_t>>>
        pq;
    dist[end] = 0;
    pq.push({0, end});
    while (!pq.empty()) {
      int64_t vertex = pq.top().second;
      int64_t dst = pq.top().first;
      pq.pop();
      if (visited[vertex]) {
        continue;
      }
      visited[vertex] = true;
      for (const auto& it : adj[vertex]) {
        int64_t weight = it.second;
        int64_t vrt = it.first;
        if (dst + weight < dist[vrt]) {
          dist[vrt] = dst + weight;
          pq.push({dist[vrt], vrt});
        }
      }
    }

    int64_t vir_dist = INT64_MAX;
    for (int64_t i = 0; i < dist.size(); ++i) {
      if (infectedSet.count(i) > 0) {
        vir_dist = std::min(vir_dist, dist[i]);
      }
    }

    int64_t you = dist[begin];
    if (vir_dist != INT64_MAX && you != INT64_MAX) {
      if (you < vir_dist) {
        std::cout << you << '\n';
      } else {
        std::cout << -1 << '\n';
      }
    } else if (vir_dist == INT64_MAX && you != INT64_MAX) {
      std::cout << you << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }
};

int main() {
  int64_t size = 0, edges = 0, num = 0;
  std::cin >> size >> edges >> num;
  Graph gr(size, num);

  std::vector<int64_t> infected(num);
  for (int64_t j = 0; j < num; ++j) {
    int64_t vert = 0;
    std::cin >> vert;
    infected[j] = vert - 1;
  }

  for (int64_t j = 0; j < edges; ++j) {
    int64_t from = 0, to = 0, weight = 0;
    std::cin >> from >> to >> weight;
    gr.insert_edge(from - 1, to - 1, weight);
  }
  gr.get_inf(infected);
  int64_t begin = 0, end = 0;
  std::cin >> begin >> end;
  gr.Djikstra(begin - 1, end - 1);
}

