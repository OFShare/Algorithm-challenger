/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-18 21:28:56 PM
 * File Name     : P1970-solution2.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
// dp[i][0]表示前i个元素以第i个元素结尾时, 且它是波谷时最长序列的长度
// dp[i][1]表示前i个元素以第i个元素结尾时, 且它是波峰时最长序列的长度
int n, height[N], dp[N][2];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &height[i]);
  }
  int ans = 1;
  dp[1][0] = dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (height[j] > height[i]) dp[i][0] = std::max(dp[i][0], dp[j][1] + 1);
      if (height[j] < height[i]) dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
    }
    ans = std::max(ans, dp[i][0]);
    ans = std::max(ans, dp[i][1]);
  }
  printf("%d\n", ans);
  return 0;
}
