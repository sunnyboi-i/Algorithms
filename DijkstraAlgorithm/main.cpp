#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

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
namespace DefaultDist {
const size_t kDefaultDist = 2009000999;
}
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
  Graph(size_t num, size_t edg) : size(num), edge_cnt(edg), adj(num) {}
  size_t GetNumVertices() const { return size; }
  size_t GetNumEdges() const { return edge_cnt; }
  void InsertEdge(std::vector<EdgeT>& edge_list) {
    for (auto& it : edge_list) {
      adj[it.Parent()].push_back(it);
    }
  }

  std::vector<EdgeT>& GetNeighbors(VertexT vertex) { return adj[vertex]; }
};

template <typename Graph>
class Visitor {
 public:
  virtual void ExamineVertex(typename Graph::VertexT& vrt, size_t dist) = 0;
  virtual ~Visitor() = default;
};

template <typename Graph>
class VisitorD : public Visitor<Graph> {
 public:
  using EdgeT = typename Graph::EdgeT;
  using VertexT = typename Graph::VertexT;

  void Visit(VertexT vrt) { Visited_[vrt] = true; }

  bool Visited(VertexT vrt) { return Visited_.find(vrt) != Visited_.end(); }

  void Ancestor(EdgeT edg) { ancest_[edg.Pred()] = edg.Parent(); }

  void ExamineVertex(VertexT& vrt, size_t dist) override { dist_[vrt] = dist; }

  size_t GetDist(VertexT vrt) { return dist_[vrt]; }

 private:
  std::unordered_map<VertexT, VertexT> ancest_;
  std::unordered_map<VertexT, size_t> dist_;
  std::unordered_map<VertexT, bool> Visited_;
};

template <typename Vertex = size_t, typename Weight = size_t>
void Dijkstra(Graph<Vertex, Weight, Edge>& graph, Vertex start,
              VisitorD<Graph<Vertex, Weight, Edge>>& visitor) {
  using VertexT = Vertex;
  using WeightT = Weight;
  std::priority_queue<std::pair<WeightT, VertexT>,
                      std::vector<std::pair<WeightT, VertexT>>,
                      std::greater<std::pair<WeightT, VertexT>>>
      pq;

  for (size_t i = 0; i < graph.GetNumVertices(); ++i) {
    if (i != start) {
      visitor.ExamineVertex(i, DefaultDist::kDefaultDist);
    }
  }
  visitor.ExamineVertex(start, 0);
  pq.push({0, start});

  while (!pq.empty()) {
    VertexT vertex = pq.top().second;
    WeightT current_dist = pq.top().first;
    pq.pop();
    if (visitor.Visited(vertex)) {
      continue;
    }
    visitor.Visit(vertex);
    for (const auto& neighbor : graph.GetNeighbors(vertex)) {
      VertexT neighbor_vertex = neighbor.pt2;
      WeightT weight = neighbor.wg;
      visitor.Ancestor(neighbor);
      if (current_dist + weight < visitor.GetDist(neighbor_vertex)) {
        visitor.ExamineVertex(neighbor_vertex, current_dist + weight);
        pq.push({visitor.GetDist(neighbor_vertex), neighbor_vertex});
      }
    }
  }

  for (size_t i = 0; i < graph.GetNumVertices(); ++i) {
    std::cout << visitor.GetDist(i) << ' ';
  }
}

int main() {
  int32_t num = 0;
  std::cin >> num;

  for (int32_t i = 0; i < num; ++i) {
    size_t size = 0;
    size_t edges = 0;
    std::vector<Edge<size_t, size_t>> edg;
    std::cin >> size >> edges;
    for (size_t i = 0; i < edges; ++i) {
      size_t from = 0;
      size_t to = 0;
      size_t weight = 0;
      std::cin >> from >> to >> weight;
      Edge<size_t, size_t> elem0(from, to, weight);
      Edge<size_t, size_t> elem1(to, from, weight);
      edg.push_back(elem0);
      edg.push_back(elem1);
    }
    Graph<size_t, size_t, Edge> gr(size, edges);
    gr.InsertEdge(edg);
    VisitorD<Graph<size_t, size_t, Edge>> visitor;
    size_t start = 0;
    std::cin >> start;
    Dijkstra(gr, start, visitor);
  }
}
