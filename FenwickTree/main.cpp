#include <cstdint>
#include <iostream>
#include <vector>

int32_t Upd(int32_t val) { return (val | (val + 1)); }

int32_t Parent(int32_t val) { return ((val & (val + 1)) - 1); }
struct FenwickTree {
  std::vector<std::vector<std::vector<int32_t>>> tree;
  int32_t size;

  FenwickTree(int32_t num) : size(num) {
    tree.resize(num, std::vector<std::vector<int32_t>>(
                         num, std::vector<int32_t>(num, 0)));
  }

  void Add(int32_t x_1, int32_t y_1, int32_t z_1, int32_t value) {
    for (int32_t i = x_1; i < size; i = Upd(i)) {
      for (int32_t j = y_1; j < size; j = Upd(j)) {
        for (int32_t k = z_1; k < size; k = Upd(k)) {
          tree[i][j][k] += value;
        }
      }
    }
  }

  int32_t PrefixSum(int32_t x_1, int32_t y_1, int32_t z_1) {
    int32_t result = 0;
    for (int32_t i = x_1; i >= 0; i = Parent(i)) {
      for (int32_t j = y_1; j >= 0; j = Parent(j)) {
        for (int32_t k = z_1; k >= 0; k = Parent(k)) {
          result += tree[i][j][k];
        }
      }
    }
    return result;
  }

  void Queries() {
    std::vector<int32_t> arr;
    int32_t x_1 = 0;
    int32_t y_1 = 0;
    int32_t z_1 = 0;
    int32_t x_2 = 0;
    int32_t y_2 = 0;
    int32_t z_2 = 0;
    int32_t value = 0;
    while (true) {
      int32_t operation = 0;
      std::cin >> operation;
      if (operation == 1) {
        std::cin >> x_1 >> y_1 >> z_1 >> value;
        Add(x_1, y_1, z_1, value);
      } else if (operation == 2) {
        std::cin >> x_1 >> y_1 >> z_1 >> x_2 >> y_2 >> z_2;
        int32_t tmp = 0;
        int32_t tmp_1 = PrefixSum(x_2, y_2, z_2) - PrefixSum(x_1 - 1, y_2, z_2);
        int32_t tmp_2 =
            PrefixSum(x_1 - 1, y_1 - 1, z_2) - PrefixSum(x_2, y_1 - 1, z_2);
        int32_t exp_1 = tmp_1 + tmp_2;
        int32_t tmp_3 =
            PrefixSum(x_2, y_2, z_1 - 1) - PrefixSum(x_1 - 1, y_2, z_1 - 1);
        int32_t tmp_4 = PrefixSum(x_1 - 1, y_1 - 1, z_1 - 1) -
                        PrefixSum(x_2, y_1 - 1, z_1 - 1);
        int32_t exp_2 = tmp_3 + tmp_4;
        tmp = exp_1 - exp_2;
        arr.push_back(tmp);
      } else if (operation == 3) {
        break;
      }
    }
    for (size_t i = 0; i < arr.size(); ++i) {
      std::cout << arr[i] << '\n';
    }
  }
};

int main() {
  int32_t size = 0;
  std::cin >> size;
  FenwickTree tree(size);
  tree.Queries();
}
