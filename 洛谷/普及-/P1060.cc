/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 14:31:39 PM
 * File Name     : P1060.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, m, dp[25 + 5][30000 + 5];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int v, p;
    scanf("%d %d", &v, &p);
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - v >= 0)
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v] + v * p);
    }
  }
  printf("%d\n", dp[m][n]);
  return 0;
}
