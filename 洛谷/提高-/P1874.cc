/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-10 16:27:09 PM
 * File Name     : P1874.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 40 + 5;
const int M = 1e5 + 5;
char s[N];
// dp[i][j]表示前i位, 构成和为j时, 最少的加法次数
int n, dp[N][M];

int my_pow(int base, int k) {
  int ret = 1;
  for (int i = 1; i <= k; ++i) ret *= base;
  return ret;
}
int main() {
  scanf("%s %d", s + 1, &n);
  int len = std::strlen(s + 1);
  // 状态的初始化
  std::memset(dp, 0x3f3f3f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= len; ++i) {
    for (int j = 0; j <= n; ++j) {
      // 枚举k
      int sum = 0, cnt = 0;
      for (int k = i; k >= 1; --k) {
        sum += (s[k] - '0') * my_pow(10, cnt++);
        if (sum > j) break;
        if (j - sum >= 0)
          dp[i][j] = std::min(dp[i][j], dp[k - 1][j - sum] + 1);
        // 特判
        if (k - 1 == 0 && j - sum == 0) dp[i][j] = 0;
      }
    }
  }
  int ans = dp[len][n];
  if (ans >= 1e9) ans = -1;
  printf("%d\n", ans); 
  return 0;
}
