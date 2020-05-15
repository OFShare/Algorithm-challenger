/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 21:28:37 PM
 * File Name     : UVA1638.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll T, n, l, r, dp[25][25][25];

// dp[i][j][k]表示i根从大到小的杆子, 从左边看有l根, 从右边看有r根的方案数.
// 转移的时候考虑最小的杆子的方法
ll dfs(int i, int j, int k) {
  // 递归的边界
  if (i == 1) {
    if (j == 1 && k == 1) return 1;
    return 0;
  }
  // 记忆化
  if (dp[i][j][k] != -1) return dp[i][j][k];

  return dp[i][j][k] = dfs(i - 1, j - 1, k) + dfs(i - 1, j, k - 1) + dfs(i - 1, j, k) * (i - 2);
}
int main() {
  std::memset(dp, -1, sizeof dp);
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld %lld %lld", &n, &l, &r);
    printf("%lld\n", dfs(n, l, r));
  }
  return 0;
}
