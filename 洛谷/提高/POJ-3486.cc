/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-13 22:02:26 PM
 * File Name     : POJ-3486.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int c, n, m[N][N], dp[N];

int main() {
  while (scanf("%d", &c) != EOF) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j)
        scanf("%d", &m[i][j]);
    // dp[i]表示前i年中, 每一年都有一台电脑的最小花费
    // 转移考虑在第j年换一台电脑然后一直维修到第i年
    std::memset(dp, 0x3f3f3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] = std::min(dp[i], dp[j - 1] + c + m[j][i]);
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
