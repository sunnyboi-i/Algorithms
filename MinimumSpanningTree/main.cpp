#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

template <typename Element = int32_t>
struct UnionFind {
  std::unordered_map<Element, Element> id;
  std::unordered_map<Element, size_t> arr;
  size_t size;

  UnionFind(size_t num) : size(num) {}

  void Insert(Element element) {
    id[element] = element;
    arr[element] = 1;
    size++;
  }

  Element Find(Element pt) {
    Element root = pt;
    while (root != id[root]) {
      root = id[root];
    }
    while (pt != root) {
      Element next = id[pt];
      id[pt] = root;
      pt = next;
    }
    return root;
  }

  bool Connected(Element pt1, Element pt2) { return Find(pt1) == Find(pt2); }

  void UnionF(Element pt1, Element pt2) {
    Element root_p = Find(pt1);
    Element root_q = Find(pt2);
    if (root_p == root_q) {
      return;
    }
    if (arr[root_p] < arr[root_q]) {
      arr[root_q] += arr[root_p];
      id[root_p] = root_q;
    } else {
      arr[root_p] += arr[root_q];
      id[root_q] = root_p;
    }
  }
};

template <typename Vertex, typename Weight>
struct Edge {
  Vertex pt1;
  Vertex pt2;
  Weight wg;

  Edge(Vertex p1, Vertex p2, Weight wgt) : pt1{p1}, pt2{p2}, wg{wgt} {}
  Vertex Parent() { return pt1; }
  Vertex Pred() { return pt2; }
  Weight GetWeight() { return wg; }
};

struct Compare {
  bool operator()(Edge<size_t, size_t>& pt1, Edge<size_t, size_t>& pt2) {
    return pt1.GetWeight() > pt2.GetWeight();
  }
};

template <typename Vertex = size_t, typename Weight = size_t,
          template <typename, typename> typename Edge = Edge>
class Graph {
 public:
  using VertexT = Vertex;
  using WeightT = Weight;
  using EdgeT = Edge<VertexT, WeightT>;
  size_t size;
  size_t edge_cnt;
  std::unordered_map<VertexT, std::vector<EdgeT>> adj;
  std::vector<EdgeT> edges;
  Graph(size_t num, size_t edg) : size(num), edge_cnt(edg), adj(num) {}
  size_t GetNumVertices() const { return size; }
  size_t GetNumEdges() const { return edge_cnt; }
  void InsertEdge(std::vector<EdgeT>& edge_list) {
    for (auto& it : edge_list) {
      adj[it.Parent()].push_back(it);
    }
  }

  void EdgeList(std::vector<EdgeT>& edge_list) { edges = edge_list; }
  std::vector<EdgeT>& GetNeighbors(VertexT vertex) { return adj[vertex]; }

  int32_t MST() {
    std::sort(edges.begin(), edges.end(), Compare());
    std::priority_queue<EdgeT, std::vector<EdgeT>, Compare> pq;
    for (const auto& edge : edges) {
      pq.push(edge);
    }
    UnionFind<VertexT> set(size);
    for (size_t i = 0; i < size; ++i) {
      set.Insert(i);
    }

    size_t res = 0;
    size_t added_edges = 0;
    while (!pq.empty()) {
      EdgeT edge = pq.top();
      pq.pop();
      if (set.Connected(edge.Parent(), edge.Pred())) {
        continue;
      }
      set.UnionF(edge.Parent(), edge.Pred());
      res += edge.GetWeight();
      added_edges++;
      if (added_edges == size - 1) {
        break;
      }
    }
    return res;
  }
};

int main() {
  size_t size = 0;
  size_t edges = 0;
  std::cin >> size >> edges;
  size_t num = edges;
  std::vector<Edge<size_t, size_t>> edg;
  while (edges > 0) {
    size_t from;
    size_t to;
    size_t weight;
    std::cin >> from >> to >> weight;
    Edge<size_t, size_t> edge(from, to, weight);
    edg.push_back(edge);
    edges -= 1;
  }
  Graph<size_t, size_t, Edge> gr(size, num);
  gr.EdgeList(edg);
  size_t mst = gr.MST();
  std::cout << mst;
}

