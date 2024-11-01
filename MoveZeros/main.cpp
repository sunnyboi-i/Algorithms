#include <iostream>
#include <vector>

void Shifter(std::vector<int64_t>& arr) {
  unsigned long long non_zero = 0;
  for (unsigned long long i = 0; i < arr.size(); ++i) {
    if (arr[i] != 0) {
      arr[non_zero] = arr[i];
      ++non_zero;
    }
  }

  for (unsigned long long i = non_zero; i < arr.size(); ++i) {
    arr[i] = 0;
  }
  for (unsigned long long i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::vector<int64_t> arr;
  int32_t size = 0;
  std::cin >> size;
  for (int32_t i = 0; i < size; ++i) {
    int64_t var = 0;
    std::cin >> var;
    arr.push_back(var);
  }
  std::cout << arr.size() << '\n';
  Shifter(arr);
}

