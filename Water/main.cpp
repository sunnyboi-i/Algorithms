#include <cstdint>
#include <iostream>
#include <vector>

int64_t Water(std::vector<int64_t>& arr) {
  size_t right = arr.size() - 1;
  size_t left = 0;
  int64_t left_max = arr[left];
  int64_t right_max = arr[right];
  int64_t sum = 0;
  while (left < right) {
    if (left_max < right_max) {
      left += 1;
      left_max = std::max(left_max, arr[left]);
      sum += left_max - arr[left];
    } else {
      right -= 1;
      right_max = std::max(right_max, arr[right]);
      sum += right_max - arr[right];
    }
  }
  return sum;
}

void Reader(std::vector<int64_t>& arr) {
  int32_t num = 0;
  std::cin >> num;
  for (int32_t i = 0; i < num; ++i) {
    int64_t var = 0;
    std::cin >> var;
    arr.push_back(var);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::vector<int64_t> arr;
  Reader(arr);
  std::cout << Water(arr);
}
