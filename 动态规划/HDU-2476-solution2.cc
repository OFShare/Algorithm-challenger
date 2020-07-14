/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 15:16:58 PM
 * File Name     : HDU-2476-solution2.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e2 + 5;
char A[N], B[N];

// dp[i][j]: 将白板从i~j区间刷成对应板子的颜色, 最少的次数
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  // 递归的边界
  if (i == j)
    return 1;
  int ret = INF;
  if (B[i] == B[j])
    ret = std::min(ret, dfs(i, j - 1)), 
    ret = std::min(ret, dfs(i + 1, j));
  for (int k = i; k < j; ++k) 
    ret = std::min(ret, dfs(i, k) + dfs(k + 1, j));
  return dp[i][j] = ret;
}

// dp2[i]: 将A串前i个字符刷成B串所需要的最少的次数
int dp2[N];
int dfs2(int i) {
  if (dp2[i] != -1)
    return dp2[i];
  // 递归的边界
  if (i == 0) return 0;
  if (i == 1 && A[i] != B[i]) return 1;

  // 至少为白板串刷成B串的次数
  int ret = dfs(1, i);
  if (A[i] == B[i])
    ret = std::min(ret, dfs2(i - 1));
  // 这里dfs(k + 1, i)将k + 1 ~ i区间看成白板字符串刷成B串
  for (int k = 1; k < i; ++k)
    ret = std::min(ret, dfs2(k) + dfs(k + 1, i));
  return dp2[i] = ret;
}
int main() {
  while (scanf("%s %s", A + 1, B + 1) != EOF) {
    std::memset(dp, -1, sizeof dp);
    std::memset(dp2, -1, sizeof dp2);
    int len = strlen(A + 1);
    // 先将白板串刷成B串
    dfs(1, len);
    // 在考虑A串刷成B串
    printf("%d\n", dfs2(len));
  }
  return 0;
}
