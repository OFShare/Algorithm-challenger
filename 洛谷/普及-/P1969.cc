/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 19:24:58 PM
 * File Name     : P1969.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, A[N];

// 返回[L, R + 1)区间里, 搭建为目标积木所最少需要的次数
int dfs(int L, int R) {
  if (L + 1 == R) return A[L];
  int mid = (L + R) / 2;
  return dfs(L, mid) + dfs(mid, R) - std::min(A[mid - 1], A[mid]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);
  int ret = dfs(1, n + 1);
  printf("%d\n", ret);
  return 0;
}
