/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 14:40:22 PM
 * File Name     : HDU-2859.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n;
char mp[N][N];
int dp[N][N];

int main() {
  while (scanf("%d", &n) && n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
      scanf("%s", mp[i] + 1);
    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= n; ++j) {
        if (i + 1 <= n && j - 1 >= 1) {
          int len = 0;
          for (int k = 1; k <= n; ++k) {
            if (j - k >= 1 && i + k <= n && mp[i][j - k] == mp[i + k][j]) ++len;
            else break;
          }
          // 更新
          dp[i][j] = std::min(dp[i + 1][j - 1], len) + 1; 
        } else {
          dp[i][j] = 1;
        }
        // 记录最大值
        ans = std::max(ans, dp[i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
