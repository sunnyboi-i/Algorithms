#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int32_t Pref(std::string& s) {
  int32_t sz = s.size();
  std::vector<int32_t> ans(sz, 0);
  for (int32_t i = 1; i < sz; ++i) {
    int j = ans[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = ans[j - 1];
    }
    if (s[i] == s[j]) {
      j += 1;
    }
    ans[i] = j;
  }
  return ans[ans.size() - 1];
}

std::string Substring(std::string& st, int32_t& start, int32_t& pos) {
  while (pos < st.size() && st[pos] != '#') {
    pos += 1;
  }
  return st.substr(start, pos - start);
}

void Increment(int32_t& left, int32_t& right) {
  right += 1;
  left = right;
}

void Result(std::string& words) {
  std::string res = "";
  std::string st_0 = "";
  std::string tmp = "";
  int32_t left = 0;
  int32_t right = 0;
  res = Substring(words, left, right);
  Increment(left, right);
  while (right < words.size()) {
    st_0 = Substring(words, left, right);
    Increment(left, right);
    if (st_0.size() < res.size()) {
      tmp = res.substr(res.size() - st_0.size(), st_0.size());
      st_0 += "#" + tmp;
      int32_t pref = Pref(st_0);
      if (pref != 0) {
        res.append(st_0, pref, st_0.size() - pref - 1 - tmp.size());
      } else {
        res.append(st_0, 0, st_0.size() - tmp.size() - 1);
      }
    } else {
      st_0 += "#" + res;
      int32_t pref = Pref(st_0);
      if (pref != 0) {
        res.append(st_0, pref, st_0.size() - pref - res.size() - 1);
      } else {
        res.append(st_0, 0, st_0.size() - res.size() - 1);
      }
    }
  }
  std::cout << res << '\n';
}

int main() {
  int32_t cnt;
  std::cin >> cnt;
  std::string words = "";
  for (int32_t i = 0; i < cnt; ++i) {
    std::string word;
    std::cin >> word;
    word.push_back('#');
    words.append(word);
  }
  Result(words);
}
