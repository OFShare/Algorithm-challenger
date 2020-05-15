/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-15 16:36:56 PM
 * File Name     : P1273-tle.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e2 + 5;
int n, m, leaves[N], dp[N][N][N], cnt[N];
std::vector<std::pair<int, int> > sons[N];

// 以root为根的子树, 选择前i个儿子结点, 含有j个叶子结点时, 能获得的最大收益
// 转移的时候和背包类似, 考虑对第i个儿子结点选了k个叶子结点
// 状态不存在, 设为负无穷大
void dfs(int root, int pre) {
  int i = 0;
  for (int tmp_i = 0; tmp_i < sons[root].size(); ++tmp_i) {
    int v = sons[root][tmp_i].first, w = sons[root][tmp_i].second;
    if (v != pre) {
      ++i;
      dfs(v, root);
      // 回溯后(即上一行dfs已经执行完后), 说明以v为根的子树, 它的dp[v][*][*]这些状态都已经更新完成了
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= j; ++k) {
          if (k == 0) dp[root][i][j] = std::max(dp[root][i][j], dp[root][i - 1][j - k]);
          else dp[root][i][j] = std::max(dp[root][i][j], dp[root][i - 1][j - k] + dp[v][sons[v].size() - 1][k] - w);
        }
      }
    }
  }
}
int main() {
  debug();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n - m; ++i) {
    int k, a, c;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d %d", &a, &c);
      sons[i].push_back({a, c});
      sons[a].push_back({i, c});
    }
  }
  for (int i = n - m + 1; i <= n; ++i) {
    scanf("%d", &leaves[i]);
  }
  // 递推的初始化, 即dfs的边界情况
  std::memset(dp, -0x3f3f3f, sizeof dp);
  for (int root = 1; root <= n; ++root) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (j == 0) dp[root][i][j] = 0;
        // 叶子结点
        if (root != 1 && sons[root].size() - 1 == 0) dp[root][0][1] = leaves[root];
      }
    }
  }
  dfs(1, -1);
  for (int j = m; j >= 0; --j) {
    if (dp[1][sons[1].size()][j] >= 0) {
      printf("%d\n", j);
      break;
    }
  }
  return 0;
}
