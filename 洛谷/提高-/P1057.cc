/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 13:45:36 PM
 * File Name     : P1057.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 30 + 5;
int n, m, dp[N][N];

// 在编号为i的位置, 还要传j次
int dfs(int i, int j) {
  // 递归的边界
  if (j == 0) {
    return i == 0? 1: 0;
  }
  // 剪枝 + 记忆化
  if (j < std::min(i, n - i)) return dp[i][j] = 0;
  if (dp[i][j] != -1) return dp[i][j];

  int ret = 0;
  // 往左
  ret += dfs((i - 1 + n) % n, j - 1);
  // 往右
  ret += dfs((i + 1) % n, j - 1);
  return dp[i][j] = ret;
}
int main() {
  scanf("%d %d", &n, &m);
  std::memset(dp, -1, sizeof dp);
  printf("%d", dfs(0, m));
  return 0;
}
