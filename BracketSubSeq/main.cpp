#include <cstdint>
#include <iostream>
#include <string>

int64_t Decide(int32_t pace, int64_t first, int64_t second) {
  return (pace == -1 ? second : first);
}

char Decide(int32_t pace) { return (pace == -1 ? ')' : '('); }

void Add(int32_t pace, int64_t& first, int64_t& second) {
  (pace == -1 ? second : first) += 1;
}

void Traverse(std::string& str, uint32_t begin, uint32_t end, int64_t& sum) {
  int64_t left_pt = 0;
  int64_t right_pt = 0;
  int32_t pace = 0;
  if (begin == 0) {
    pace = 1;
  } else {
    pace = -1;
  }
  for (uint32_t i = begin; i != end; i += pace) {
    if (str[i] == Decide(pace)) {
      Add(pace, right_pt, left_pt);
    } else {
      Add(pace, left_pt, right_pt);
    }
    if (left_pt == right_pt) {
      sum = std::max(sum, 2 * Decide(pace, right_pt, left_pt));
    } else if (Decide(pace, left_pt, right_pt) >
               Decide(pace, right_pt, left_pt)) {
      left_pt = 0;
      right_pt = 0;
    }
  }
}

int64_t Subsequence(std::string& str) {
  int64_t sum = 0;
  Traverse(str, 0, str.size(), sum);
  Traverse(str, str.size(), 0, sum);
  return sum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string str;
  std::cin >> str;
  std::cout << Subsequence(str);
}
