#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Edge {
  int32_t from;
  int32_t to;
  Edge(int32_t pt1, int32_t pt2) {
    from = pt1;
    to = pt2;
  }
  int32_t Parent() { return from; }
  int32_t Pred() { return to; }
};

struct Graph {
  int32_t size;
  int32_t hgt;
  int32_t wdth;
  int32_t bcnt;
  int32_t cst1;
  int32_t cst2;
  std::unordered_map<int32_t, std::vector<Edge>> adj;
  std::unordered_map<int32_t, int32_t> next;
  std::unordered_map<int32_t, bool> visited;

  Graph(int32_t sz, int32_t pt1, int32_t pt2, int32_t p1, int32_t p2)
      : size(sz),
        hgt(pt1),
        wdth(pt2),
        bcnt{0},
        cst1(p1),
        cst2(p2),
        adj(sz),
        next(sz),
        visited(sz) {
    for (int32_t i = 0; i < sz; ++i) {
      visited[i] = false;
      next[i] = -1;
    }
  }

  void unvisit() {
    for (int32_t i = 0; i < size; ++i) {
      visited[i] = false;
    }
  }
  int32_t DFS(int32_t at) {
    if (visited[at] == true) {
      return 0;
    }

    visited[at] = true;
    for (auto it : adj[at]) {
      int32_t op = it.Pred();
      if (next[op] == -1 || DFS(next[op])) {
        next[op] = at;
        return 1;
      }
    }
    return 0;
  }

  void insert_edge(std::vector<std::string> farm) {
    for (int32_t i = 0; i < hgt; ++i) {
      for (int32_t j = 0; j < wdth; ++j) {
        if (farm[i][j] == '.') {
          continue;
        }
        bcnt += 1;
        if ((i + j) % 2 == 1) {
          continue;
        }
        int32_t id = i * wdth + j;
        if (j > 0 && farm[i][j - 1] == '*') {
          Edge curr(id, id - 1);
          adj[id].push_back(curr);
        }
        if (j < wdth - 1 && farm[i][j + 1] == '*') {
          Edge curr(id, id + 1);
          adj[id].push_back(curr);
        }
        if (i > 0 && farm[i - 1][j] == '*') {
          Edge curr(id, id - wdth);
          adj[id].push_back(curr);
        }
        if (i < hgt - 1 && farm[i + 1][j] == '*') {
          Edge curr(id, id + wdth);
          adj[id].push_back(curr);
        }
      }
    }
  }

  void match() {
    if (2 * cst2 <= cst1) {
      int32_t res = cst2 * bcnt;
      std::cout << res;
      return;
    }
    for (int32_t i = 0; i < hgt; ++i) {
      for (int32_t j = 0; j < wdth; ++j) {
        unvisit();
        DFS(i * wdth + j);
      }
    }
    int32_t res = 0;
    for (int32_t i = 0; i < size; ++i) {
      if (next[i] != -1) {
        res += 1;
      }
    }
    int32_t ans = cst1 * res + (bcnt - 2 * res) * cst2;
    std::cout << ans;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int32_t pt1, pt2;
  int32_t p1, p2;
  std::cin >> pt1 >> pt2 >> p1 >> p2;

  std::vector<std::string> farm;
  for (int32_t i = 0; i < pt1; ++i) {
    std::string var;
    std::cin >> var;
    farm.push_back(var);
  }
  int32_t dim = pt1 * pt2;
  Graph gr(dim, pt1, pt2, p1, p2);
  gr.insert_edge(farm);
  gr.match();
}
