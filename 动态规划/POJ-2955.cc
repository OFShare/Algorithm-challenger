/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-10 17:18:21 PM
 * File Name     : POJ-2955.cc
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

const int INF = -INF;
const int N = 1e3 + 5;
char A[N];

bool is_match(int i, int j) {
  if (A[i] == '(' && A[j] == ')') return true;
  if (A[i] == '[' && A[j] == ']') return true;
  return false;
}
// dp[i][j]: i ~ j区间, 合法的最长的子序列的长度
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  // 递归的边界
  if (i > j) return 0;
  if (i == j) return -INF;

  int ret = 0;
  if (is_match(i, j)) 
    ret = std::max(ret, dfs(i + 1, j - 1) + 2);
  // 枚举划分点k
  for (int k = i; k <= j - 1; ++k) {
    ret = std::max(ret, dfs(i, k) + dfs(k + 1, j)); 
  }
  return dp[i][j] = ret;
}
int main() {
  while (scanf("%s", A + 1)) {
    if (A[1] == 'e') break;
    std::memset(dp, -1, sizeof dp);
    printf("%d\n", dfs(1, strlen(A + 1)));
  }
  return 0;
}
