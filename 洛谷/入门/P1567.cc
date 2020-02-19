/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 18:02:43 PM
 * File Name     : P1567.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
int n, A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);
  // 模拟扫一遍
  int ans = 0, pre = -1, consective_day = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, consective_day);
    if (A[i] > pre) ++consective_day;
    else consective_day = 1;
    pre = A[i];
    ans = std::max(ans, consective_day);
  }
  printf("%d\n", ans);
  return 0;
}
