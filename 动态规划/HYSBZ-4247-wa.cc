/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 22:30:01 PM
 * File Name     : HYSBZ-4247.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 2e3 + 5;
// dp[i][j]: 挂完前i个物品后, 还恰好剩下j个钩子时能获得的最大值
// 什么叫还剩下的钩子, 就是你挂完物品后, 还露出来的钩子数量
int n, dp[N][N];

int main() {
  scanf("%d", &n);
  std::memset(dp, -0x3f3f3f, sizeof dp);
  // 初始状态
  dp[0][1] = 0;

  int ans = dp[0][1];
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int j = 0; j <= 5; ++j) {
      // 不选第i件物品
      dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
      // 选第i件物品, 至少有一个钩子可以用来挂
      if (j >= 1)
        dp[i][j + a - 1] = std::max(dp[i][j + a - 1], dp[i - 1][j] + b);
       
      // 记录最优解
      ans = std::max(ans, dp[i][j]);
      ans = std::max(ans, dp[i][j + a - 1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
