/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 15:45:33 PM
 * File Name     : P1880.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e2 * 2 + 5;
int n, A[N], sum[N];

// dp1[i][j]: i ~ j, 按照题目要求合并的最小得分
int dp1[N][N];
int dfs1(int i, int j) {
  if (dp1[i][j] != -1)
    return dp1[i][j];
  // 递归的边界
  if (i == j)
    return 0;
  int ret = INF;
  for (int k = i; k < j; ++k) {
    ret = std::min(ret, dfs1(i, k) + dfs1(k + 1, j) + sum[j] - sum[i - 1]);
  }
  return dp1[i][j] = ret;
}

// dp2[i][j]: i ~ j, 按照题目要求合并的最大得分
int dp2[N][N];
int dfs2(int i, int j) {
  if (dp2[i][j] != -1)
    return dp2[i][j];
  // 递归的边界
  if (i == j)
    return 0;
  int ret = -INF;
  for (int k = i; k < j; ++k) {
    ret = std::max(ret, dfs2(i, k) + dfs2(k + 1, j) + sum[j] - sum[i - 1]);
  }
  return dp2[i][j] = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]), sum[i] = A[i] + sum[i - 1];
  for (int i = n + 1; i <= 2 * n; ++i) 
    sum[i] = A[i - n] + sum[i - 1];
  std::memset(dp1, -1, sizeof dp1);
  std::memset(dp2, -1, sizeof dp2);

  int ans_min = INF, ans_max = -INF;
  for (int i = 1; i + n -1 <= 2 * n; ++i) {
    ans_min = std::min(ans_min, dfs1(i, i + n - 1));
    ans_max = std::max(ans_max, dfs2(i, i + n - 1));
  }
  printf("%d\n%d\n", ans_min, ans_max);
  return 0;
}
