/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 13:52:29 PM
 * File Name     : POJ-3186.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e3 + 5;
int n, A[N];

// 区间i ~ j, 下标为k时, 能获得的最大价值之和
// k 可以由i和j推算出来
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  int k = n - (j - i + 1) + 1;
  if (i == j) 
    return dp[i][j] = A[i] * k;
  int ret1 = dfs(i + 1, j) + k * A[i];
  int ret2 = dfs(i, j - 1) + k * A[j];
  return dp[i][j] = std::max(ret1, ret2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &A[i]);
  std::memset(dp, -1, sizeof dp);
  int ret = dfs(1, n);
  printf("%d\n", ret);
  return 0;
}
