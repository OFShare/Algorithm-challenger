/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-18 15:39:36 PM
 * File Name     : P1970.cc
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
int n, height[N], dp[N][2];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &height[i]);
  }
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (height[i] > height[i - 1]) dp[i][1] = dp[i - 1][0] + 1;
    else dp[i][1] = dp[i - 1][1];

    if (height[i] < height[i - 1]) dp[i][0] = dp[i - 1][1] + 1;
    else dp[i][0] = dp[i - 1][0];
  }
  printf("%d\n", std::max(dp[n][0], dp[n][1]));
  return 0;
}
