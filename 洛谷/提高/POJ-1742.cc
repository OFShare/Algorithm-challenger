/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-14 13:27:58 PM
 * File Name     : POJ-1742.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5, M = 1e5 + 5;
int n, m, a[N], c[N], dp[2][M];

int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
    }
    // dp[i][j]表示前i种硬币, 组成恰好价值为j时, 第i种硬币最多剩余的个数
    std::fill(dp[0], dp[0] + M - 2, -1);
    dp[0 & 1][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        // 不选第i个
        if (dp[(i - 1) & 1][j] >= 0) dp[i & 1][j] = c[i];
        // 至少选一个
        else if (j - a[i] >= 0 && dp[i & 1][j - a[i]] >= 1)
          dp[i & 1][j] = dp[i & 1][j - a[i]] - 1;
        else dp[i & 1][j] = -1;
      }
    }
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      if (dp[n & 1][j] >= 0) ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
