#include <iostream>
#include <string>
#include <vector>

struct UnionFind {
  int32_t size;
  std::vector<int32_t> arr;
  std::vector<int32_t> id;
  int32_t num_comp;

  UnionFind(int32_t num) {
    size = num;
    arr.resize(num, 1);
    id.resize(num);
    num_comp = num;
    for (int32_t i = 0; i < num; ++i) {
      id[i] = i;
    }
  }

  int32_t find(int32_t p) {
    int32_t root = p;

    while (root != id[root]) {
      root = id[root];
    }

    while (p != root) {
      int32_t next = id[p];
      id[p] = root;
      p = next;
    }
    return root;
  }

  bool connected(int32_t pt1, int32_t pt2) { return find(pt1) == find(pt2); }

  int32_t comp_size(int32_t pt1) { return arr[pt1]; }

  int32_t get_size() { return size; }

  void union_f(int32_t pt1, int32_t pt2) {
    int32_t root_p = find(pt1);
    int32_t root_q = find(pt2);

    if (root_p == root_q) {
      return;
    }

    if (arr[root_p] < arr[root_q]) {
      arr[root_q] += arr[root_p];
      id[root_p] = root_q;
      arr[root_p] = 0;
    } else {
      arr[root_p] += arr[root_q];
      id[root_q] = root_p;
      arr[root_q] = 0;
    }

    num_comp -= 1;
  }
  std::string ask(int32_t u, int32_t v) {
    std::string ans = "";
    if (connected(u, v)) {
      ans = "YES";
    } else {
      ans = "NO";
    }
    return ans;
  }
};

int main() {
  int32_t n = 0;
  int32_t m = 0;
  int32_t ops = 0;
  std::cin >> n >> m >> ops;
  UnionFind set(n);
  for (int32_t i = 0; i < m; ++i) {
    int32_t pt1, pt2;
    std::cin >> pt1 >> pt2;
  }
  std::vector<std::string> ans;
  std::vector<std::pair<std::string, std::pair<int32_t, int32_t>>> qr;

  for (int32_t i = 0; i < ops; ++i) {
    int32_t pt1, pt2;
    std::string op;
    std::cin >> op >> pt1 >> pt2;
    std::pair<std::string, std::pair<int32_t, int32_t>> pr{op,
                                                           {pt1 - 1, pt2 - 1}};
    qr.push_back(pr);
  }

  for (int32_t i = qr.size() - 1; i >= 0; --i) {
    std::pair<std::string, std::pair<int32_t, int32_t>> curr = qr[i];
    if (curr.first == "cut") {
      set.union_f(curr.second.first, curr.second.second);
    } else {
      std::string out_p = "";
      out_p = set.ask(curr.second.first, curr.second.second);
      ans.push_back(out_p);
    }
  }

  for (size_t i = ans.size(); i > 0; --i) {
    std::cout << ans[i - 1] << '\n';
  }
}
