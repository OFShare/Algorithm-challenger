/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-21 12:18:06 PM
 * File Name     : P2241.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, m;
long long square = 0, rectangle = 0;
void count(int i, int j) {
  // 枚举左上角(i, j)可以构成的正方形个数
  int len = std::min(m - j + 1, n - i + 1);
  square += len;
  // 枚举左上角(i, j)可以构成的长方形个数
  rectangle += (m - j + 1) * (n - i + 1) - len;

}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      count(i, j);
    }
  }
  printf("%lld %lld\n", square, rectangle);
  return 0;
}
