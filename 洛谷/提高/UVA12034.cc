/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 20:57:08 PM
 * File Name     : UVA12034.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
const int MOD = 10056;
ll t, n, dp[N], C[N][N];

// 算组合数
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= N - 2; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
}
// dp[x]表示x个人赛马时的方案数, 转移是枚举第一名有多少人, 然后递归求子问题
ll dfs(ll x) {
  // 递归的边界
  if (x == 0) return 1;
  // 记忆化
  if (dp[x] != -1) return dp[x];

  ll ret = 0;
  for (int i = 1; i <= x; ++i) {
    ret = (ret + C[x][i] * dfs(x - i)) % MOD;
  }
  return dp[x] = ret % MOD;
}
int main() {
  init();
  std::memset(dp, -1, sizeof dp);
  scanf("%lld", &t);
  for (int kase = 1; kase <= t; ++kase) {
    scanf("%lld", &n);
    printf("Case %d: %lld\n", kase, dfs(n));
  }
  return 0;
}
