#include <iostream>
#include <string>

void Rle(std::string& word) {
  unsigned long compressed_len = 0;
  unsigned long count = 1;
  for (unsigned long i = 0; i <= word.size() - 1; ++i) {
    if (i < word.size() - 1 && word[i] == word[i + 1]) {
      count++;
    } else {
      compressed_len += 1;
      if (count > 1) {
        compressed_len += std::to_string(count).size();
      }
      count = 1;
    }
  }
  std::cout << compressed_len << '\n';
  count = 1;
  for (unsigned long i = 0; i <= word.size() - 1; ++i) {
    if (i < word.size() - 1 && word[i] == word[i + 1]) {
      count++;
    } else {
      std::cout << word[i];
      if (count > 1) {
        std::cout << count;
      }
      count = 1;
    }
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string word;
  std::cin >> word;
  Rle(word);
}
