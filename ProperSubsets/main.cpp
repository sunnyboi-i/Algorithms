#include <algorithm>
#include <iostream>
#include <vector>

void GoodSubset(std::vector<int64_t>& arr) {
  unsigned long length = arr.size();
  std::vector<unsigned long> dp(length, 1);
  std::vector<int64_t> hash_map(length);
  std::sort(arr.begin(), arr.end());
  unsigned long max_size = 0;
  int64_t last_index = 0;
  for (unsigned long i = 0; i < length; ++i) {
    hash_map[i] = i;
    for (unsigned long j = 0; j < i; ++j) {
      if (arr[i] % arr[j] == 0 && dp[j] + 1 > dp[i]) {
        dp[i] = 1 + dp[j];
        hash_map[i] = j;
      }
    }
    if (dp[i] > max_size) {
      max_size = dp[i];
      last_index = i;
    }
  }
  std::cout << max_size << std::endl;
  std::vector<int64_t> tmp;
  tmp.push_back(arr[last_index]);
  while (hash_map[last_index] != last_index) {
    last_index = hash_map[last_index];
    tmp.push_back(arr[last_index]);
  }
  for (unsigned long i = 0; i < max_size; ++i) {
    std::cout << tmp[i] << ' ';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int32_t num = 0;
  std::vector<int64_t> arr;
  std::cin >> num;
  for (int32_t i = 0; i < num; ++i) {
    int64_t val = 0;
    std::cin >> val;
    arr.push_back(val);
  }
  GoodSubset(arr);
}
