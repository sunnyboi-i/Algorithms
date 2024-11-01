#include <iostream>
#include <vector>

struct UnionFind {
  int32_t size;
  std::vector<int32_t> arr;
  std::vector<std::pair<int32_t, int32_t>> id;
  int32_t num_comp;

  UnionFind(int32_t num) {
    size = num;
    arr.resize(num, 1);
    id.resize(num);
    num_comp = num;
    for (int32_t i = 0; i < num; ++i) {
      id[i].first = i;
      id[i].second = 0;
    }
  }

  int32_t find(int32_t p) {
    int32_t root = p;

    while (root != id[root].first) {
      root = id[root].first;
    }

    while (p != root) {
      int32_t next = id[p].first;
      id[p].first = root;
      p = next;
    }
    return root;
  }

  int32_t status(int32_t root) {
    int32_t r_root = find(root);
    return id[r_root].second;
  }

  bool connected(int32_t pt1, int32_t pt2) { return find(pt1) == find(pt2); }

  int32_t comp_size(int32_t pt1) { return arr[pt1]; }

  int32_t get_size() { return size; }

  void union_f(int32_t pt1, int32_t pt2, int32_t level) {
    int32_t root_p = find(pt1);
    int32_t root_q = find(pt2);

    if (root_p == root_q) {
      id[root_p].second += level;
      return;
    }

    if (arr[root_p] < arr[root_q]) {
      arr[root_q] += arr[root_p];
      id[root_p].first = root_q;
      id[root_q].second += id[root_p].second + level;
      arr[root_p] = 0;
    } else {
      arr[root_p] += arr[root_q];
      id[root_q].first = root_p;
      id[root_p].second += id[root_q].second + level;
      arr[root_q] = 0;
    }

    num_comp -= 1;
  }

  void get_action(std::vector<int32_t>& ans, int32_t bit, int32_t arg1,
                  int32_t arg2 = 0, int32_t arg3 = 0) {
    if (bit == 1) {
      union_f(arg1, arg2, arg3);
    } else {
      ans.push_back(status(arg1));
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int32_t set_size = 0;
  int32_t actions = 0;
  std::cin >> set_size >> actions;
  UnionFind myset(set_size);
  std::vector<int32_t> ans;
  while (actions > 0) {
    int32_t bit = 0;
    int32_t arg1 = 0;
    int32_t arg2 = 0;
    int32_t arg3 = 0;
    std::cin >> bit;
    if (bit == 1) {
      std::cin >> arg1 >> arg2 >> arg3;
      myset.get_action(ans, bit, arg1 - 1, arg2 - 1, arg3);
      actions -= 1;
    } else {
      std::cin >> arg1;
      myset.get_action(ans, bit, arg1 - 1, arg2, arg3);
      actions -= 1;
    }
  }
  for (size_t i = 0; i < ans.size(); ++i) {
    std::cout << ans[i] << '\n';
  }
}
