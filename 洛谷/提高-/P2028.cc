/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-18 11:11:17 AM
 * File Name     : P2028.cc
 */

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
ull n, k, p, dp[N][N / 10];
bool vis[N][N / 10];

// dp[i][j]表示i个苹果装进个盘子的方案数.
// 转移的时候, 考虑第i个苹果怎么放
ull dfs(int i, int j) {
  // 递归的边界
  if (i == 0) {
    return j == 0? 1: 0;
  }
  if (j == 0) return 0;
  // 记忆化
  if (vis[i][j]) return dp[i][j];

  ull ret = 0;
  ret += dfs(i - 1, j - 1) % p;
  ret += dfs(i - 1, j) * j % p;
  vis[i][j] = true;
  return dp[i][j] = ret % p;
}
int main() {
  scanf("%llu %llu %llu", &n, &k, &p);
  printf("%llu\n", dfs(n, k));
  return 0;
}
