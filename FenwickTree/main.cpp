#include <cmath>
#include <iostream>
#include <vector>

class SparseTable {
 public:
  SparseTable(std::vector<int32_t>& arr) {
    int32_t power = log2(arr.size());
    size_ = arr.size();
    powers_.resize(size_ + 1);

    for (size_t i = 0; i < size_ + 1; ++i) {
      powers_[i] = 0;
    }

    for (size_t i = 2; i < size_ + 1; ++i) {
      powers_[i] = powers_[i / 2] + 1;
    }
    sp_t_.resize(power + 1);
    id_t_.resize(power + 1);
    for (int32_t i = 0; i < power + 1; ++i) {
      sp_t_[i].resize(size_);
      id_t_[i].resize(size_);
    }
    for (size_t i = 0; i < size_; ++i) {
      sp_t_[0][i] = arr[i];
      id_t_[0][i] = i;
    }

    for (int32_t i = 1; i <= power; ++i) {
      for (size_t j = 0; j + (1 << i) <= size_; ++j) {
        int32_t left = sp_t_[i - 1][j];
        int32_t right = sp_t_[i - 1][j + (1 << (i - 1))];
        sp_t_[i][j] = std::min(left, right);
        if (left <= right) {
          id_t_[i][j] = id_t_[i - 1][j];
        } else {
          id_t_[i][j] = id_t_[i - 1][j + (1 << (i - 1))];
        }
      }
    }
  }

  int32_t Min(int32_t left, int32_t right) {
    int32_t length = right - left + 1;
    int32_t pow_2 = powers_[length];
    int32_t l_i = sp_t_[pow_2][left];
    int32_t r_i = sp_t_[pow_2][right - (1 << pow_2) + 1];
    return std::min(l_i, r_i);
  }

  int32_t MinIndex(int32_t left, int32_t right) {
    int32_t length = right - left + 1;
    int32_t pow_2 = powers_[length];
    int32_t l_i = sp_t_[pow_2][left];
    int32_t r_i = sp_t_[pow_2][right - (1 << pow_2) + 1];
    if (l_i <= r_i) {
      return id_t_[pow_2][left];
    }
    return id_t_[pow_2][right - (1 << pow_2) + 1];
  }

  int32_t SecondStat(int32_t left, int32_t right) {
    int32_t index_min = MinIndex(left, right);
    if (left == index_min) {
      return Min(left + 1, right);
    }
    if (right == index_min) {
      return Min(left, right - 1);
    }
    int32_t tmp_1 = Min(left, index_min - 1);
    int32_t tmp_2 = Min(index_min + 1, right);
    return std::min(tmp_1, tmp_2);
  }

  void Queries(int32_t nums) {
    int32_t left = 0;
    int32_t right = 0;
    std::vector<int32_t> ans;
    while (nums > 0) {
      int32_t tmp = 0;
      std::cin >> left >> right;
      tmp = SecondStat(left - 1, right - 1);
      ans.push_back(tmp);
      nums -= 1;
    }
    for (size_t i = 0; i < ans.size(); ++i) {
      std::cout << ans[i] << '\n';
    }
  }

  ~SparseTable() = default;

 private:
  std::vector<std::vector<int32_t>> sp_t_;
  std::vector<std::vector<int32_t>> id_t_;
  std::vector<int32_t> powers_;
  size_t size_ = 0;
};

int main() {
  std::vector<int32_t> arr;
  int32_t num = 0;
  int32_t size = 0;
  std::cin >> num >> size;
  for (int32_t i = 0; i < num; ++i) {
    int32_t var = 0;
    std::cin >> var;
    arr.push_back(var);
  }
  SparseTable spars(arr);
  spars.Queries(size);
}

