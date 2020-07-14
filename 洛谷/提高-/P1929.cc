/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-18 12:11:52 PM
 * File Name     : P1929.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e2 + 5;
// dp[i]表示移动到第i个台阶的最小次数
ll n, height[N], dp[N];

ll Pow(int base, int cnt) {
  ll ret = 1;
  for (int i = 1; i <= cnt; ++i) {
    ret *= base;
  }
  return ret;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &height[i]);
  }
  // 尝试用dp[i]去更新他能跳到的台阶的状态
  std::memset(dp, 0x3f3f3f, sizeof dp);
  dp[1] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    if (height[i] + 1 == height[i + 1]) dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
    // 枚举向后退几步
    bool conti = true;
    for (int k = 1; ; ++k) {
      if (i - k < 1) break;
      // j + 1 ~ n 全部更新, 后面就没必要再退了, 直接break掉
      if (height[i - k] + Pow(2, k) >= height[n]) {
        for (int j = i + 1; j <= n; ++j) {
          dp[j] = std::min(dp[j], dp[i] + k + 1);
        }
        conti = false;
        break;
      }
      if (!conti) break;
      for (int j = i + 1; j <= n; ++j) {
        if (height[j] <= height[i - k] + Pow(2, k)) dp[j] = std::min(dp[j], dp[i] + k + 1);
        else break;
      }
    }
  }
  if (dp[n] >= 1e9) printf("-1\n");
  else printf("%lld\n", dp[n]);
  return 0;
}
