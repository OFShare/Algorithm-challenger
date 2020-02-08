/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 22:02:58 PM
 * File Name     : HDU-1257.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e3 + 5;
int n;
int dp[N];

int main() {
  while (scanf("%d", &n) != EOF) {
    std::memset(dp, 0x3f3f3f, sizeof dp);
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      *std::lower_bound(dp + 1, dp + 1 + n, x) = x;
    }
    printf("%d\n", std::lower_bound(dp + 1, dp + 1 + n, INF) - (dp + 1));
  }
  return 0;
}
