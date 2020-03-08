/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-20 11:04:17 AM
 * File Name     : P1304.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n;
std::vector<int> prime;
bool flag[N];

void init() {
  std::memset(flag, 0, sizeof flag);
  for (int i = 2; i <= N - 3; ++i) {
    if (!flag[i]) {
      prime.push_back(i);
      for (int j = 2 * i; j <= N - 3; j += i) 
        flag[j] = 1;
    }
  }
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 4; i <= n; i += 2) {
    for (int j = 0; j < prime.size(); ++j) {
      int a = prime[j], b = i - prime[j];
      int cnt = std::upper_bound(prime.begin(), prime.end(), b) - std::lower_bound(prime.begin(), prime.end(), b);
      if (cnt == 1) {
        printf("%d=%d+%d\n", i, a, b);
        break;
      }
    }
  }
  return 0;
}
