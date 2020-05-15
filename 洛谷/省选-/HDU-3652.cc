/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-29 10:38:14 AM
 * File Name     : HDU-3652.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, len, number[15], dp[50][15][5][5][15];
// 从高位往低位搜, 前i位且现在第i位为x时, 符合题目要求的个数.
// have_limit判断是否贴着放, contain维护是否已经出现过"13", module维护取余
// 状态i由i+1这些状态转移过来, 转移的时候(module * 10 + k) % 13, 这其实就是大数取模的过程
int dfs(int i, int x, bool have_limit, bool contain, int module) {
  // 递归的边界
  if (i == len) {
    return contain && module == 0;
  }
  // 记忆化
  if (dp[i][x][have_limit][contain][module] != -1) return dp[i][x][have_limit][contain][module];

  int ret = 0;
  int upper = (have_limit? number[i + 1]: 9);
  for (int k = 0; k <= upper; ++k) {
    bool limit = false;
    if (have_limit && k == number[i + 1]) limit = true;
    if (x == 1 && k == 3) ret += dfs(i + 1, k, limit, true, (module * 10 + k) % 13);
    else ret += dfs(i + 1, k, limit, contain, (module * 10 + k) % 13);
  }
  return dp[i][x][have_limit][contain][module] = ret;
}
int count(int x) {
  if (x == 0) return 0;
  int pos = 0;
  while (x) {
    number[++pos] = x % 10;
    x /= 10;
  }
  len = pos;
  std::reverse(number + 1, number + 1 + len);
  std::memset(dp, -1, sizeof dp);
  return dfs(0, 0, true, false, 0);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", count(n));
  }
  return 0;
}
