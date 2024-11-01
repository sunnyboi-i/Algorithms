#include <algorithm>
#include <math.h>
#include <complex>
#include <iostream>
#include <vector>

typedef std::complex<double> cd;
const double PI = acos(-1);

void FFT(std::vector<cd>& polyn, bool invert) {
  int32_t n = polyn.size();
  if (n == 1) {
    return;
  }
  std::vector<cd> P1(n / 2);
  std::vector<cd> P2(n / 2);
  int32_t j = 0;
  for (int32_t i = 0; i < n; i += 2) {
    P1[j] = polyn[i];
    P2[j] = polyn[i + 1];
    j += 1;
  }
  FFT(P1, invert);
  FFT(P2, invert);

  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1);
  cd wn(cos(ang), sin(ang));
  for (int32_t i = 0; i < n / 2; ++i) {
    polyn[i] = P1[i] + w * P2[i];
    polyn[i + n / 2] = P1[i] - w * P2[i];
    if (invert) {
      polyn[i] /= 2;
      polyn[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

void Multiply(std::vector<int32_t>& a, std::vector<int32_t>& b,
              std::vector<int32_t>& res) {
  std::vector<cd> res_a(a.begin(), a.end());
  std::vector<cd> res_b(b.begin(), b.end());
  size_t n = 1;

  while (n < std::max(a.size(), b.size())) {
    n <<= 1;
  }
  n <<= 1;
  res_a.resize(n);
  res_b.resize(n);

  FFT(res_a, false);
  FFT(res_b, false);

  for (size_t i = 0; i < n; ++i) {
    res_a[i] *= res_b[i];
  }

  FFT(res_a, true);
  res.resize(n);
  for (size_t i = 0; i < n; ++i) {
    res[i] = round(res_a[i].real());
  }
  std::vector<int32_t> tmp;
	int32_t pt = res.size() - 1;
	while(true) {
		if(res[pt] != 0) {
			break;
		}
		pt -= 1;
	}

	for (int32_t j = 0; j < pt + 1; ++j) {
		tmp.push_back(res[j]);
	}
  std::cout << tmp.size() - 1 << ' ';
  std::reverse(tmp.begin(), tmp.end());
  for (auto& it : tmp) {
    std::cout << it << ' ';
  }
}

void Read(std::vector<int32_t>& P1, std::vector<int32_t>& P2) {
  int32_t d1 = 0;
  int32_t d2 = 0;
  std::cin >> d1;
  for (int32_t i = 0; i < d1 + 1; ++i) {
    int32_t var;
    std::cin >> var;
    P1.push_back(var);
  }
  std::cin >> d2;
  for (int32_t i = 0; i < d2 + 1; ++i) {
    int32_t var;
    std::cin >> var;
    P2.push_back(var);
  }
  std::reverse(P1.begin(), P1.end());
  std::reverse(P2.begin(), P2.end());
}

int32_t main() {
  std::vector<int32_t> a1;
  std::vector<int32_t> a2;
  std::vector<int32_t> res;
  Read(a1, a2);
  Multiply(a1, a2, res);
}
