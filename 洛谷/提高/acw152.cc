/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-08 11:48:31 AM
 * File Name     : acw152.cc
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
int n, m;
char A[N][N];
int up[N][N], left[N], right[N];

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> A[i][j];
    }
  }
  // 枚举每一行的最大矩阵(用单调栈找出)
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] == 'F') up[i][j] = up[i - 1][j] + 1;
      else up[i][j] = 0;
    }
    // 单调栈, 从左往右, 找到第一个比它低的
    std::deque<std::pair<int, int> > que;
    for (int k = 1; k <= m; ++k) {
      while (!que.empty() && que.back().first >= up[i][k]) que.pop_back();
      if (que.empty()) left[k] = 0;
      else left[k] = que.back().second;
      que.push_back({up[i][k], k});
    }
    // 从右往左, 找到第一个比它低的
    que.clear();
    for (int k = m; k >= 1; --k) {
      while (!que.empty() && que.back().first >= up[i][k]) que.pop_back();
      if (que.empty()) right[k] = m + 1;
      else right[k] = que.back().second;
      que.push_back({up[i][k], k});
    }
    // 更新答案
    for (int k = 1; k <= m; ++k) {
      ans = std::max(ans, up[i][k] * (right[k] - left[k] - 1));
    }
  }
  printf("%d\n", ans * 3);
  return 0;
}
