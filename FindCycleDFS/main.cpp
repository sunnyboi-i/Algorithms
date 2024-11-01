#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct Graph {
  int32_t size;
  std::vector<std::vector<int32_t>> adj;
  std::vector<int32_t> color;
  std::vector<int32_t> parent;
  int32_t pt1 = -1;
  int32_t pt2 = -1;
  Graph(int32_t num) {
    size = num;
    adj.resize(num);
    color.resize(num, 0);
    parent.resize(num, -1);
  }

  void insert_edge(int32_t pt1, int32_t pt2) { adj[pt1].push_back(pt2); }

  bool DFS(int32_t vertex) {
    color[vertex] = 1;
    for (uint32_t i = 0; i < adj[vertex].size(); ++i) {
      if (color[adj[vertex][i]] == 0) {
        parent[adj[vertex][i]] = vertex;
        if (DFS(adj[vertex][i])) {
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

  void hasCycle() {
    for (int32_t i = 0; i < size; ++i) {
      if (color[i] == 0 && DFS(i)) {
        break;
      }
    }
    if (pt1 == -1) {
      std::cout << "NO";
    } else {
      std::vector<int32_t> cycle;
      cycle.push_back(pt1);
      for (int32_t i = pt2; i != pt1; i = parent[i]) {
        cycle.push_back(i);
      }
			cycle.push_back(pt1);
			reverse(cycle.begin(), cycle.end());
			cycle.pop_back();
      std::cout << "YES"
                << "\n";
      for (uint32_t i = 0; i < cycle.size(); ++i) {
        std::cout << cycle[i] + 1 << " ";
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
  gr.hasCycle();
}
