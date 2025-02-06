#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Edge {
  Edge* residual;
  int32_t from;
  int32_t to;
  int32_t capacity;
  int32_t flow;
  int32_t pos;
  Edge(int32_t p1, int32_t p2, int32_t cap, int32_t position)
      : from{p1}, to{p2}, capacity{cap}, flow{0}, pos{position} {}

  int32_t Parent() { return from; }

  int32_t Pred() { return to; }

  void Augment(int32_t lim) {
    flow += lim;
    residual->flow -= lim;
  }
};

struct Graph {
  int32_t size;
  int32_t edges;
  int32_t sink;
  std::unordered_map<int32_t, std::vector<Edge*>> adj;
  std::vector<bool> visited;

  Graph(int32_t p1, int32_t p2) : size{p1}, edges{p2}, adj(p1) {
    sink = p1 - 1;
    visited.resize(p1, false);
  }

  void insert_edge(int32_t from, int32_t to, int32_t cap, int32_t position) {
    Edge* curr = new Edge(from, to, cap, position);
    Edge* tmp = new Edge(to, from, cap, position); 
    curr->residual = tmp;
    tmp->residual = curr;
    adj[from].push_back(curr);
    adj[to].push_back(tmp);
  }

  int32_t DFS(int32_t src, int32_t flow) {
    if (src == sink) {
      return flow;
    }
    visited[src] = true;
    for (auto& edge : adj[src]) {
      int32_t diff = edge->capacity - edge->flow;
      if (diff > 0 && !visited[edge->Pred()]) {
        int32_t lim = DFS(edge->Pred(), std::min(flow, diff));
        if (lim > 0) {
          edge->Augment(lim);
          return lim;
        }
      }
    }
    return 0;
  }

  int32_t FordFulkerson() {
    int32_t ans = 0;
    for (int32_t i = DFS(0, INT_MAX); i != 0; i = DFS(0, INT_MAX)) {
      std::fill(visited.begin(), visited.end(), false);
      ans += i;
    }
    return ans;
  }

  void MinCut() {
    int32_t ans = FordFulkerson();
    std::vector<Edge*> edg;
    for (int32_t i = 0; i < size; ++i) {
      for (auto it : adj[i]) {
        if (!visited[i] && visited[it->Pred()]) {
          edg.push_back(it);
        }
      }
    }
    std::sort(edg.begin(), edg.end(),
              [](Edge* p1, Edge* p2) { return p1->pos < p2->pos; });
    std::cout << edg.size() << ' ' << ans << '\n';
    for (auto it : edg) {
      std::cout << it->pos << ' ';
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int32_t size;
  int32_t edges;
  std::cin >> size >> edges;
  Graph gr(size, edges);
  int32_t pos = 1;
  while (edges > 0) {
    int32_t from, to, cap;
    std::cin >> from >> to >> cap;
    gr.insert_edge(from - 1, to - 1, cap, pos);
    edges -= 1;
    pos += 1;
  }
  gr.MinCut();
}
