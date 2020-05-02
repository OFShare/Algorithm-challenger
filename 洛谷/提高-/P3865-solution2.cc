/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-29 15:21:38 PM
 * File Name     : P3865-solution2.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

// 快读
inline int read() {
  int x = 0,f = 1; char ch = getchar();
  while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
  while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
  return x * f;
}
// 快输
void write(int x){
  if (x<0) {putchar('-'); x = -x;}
  int y = 10, len = 1;
  while (y <= x) {y *= 10; len++;}
  while (len--) {y /= 10; putchar(x / y + 48); x %= y;}
}
const int N = 1e5 + 5;
int n, m, A[N], dp[N][50];
// 从下标为i, 长度为2 ^ j区间的最大值
// dp[i][j] = std::max{dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]}
int dfs(int i, int j) {
  // 递归的边界
  if (j == 0) {
    return dp[i][j] = A[i];
  }
  // 记忆化
  if (dp[i][j] != -1) return dp[i][j];

  return dp[i][j] = std::max(dfs(i, j - 1), dfs(i + (1 << j - 1), j - 1));
}
void init_st() {
  std::memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    // 从2 ^ upper <= (n - i + 1)推导而来
    int upper = std::log2(n - i + 1);
    for (int j = 0; j <= upper; ++j) 
      dfs(i, j);
  }
}
int query(int L, int R) {
  int upper = std::log2(R - L + 1);
  // 从L往右2 ^ upper个元素, 从R往左2 ^ upper个元素, 合起来的最大值
  return std::max(dp[L][upper], dp[R - (1 << upper) + 1][upper]);
}
int main() {
  n = read(); m = read();
  for (int i = 1; i <= n; ++i) {
    A[i] = read();
  }
  init_st();
  for (int i = 1; i <= m; ++i) {
    int L = read(), R = read();
    write(query(L, R)); putchar('\n');
  }
  return 0;
}
