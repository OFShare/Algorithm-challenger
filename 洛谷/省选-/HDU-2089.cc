/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-28 14:19:17 PM
 * File Name     : HDU-2089.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, m, dp[50][15][5];

// 前i位, 当前在第i位, 且第i位填的是x, 下一位是否有限制时, 吉利的个数
// 状态i由i+1这些状态转移过来(构成)
int dfs(int i, int x, bool have_limit, std::vector<int> &origin) {
  // 递归的边界
  if (i == origin.size() - 1) {
    return (x == 4? 0: 1);
  }
  // 记忆化
  if (dp[i][x][have_limit] != -1) return dp[i][x][have_limit];

  int ret = 0;
  if (x == 4) ret = 0;
  else {
    int upper = (have_limit? origin[i + 1]: 9);
    for (int k = 0; k <= upper; ++k) {
      if (x == 6 && k == 2) continue;
      bool limit = false;
      if (k == origin[i + 1] && have_limit) limit = true;
      ret += dfs(i + 1, k, limit, origin);
    }
  }
  return dp[i][x][have_limit] = ret;
}
std::vector<int> decompose(int x) {
  std::vector<int> tmp;
  while (x) {
    tmp.push_back(x % 10);
    x /= 10;
  }
  tmp.push_back(-1);
  std::reverse(tmp.begin(), tmp.end());
  return tmp;
}
int count(int x) {
  if (x == 0) return 1;

  std::memset(dp, -1, sizeof dp);
  std::vector<int> tmp = decompose(x);
  return dfs(0, 0, true, tmp);
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    printf("%d\n", count(m) - count(n - 1));
  }
  return 0;
}
