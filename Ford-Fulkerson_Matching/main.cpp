#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

template <typename Vertex, typename Flow = int32_t>
struct Edge {
  Edge* residual;
  Vertex from;
  Vertex to;
  Flow capacity;
  Flow flow;

  Edge(Vertex p1, Vertex p2, Flow cap)
      : from{p1}, to{p2}, capacity{cap}, flow{0} {}

  Vertex Parent() { return from; }

  Vertex Pred() { return to; }

  void Augment(Flow lim) {
    flow += lim;
    residual->flow -= lim;
  }
};
template <typename Vertex, typename Flow,
          template <typename, typename> typename Edge = Edge>
struct Graph {
  using VertexT = Vertex;
  using FlowT = Flow;
  using EdgeT = Edge<VertexT, FlowT>;
  size_t size;
  size_t edges;
  VertexT sink;
  VertexT source;
  VertexT cn;
  std::unordered_map<VertexT, std::vector<EdgeT*>> adj;
  std::unordered_map<VertexT, bool> visited;

  Graph(size_t p1, size_t p2) : size{p1}, edges{p2}, adj(p1), visited(p1) {}

  void InsertEdge(VertexT from, VertexT to, Flow cap) {
    EdgeT* curr = new EdgeT(from, to, cap);
    EdgeT* tmp = new EdgeT(to, from, 0);
    curr->residual = tmp;
    tmp->residual = curr;
    adj[from].push_back(curr);
    adj[to].push_back(tmp);
    visited[from] = false;
    visited[to] = false;
  }

  std::vector<EdgeT*> GetNeighbors(VertexT from) { return adj[from]; }

  void SourceSink(VertexT pt1, VertexT pt2) {
    source = pt1;
    sink = pt2;
  }
  void Unvisit() {
    for (auto it = visited.begin(); it != visited.end(); ++it) {
      it->second = false;
    }
  }

  void GetConst(int32_t cnst) { cn = cnst; }
  VertexT Sink() { return sink; }
  VertexT Source() { return source; }
};

template <typename Vertex = size_t, typename Flow = int32_t>
Flow DFS(Graph<Vertex, Flow, Edge>& gr, Vertex src, Flow flow) {
  if (src == gr.Sink()) {
    return flow;
  }
  gr.visited[src] = true;
  for (auto& edge : gr.GetNeighbors(src)) {
    Flow diff = edge->capacity - edge->flow;
    if (diff > 0 && !gr.visited[edge->Pred()]) {
      Flow lim = DFS(gr, edge->Pred(), std::min(flow, diff));
      if (lim > 0) {
        edge->Augment(lim);
        return lim;
      }
    }
  }
  return 0;
}

template <typename Vertex = size_t, typename Flow = int32_t>
int32_t FordFulkerson(Graph<Vertex, Flow, Edge>& gr) {
  int32_t ans = 0;
  Vertex src = gr.Source();
  for (int32_t i = DFS(gr, src, INT_MAX); i != 0; i = DFS(gr, src, INT_MAX)) {
    gr.Unvisit();
    ans += i;
  }
  return ans;
}

template <typename Vertex = size_t, typename Flow = int32_t>
Graph<Vertex, Flow, Edge> Read() {
  size_t left;
  size_t right;
  int32_t def_flow = 1;
  std::cin >> left >> right;
  size_t my_c = std::max(left, right);

  std::vector<std::pair<size_t, std::vector<size_t>>> ans;

  size_t tmp = 0;
  size_t edge_c = 0;
  size_t vert_c = 0;
  std::set<size_t> right_s;

  while (tmp < left) {
    size_t variable = 1;
    std::vector<size_t> line;
    while (variable != 0) {
      std::cin >> variable;
      if (variable != 0) {
        line.push_back(variable + my_c);
        right_s.insert(variable + my_c);
        edge_c += 1;
      }
    }
    ans.push_back({tmp, line});
    tmp += 1;
  }

  edge_c += left + right;
  vert_c += left + right + 2;

  Graph<size_t, int32_t, Edge> gr(vert_c, edge_c);
  gr.GetConst(my_c);

  for (size_t i = 0; i < ans.size(); ++i) {
    for (size_t j = 0; j < ans[i].second.size(); ++j) {
      gr.InsertEdge(ans[i].first, ans[i].second[j], def_flow);
    }
  }

  gr.SourceSink(vert_c + my_c, vert_c + my_c + 1);
  for (auto it = right_s.begin(); it != right_s.end(); ++it) {
    gr.InsertEdge(*it, gr.sink, def_flow);
  }
  for (size_t i = 0; i < ans.size(); ++i) {
    gr.InsertEdge(gr.source, ans[i].first, def_flow);
  }
  return gr;
}

template <typename Vertex = size_t, typename Flow = int32_t>
std::vector<Edge<Vertex, Flow>> Answer(Graph<Vertex, Flow, Edge>& gr) {
  FordFulkerson<Vertex, Flow>(gr);
  std::vector<Edge<Vertex, Flow>> res;

  for (auto& it : gr.adj) {
    if (it.first != gr.source || it.first != gr.sink) {
      for (size_t i = 0; i < it.second.size(); ++i) {
        Edge curr = *it.second[i];
        if (curr.Parent() != gr.source && curr.Pred() != gr.sink) {
          if (curr.Parent() >= 0 && curr.Pred() >= 0) {
            if (curr.flow == 1) {
              curr.from += 1;
              curr.to -= gr.cn;
              res.push_back(curr);
            }
          }
        }
      }
    }
  }
  return res;
}

template <typename Vertex = size_t, typename Flow = int32_t>
void Print(std::vector<Edge<Vertex, Flow>>& ans) {
  std::cout << ans.size() << '\n';
  for (auto& it : ans) {
    std::cout << it.Parent() << ' ' << it.Pred() << '\n';
  }
}

int main() {
  Graph<size_t, int32_t, Edge> gr = Read<size_t, int32_t>();
  std::vector<Edge<size_t, int32_t>> ans = Answer<size_t, int32_t>(gr);
  Print<size_t, int32_t>(ans);
}
