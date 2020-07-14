/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 16:13:04 PM
 * File Name     : CF811C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5000 + 5;
int n, A[N], dp[N], cnt[N], vis[N], valid[N][N][2];

// 预处理区间[i, j]是否合法
// 暴力是O(n ^ 3), 稍微优化一下是O(n ^ 2)
void init() {
  for (int i = 1; i <= n; ++i) {
    int XOR = 0, tmp_cnt = 0;
    std::memset(vis, 0, sizeof vis);
    for (int j = i; j <= n; ++j) {
      if (vis[A[j]] == false) {
        vis[A[j]] = true;
        tmp_cnt += cnt[A[j]];
        XOR ^= A[j];
      }
      // 找到一段合法的
      if (j - i + 1 == tmp_cnt) {
        valid[i][j][0] = true;
        valid[i][j][1] = XOR;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    cnt[A[i]]++;
  }
  init();

  // dp[i]表示前i个元素的最大值(转移的时候考虑第i个元素选0个, 或者选一个), 类似背包
  // 选一个即以它结尾, 然后向前枚举合法区间
  for (int i = 1; i <= n; ++i) {
    // 不以第i个元素结尾
    dp[i] = dp[i - 1];
    // 以第i个元素结尾
    for (int j = i; j >= 1; --j) {
      if (valid[j][i][0]) dp[i] = std::max(dp[i], dp[j - 1] + valid[j][i][1]);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
