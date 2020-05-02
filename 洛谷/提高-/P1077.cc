/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 11:49:18 AM
 * File Name     : P1077.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
const int MOD = 1000007;
int n, m, A[N], dp[N][N];

// 前i种花, 排成一排共j盆时的方案数
int dfs(int i, int j) {
  // 递归的边界
  if (i == 0) {
    return j == 0? 1: 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int ret = 0;
  // 枚举第i盆花
  for (int k = 0; k <= A[i]; ++k) {
    if (j - k >= 0)
      ret = (ret + dfs(i - 1, j - k)) % MOD;
  }
  return dp[i][j] = ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  std::memset(dp, -1, sizeof dp);
  printf("%d\n", dfs(n, m));
  return 0;
}
