/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 13:54:47 PM
 * File Name     : P4170.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 50 + 5;
char A[N];

// dp[i][j]: 将白板从i~j区间刷成对应板子的颜色, 最少的次数
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  // 递归的边界
  if (i == j)
    return 1;
  int ret = INF;
  if (A[i] == A[j])
    ret = std::min(ret, dfs(i, j - 1)), 
    ret = std::min(ret, dfs(i + 1, j));
  for (int k = i; k < j; ++k) 
    ret = std::min(ret, dfs(i, k) + dfs(k + 1, j));
  return dp[i][j] = ret;
}
int main() {
  std::memset(dp, -1, sizeof dp);
  scanf("%s", A + 1);
  printf("%d\n", dfs(1, strlen(A + 1)));
  return 0;
}
