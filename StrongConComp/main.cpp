#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct Graph {
  int32_t size;
  std::vector<std::vector<int32_t>> adj, adj_t;
  std::vector<int32_t> components, order;
  std::vector<bool> visited;

  Graph(int32_t size)
      : size(size),
        adj(size),
        adj_t(size),
        components(size, -1),
        visited(size, false) {}

  void addEdge(int32_t pt1, int32_t pt2) {
    adj[pt1].push_back(pt2);
    adj_t[pt2].push_back(pt1);
  }

  void DFS1(int32_t vrt) {
    visited[vrt] = true;
    for (int32_t adjacentNode : adj[vrt]) {
      if (!visited[adjacentNode]) {
        DFS1(adjacentNode);
      }
    }
    order.push_back(vrt);
  }

  void DFS2(int32_t vrt, int32_t pt0) {
    visited[vrt] = true;
    components[vrt] = pt0;
    for (int32_t u : adj_t[vrt]) {
      if (!visited[u]) {
        DFS2(u, pt0);
      }
    }
  }

  void find_comp() {
    for (int32_t vrt = 0; vrt < size; ++vrt) {
      if (!visited[vrt]) {
        DFS1(vrt);
      }
    }

    visited.assign(size, false);

    int32_t count = 0;
    for (int32_t i = size - 1; i >= 0; --i) {
      int32_t vrt = order[i];
      if (!visited[vrt]) {
        DFS2(vrt, count++);
      }
    }

    std::cout << count << "\n";

    for (int32_t ind : components) {
      std::cout << ind + 1 << " ";
    }
  }
};

int main() {
  int32_t size, numberOfEdges;
  std::cin >> size >> numberOfEdges;

  Graph graph(size);

  for (int32_t i = 0; i < numberOfEdges; ++i) {
    int32_t pt1, pt2;
    std::cin >> pt1 >> pt2;
    graph.addEdge(pt1 - 1, pt2 - 1);
  }

  graph.find_comp();

  return 0;
}
