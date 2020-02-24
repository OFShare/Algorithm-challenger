/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 14:21:34 PM
 * File Name     : P2006.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

long long k, m, n;
int main() {
  debug();
  std::vector<long long > ans;

  scanf("%lld %lld %lld", &k, &m, &n);
  for (int i = 1; i <= m; ++i) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a > 0) {
      if (k / a * b >= n)
        ans.push_back(i);
    } else if (a == 0) {
      if (b > 0)
        ans.push_back(i);
    }
  }
  for (const auto &ch: ans) {
    printf("%lld ", ch);
  }
  if (ans.empty()) printf("-1\n");
}
