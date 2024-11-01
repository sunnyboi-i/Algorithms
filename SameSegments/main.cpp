#include <iostream>
#include <vector>
unsigned long Max(unsigned long x_1, unsigned long x_2) {
  if (x_1 >= x_2) {
    return x_1;
  }
  return x_2;
}
unsigned long MaxSegment(std::vector<unsigned long>& arr) {
  int32_t balance_zero = 1;
  unsigned long left_pt = 0;
  unsigned long right_pt = 0;
  unsigned long answer = 0;
  for (right_pt = 0; right_pt < arr.size(); ++right_pt) {
    if (arr[right_pt] == 0) {
      balance_zero--;
    }
    while (balance_zero < 0) {
      if (arr[left_pt] == 0) {
        balance_zero += 1;
      }
      left_pt += 1;
    }
    answer = Max(answer, right_pt - left_pt);
  }
  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::vector<unsigned long> arr;
  unsigned long num = 0;
  std::cin >> num;
  for (unsigned long i = 0; i < num; ++i) {
    unsigned long var = 0;
    std::cin >> var;
    arr.push_back(var);
  }
  std::cout << MaxSegment(arr);
}
