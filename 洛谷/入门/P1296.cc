/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-20 11:17:44 AM
 * File Name     : P1296.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
int n, d, A[N];

int main() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);
  std::sort(A + 1, A + 1 + n);
  // 排序后扫一遍
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int *it = std::upper_bound(A + 1, A + 1 + n, A[i] + d);
    ans += it - (A + i) - 1;
  }
  printf("%lld\n", ans);
  return 0;
}
