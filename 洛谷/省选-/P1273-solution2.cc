/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-02 00:07:30 AM
 * File Name     : P1273-solution2.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e3 + 5;
int n, m, dp[N][N], size[N], score[N];
std::vector<std::pair<int, int> > sons[N];

void dfs(int u) {
  // 递归的边界
  if (sons[u].size() == 0) {
    size[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = score[u];
    return ;
  }
  size[u] = 0;
  dp[u][0] = 0;
  // 枚举儿子
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i].first, w = sons[u][i].second;
    dfs(v);
    size[u] += size[v];
    for (int j = size[u]; j >= 0; --j) {
      for (int k = 0; k <= size[v]; ++k) {
        if (j - k >= 0)
          dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k] - w);
      }
    }
  }
  // 无需处理根, 因为根选0个用户终端
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n - m; ++i) {
    int k, a, c;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d %d", &a, &c);
      sons[i].push_back({a, c});
    }
  }
  for (int i = n - m + 1; i <= n; ++i) {
    scanf("%d", &score[i]);
  }
  std::memset(dp, -0x3f3f3f, sizeof dp);
  dfs(1);
  for (int j = size[1]; j >= 0; --j) {
    if (dp[1][j] >= 0) {
      printf("%d\n", j);
      break;
    }
  }
  return 0;
}
