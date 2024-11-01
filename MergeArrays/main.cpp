#include <cstdint>
#include <iostream>
#include <vector>

std::vector<int32_t> MergeTwo(std::vector<int32_t>& arr_1,
                              std::vector<int32_t>& arr_2) {
  std::vector<int32_t> result;
  uint32_t left_pt = 0;
  uint32_t right_pt = 0;
  while (left_pt < arr_1.size() && right_pt < arr_2.size()) {
    if (arr_1[left_pt] <= arr_2[right_pt]) {
      result.push_back(arr_1[left_pt]);
      left_pt += 1;
    } else {
      result.push_back(arr_2[right_pt]);
      right_pt += 1;
    }
  }
  while (left_pt < arr_1.size()) {
    result.push_back(arr_1[left_pt]);
    left_pt += 1;
  }
  while (right_pt < arr_2.size()) {
    result.push_back(arr_2[right_pt]);
    right_pt += 1;
  }
  return result;
}

void Merge(std::vector<std::vector<int32_t>>& arr) {
  uint32_t rows = arr.size();
  while (rows > 1) {
    std::vector<std::vector<int32_t>> tmp;
    for (uint32_t i = 0; i < rows; i += 2) {
      if (i + 1 < rows) {
        tmp.push_back(MergeTwo(arr[i], arr[i + 1]));
      } else {
        tmp.push_back(arr[i]);
      }
    }
    arr = tmp;
    rows = arr.size();
  }
}

void Reader(std::vector<std::vector<int32_t>>& arr) {
  size_t nums = 0;
  std::cin >> nums;
  for (size_t i = 0; i < nums; ++i) {
    int32_t size_i = 0;
    std::vector<int32_t> arr_i;
    std::cin >> size_i;
    for (int32_t j = 0; j < size_i; ++j) {
      int32_t var = 0;
      std::cin >> var;
      arr_i.push_back(var);
    }
    arr.push_back(arr_i);
  }
}

void Printer(std::vector<std::vector<int32_t>>& arr) {
  for (uint32_t i = 0; i < arr[0].size(); ++i) {
    std::cout << arr[0][i] << " ";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::vector<std::vector<int32_t>> arr;
  Reader(arr);
  Merge(arr);
  Printer(arr);
}
