/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-22 18:26:01 PM
 * File Name     : acw165.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 18 + 5;
int n, w, ans, A[N], sum[N];

// 遍历到第i个小猫时, 揽车个数为k个时的状态
void dfs(int i, int k) {
  // 递归的边界
  if (i == n + 1) {
    ans = std::min(ans, k);
    return ;
  }
  // 剪枝
  if (k >= ans) return ;

  // 尝试装进前面的一个
  for (int u = 1; u <= k; ++u) {
    if (sum[u] + A[i] <= w) {
      sum[u] += A[i];
      dfs(i + 1, k);
      sum[u] -= A[i];
    }
  }
  // 尝试独立装进一个
  sum[k + 1] += A[i];
  dfs(i + 1, k + 1);
  sum[k + 1] -= A[i];
}
int main() {
  scanf("%d %d", &n, &w);
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  // std::sort(A + 1, A + 1 + n, std::greater<int>());
  ans = n;
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
