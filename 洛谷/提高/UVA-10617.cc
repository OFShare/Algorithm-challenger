/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-13 23:12:50 PM
 * File Name     : UVA-10617.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 60 + 5;
int t;
char str[N];

// dp[i][j]表示区间i~j里回文序列的个数
ll dp[N][N];
ll dfs(int i, int j) {
  // 递归的边界
  if (i == j) return 1;
  if (i > j) return 0;
  // 记忆化
  if (dp[i][j] != -1) return dp[i][j];

  ll ret = 0;
  if (str[i] == str[j]) ret = dfs(i, j - 1) + dfs(i + 1, j) + 1;
  else ret = dfs(i, j - 1) + dfs(i + 1, j) - dfs(i + 1, j - 1);
  return dp[i][j] = ret;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", str + 1);
    std::memset(dp, -1, sizeof dp);
    printf("%lld\n", dfs(1, (int)std::strlen(str + 1)));
  }
  return 0;
}
