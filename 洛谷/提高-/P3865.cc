/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 17:56:35 PM
 * File Name     : P3865.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, m, A[N];

// st表
// dp[i][j]: 从下标i出发, 长度为2 ^ j的区间维护的最大值
int dp[N][20];
void init_st() {
  // 递推, 第一层循环为长度
  for (int j = 0; j <= 20; ++j) {
    // 递推的初始化
    if (j == 0) {
      for (int i = 1; i <= n; ++i)
        dp[i][j] = A[i];
    } else {
      for (int i = 1; i <= n; ++i) {
        // 注意这里要控制边界 
        if (i + (1 << j) - 1 > n) break;
        dp[i][j] = std::max(dp[i][j], std::max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]));
      }
    }
  }
}
int query(int L, int R) {
  int j = std::log2(R - L + 1);
  return std::max(dp[L][j], dp[R - (1 << j) + 1][j]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);
  init_st();

  for (int i = 1; i <= m; ++i) {
    int L, R;
    scanf("%d %d", &L, &R);
    int ret = query(L, R);
    printf("%d\n", ret);
  }
  return 0;
}
