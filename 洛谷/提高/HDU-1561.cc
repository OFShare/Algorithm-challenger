/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-16 15:54:49 PM
 * File Name     : HDU-1561.cc
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
int n, m, cost[N], dp[N][N], cnt[N];
std::vector<int> sons[N];

// dp[u][j]维护以u为根, 恰好选j个点的最大值(dp[u][i][j]为原始状态)
void dfs(int u, int pre) {
  dp[u][1] = cost[u];
  dp[u][0] = 0;
  cnt[u] = 1;
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    if (v != pre) {
      dfs(v, u);
      cnt[u] += cnt[v];
      for (int j = std::min(cnt[u], m + 1); j >= 2; --j) {
        for (int k = 0; k < j; ++k) {
          dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k]);
        }
      }
    }
  }
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    std::memset(dp, -0x3f3f3f, sizeof dp);
    for (int i = 0; i <= n; ++i) {
      sons[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      int u, c;
      scanf("%d %d", &u, &c);
      sons[u].push_back(i);
      cost[i] = c;
    }
    dfs(0, -1);
    printf("%d\n", dp[0][m + 1]);
  }
  return 0;
}
