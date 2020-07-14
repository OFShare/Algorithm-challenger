/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-03 00:19:26 AM
 * File Name     : HDU-3593.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

const int N = 5e2 + 5;
int n, G, cost[N], value[N], size[N], dp[N][10000 + 5];
bool is_leaf[100000 + 5];
std::vector<int> sons[N];

void dfs(int u) {
  dp[u][0] = 0;
  size[u] = cost[u];
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i];
    if (is_leaf[v]) {
      size[u] += cost[v];
      for (int j = size[u]; j >= 0; --j) {
        for (int k = 0; k <= cost[v]; ++k) {
          if (j - k >= 0) {
            int tmp = dp[u][j - k];
            if (k < cost[v]) tmp += 0;
            else if (k >= cost[v]) tmp += value[v];
            dp[u][j] = std::max(dp[u][j], tmp);
          }
        }
      }
      for (int j = size[u]; j <= G; ++j)
        dp[u][j] = dp[u][size[u]];
    }
    else {
      dfs(v);
      size[u] += size[v];
      for (int j = size[u]; j >= 0; --j) {
        for (int k = 0; k <= size[v]; ++k) {
          if (j - k >= 0)
            dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k]);
        }
      }
      for (int j = size[u]; j <= G; ++j)
        dp[u][j] = dp[u][size[u]];
    }
  }
  // 考虑根
  for (int j = size[u]; j >= 0; --j) {
    if (j - cost[u] >= 0)
      dp[u][j] = dp[u][j - cost[u]] + value[u];
  }
  for (int j = size[u]; j <= G; ++j) {
    dp[u][j] = dp[u][size[u]];
  }
}
int main() {
  while (scanf("%d %d", &n, &G) != EOF) {
    for (int i = 0; i <= n; ++i) sons[i].clear();
    std::memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; ++i) {
      int c, v, f;
      scanf("%d %d %d", &c, &v, &f);
      if (i == f) sons[0].push_back(f);
      else sons[f].push_back(i);
      cost[i] = c;
      value[i] = v;
    }
    // 找出叶子结点
    std::memset(is_leaf, 0, sizeof is_leaf);
    for (int i = 0; i <= n; ++i) {
      if (sons[i].size() == 0) {
        is_leaf[i] = true;
      }
    }
    dfs(0);
    printf("%d\n", dp[0][G]);
  }
  return 0;
}
