/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-10 15:57:54 PM
 * File Name     : CodeForces-149D.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 700 + 5;
const int MOD = 1e9 + 7;
char A[N];
int F[N];
long long ans = 0;

// 判断这一对相邻的括号(可能是'()', 也可能是')('), 染色为c1, c2是否合法
// is_normal为true, 表示是这样的括号'()'
bool valid(int c1, int c2, bool is_normal) {
  if (is_normal) {
    // 有且仅有一个染色
    if (c1 == 0 && c2 == 0) return false;
    if (c1 >= 1 && c2 >= 1) return false;
    return true;
  } else {
    if (c1 == c2 && c1) return false;
    return true;
  }
}
// dp[i][j][c1][c2]: i ~ j 区间, i端点染色为c1, j端点染色为c2时, 符合题目条件合法的方案数
long long dp[N][N][3][3];
long long dfs(int i, int j, int c1, int c2) {
  if (dp[i][j][c1][c2] != -1) 
    return dp[i][j][c1][c2];

  long long k = F[i], ret = 0;
  // 递归的边界
  if (i + 1 == j) {
    if (valid(c1, c2, true)) return 1;
    else return 0;
  }

  if (k == j) {
    if (c1 == 0 && c2 == 0) return 0;
    if (c1 >= 1 && c2 >= 1) return 0;
    for (int a = 0; a < 3; ++a)
      for (int b = 0; b < 3; ++b)
        if (valid(c1, a, false) && valid(b, c2, false))
          ret = (ret + dfs(i + 1, j - 1, a, b)) % MOD;
  } else {
    for (int a = 0; a < 3; ++a)
      for (int b = 0; b < 3; ++b)
        if (valid(a, b, false))
          ret = (ret + dfs(i, k, c1, a) * dfs(k + 1, j, b, c2)) % MOD;
  }
  return dp[i][j][c1][c2] = ret;
}
int main() {
  scanf("%s", A + 1);
  int len = strlen(A + 1);
  std::memset(dp, -1, sizeof dp);
  // 预处理, 每个匹配括号, 左括号对应的右括号的下标
  // 右括号F[i] = 0;
  std::stack<int> stk;
  for (int i = 1; i <= len; ++i) {
    if (A[i] == '(') stk.push(i);
    else F[stk.top()] = i, stk.pop();
  }
  for (int a = 0; a < 3; ++a) 
    for (int b = 0; b < 3; ++b) 
      ans = (ans + dfs(1, strlen(A + 1), a, b)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
