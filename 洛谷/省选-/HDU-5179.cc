/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-29 00:02:46 AM
 * File Name     : HDU-5179.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int t, number[50], len, dp[50][15][5];

// 从左往右, 第i位为x, 前i位是否贴着放时, 符合题目要求的个数
// have_limit判断是否贴着放, have_zero判断是否前面都是0(前导零)
int dfs(int i, int x, bool have_limit, bool have_zero) {
  // 递归的边界
  if (i == len) {
    return 1;
  }
  // 记忆化
  if (dp[i][x][have_limit] != -1) return dp[i][x][have_limit];

  int ret = 0;
  int upper = (have_limit? number[i + 1]: 9);
  for (int k = 0; k <= upper; ++k) {
    if (k == 0) {
      if (have_zero) ret += dfs(i + 1, k, false, true);
      continue;
    }
    if (have_zero) {
      assert(x == 0);
      bool limit = false;
      if (have_limit && k == number[i + 1]) limit = true;
      ret += dfs(i + 1, k, limit, false);
      continue;
    }
    if (x < k || x % k != 0) continue;
    bool limit = false;
    if (have_limit && k == number[i + 1]) limit = true;
    ret += dfs(i + 1, k, limit, false);
  }
  return dp[i][x][have_limit] = ret;
}
int count(int x) {
  // 特判
  if (x == 0) return 1;
  int pos = 0;
  while (x) {
    number[++pos] = x % 10;
    x /= 10;
  }
  len = pos;
  std::reverse(number + 1, number + 1 + pos);
  std::memset(dp, -1, sizeof dp);
  return dfs(0, 0, true, true);
}
int main() {
  // std::cout << "count: " << count(11) << std::endl;
  // exit(0);

  scanf("%d", &t);
  while (t--) {
    int L, R;
    scanf("%d %d", &L, &R);
    if (L == 1 && R == 1) printf("1\n");
    else printf("%d\n", count(R) - count(L - 1));
  }
  return 0;
}
