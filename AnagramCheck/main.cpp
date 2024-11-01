#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

void AnagramCheck(std::string& str_1, std::string& str_2) {
  std::unordered_map<char, int64_t> hash_map;
  for (uint32_t i = 0; i < str_1.length(); ++i) {
    hash_map[str_1[i]] += 1;
  }
  uint32_t left_pt = 0;
  uint32_t right_pt = 0;
  uint32_t matched = str_1.size();
  while (right_pt < str_2.size()) {
    if ((hash_map[str_2[right_pt++]]--) > 0) {
      matched -= 1;
    }
    if (matched == 0) {
      std::cout << "Yes";
      return;
    }
    if ((right_pt - left_pt == str_1.size()) &&
        ((++hash_map[str_2[left_pt++]]) > 0)) {
      matched += 1;
    }
  }
  std::cout << "No";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string x_1;
  std::string x_2;
  std::cin >> x_1;
  std::cin >> x_2;
  AnagramCheck(x_1, x_2);
}
