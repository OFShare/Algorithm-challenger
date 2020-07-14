/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-12 23:33:24 PM
 * File Name     : P1130.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 2e3 + 5;
int n, m;
int A[N][N];
int dp[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &A[i][j]);
    }
  }

  // dp, 用dp[i][j]去更新dp[i][j + 1], dp[i - 1][j + 1], dp[i + 1][j + 1]
  // 即第j列的状态去更新第j + 1列的状态
  std::memset(dp, 0x3f3f3f, sizeof dp);
  for (int i = 1; i <= m; ++i) {
    dp[i][1] = A[i][1];
  }
  for (int j = 1; j <= n - 1; ++j) {
    for (int i = 1; i <= m; ++i) {
      // int index1 = (i - 1 == 0? m: i - 1);
      int index2 = (i + 1 == m + 1? 1: i + 1);

      // dp[index1][j + 1] = std::min(dp[index1][j + 1], dp[i][j] + A[index1][j + 1]);
      dp[i][j + 1] = std::min(dp[i][j + 1],           dp[i][j] + A[i][j + 1]);
      dp[index2][j + 1] = std::min(dp[index2][j + 1], dp[i][j] + A[index2][j + 1]);
    }
  }
  int ans = INF;

  for (int i = 1; i <= m; ++i) {
    ans = std::min(ans, dp[i][n]);
  }
  printf("%d\n", ans);
  return 0;
}
