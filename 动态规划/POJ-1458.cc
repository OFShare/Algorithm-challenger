/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-07 11:18:13 AM
 * File Name     : POJ-1458.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
char A[N], B[N];

// dp[i][j]: 字符串A的前i个字符, 和字符串B的前j个字符, 最长的公共子序列的长度
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i == 0 || j == 0)
    return 0;
  int ret = 0;
  if (A[i] == B[j])
    ret = std::max(ret, dfs(i - 1, j - 1) + 1);
  ret = std::max(ret, dfs(i, j - 1));
  ret = std::max(ret, dfs(i - 1, j));
  return dp[i][j] = ret;
}
int main() {
  while (scanf("%s %s", A + 1, B + 1) != EOF) {
    std::memset(dp, -1, sizeof dp);
    int ret = dfs(strlen(A + 1), strlen(B + 1));
    printf("%d\n", ret);
  }
  return 0;
}
