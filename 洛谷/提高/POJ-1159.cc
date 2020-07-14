/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-13 22:28:34 PM
 * File Name     : POJ-1159.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e3 + 5;
const int INF = 1e9;
int n;
char str[N];

// dp[i][j]表示将区间i~j的字符变为回文的最少插入的字符数量
short dp[N][N];
int dfs(int i, int j) {
  // 递归的边界
  if (i > j) return 0;
  // 记忆化
  if (dp[i][j] != -1) return dp[i][j];

  int ret = INF;
  if (str[i] == str[j]) ret = std::min(ret, dfs(i + 1, j - 1));
  else {
    ret = std::min(ret, dfs(i + 1, j) + 1);
    ret = std::min(ret, dfs(i, j - 1) + 1);
  }
  return dp[i][j] = ret;
}
int main() {
  scanf("%d %s", &n, str + 1);
  std::memset(dp, -1, sizeof dp);
  printf("%d\n", dfs(1, n));
  return 0;
}
