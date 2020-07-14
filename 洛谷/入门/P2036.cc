/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 15:28:07 PM
 * File Name     : P2036.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 10 + 5;
int n, ans = 1e9, A1[N], A2[N];
// 遍历到第i位, 酸度为S, 甜度为B
void dfs(int i, int S, int B) {
  if (i == n) {
    if (S == 1 && B == 0) return ;
    ans = std::min(ans, std::abs(S - B));
    return ;
  }
  dfs(i + 1, S, B);
  dfs(i + 1, S * A1[i + 1], B + A2[i + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A1[i], &A2[i]);
  }
  dfs(0, 1, 0);
  printf("%d\n", ans);
  return 0;
}
