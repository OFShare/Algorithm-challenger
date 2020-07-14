/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 14:03:42 PM
 * File Name     : HDU-2476.cc
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

// 将A串的前i个字符刷成B串的前i个字符, 所需要的最少的次数
int dp2[N];

int main() {
  while (scanf("%s %s", A + 1, B + 1) != EOF) {
    std::memset(dp, -1, sizeof dp);
    int len = strlen(A + 1);
    // 先将白板串刷成B串
    dfs(1, len);

    for (int i = 1; i <= len; ++i) {
      // 先将空白串刷成B串的次数作为初始值
      dp2[i] = dfs(1, i);
      if (A[i] == B[i]) dp2[i] = dp2[i - 1];
      // 将k + 1 ~ i看成空白串刷成B串
      else {
        for (int k = 1; k < i; ++k)
          dp2[i] = std::min(dp2[i], dp2[k] + dfs(k + 1, i));
      }
    }
    printf("%d\n", dp2[len]);
  }
  return 0;
}
