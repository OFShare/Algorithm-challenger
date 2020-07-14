/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-01 12:59:13 PM
 * File Name     : acw9.cc
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
// dp[i][j]表示前i组背包, 装进背包容量为j时, 能获得的最大价值
int n, v, dp[N][N];
std::vector<std::pair<int, int> > A[N];

int main() {
  scanf("%d %d", &n, &v);
  for (int i = 1; i <= n; ++i) {
    int s, u, v;
    scanf("%d", &s);
    for (int k = 1; k <= s; ++k) {
      scanf("%d %d", &u, &v);
      A[i].push_back({u, v});
    }
  }
  // 初始化
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= v; ++j) {
      // 不选
      dp[i][j] = dp[i - 1][j];
      // 枚举选哪一个
      for (int k = 0; k < A[i].size(); ++k) {
        if (j - A[i][k].first >= 0)
          dp[i][j] = std::max(dp[i][j], dp[i - 1][j - A[i][k].first] + A[i][k].second);
      }
    }
  }
  printf("%d\n", dp[n][v]);
  return 0;
}
