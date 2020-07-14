/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-02 18:02:22 PM
 * File Name     : HDU-1561-solution2.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e2 + 5;
int n, m, score[N], size[N], dp[N][N];
std::vector<int> sons[N];

// dp[u][j]表示以u为结点选择j个物品能获得的最大点权值和
void dfs(int u) {
  size[u] = 1;
  dp[u][0] = 0;
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    dfs(v);
    size[u] += size[v];
    for (int j = size[u]; j >= 0; --j) {
      for (int k = 0; k <= size[v]; ++k) {
        if (j - k >= 0)
          dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k]);
      }
    }
  }
  // 考虑根结点u, 且必须选
  for (int j = size[u]; j >= 0; --j) {
    if (j - 1 >= 0)
      dp[u][j] = dp[u][j - 1] + score[u];
  }
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    for (int i = 0; i <= n; ++i) sons[i].clear();
    std::memset(dp, -0x3f3f3f, sizeof dp);

    for (int i = 1; i <= n; ++i) {
      int u, v = i;
      scanf("%d %d", &u, &score[i]);
      sons[u].push_back(v);
    }
    dfs(0);
    printf("%d\n", dp[0][m + 1]);
  }
  return 0;
}
