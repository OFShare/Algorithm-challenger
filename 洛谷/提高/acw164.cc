/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-21 23:18:15 PM
 * File Name     : acw164.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e4 + 5;
int n, m, vis[N];
std::vector<int> sons[N], ans;

std::bitset<N> dp[N];
// 完成以结点u的拓扑排序
void dfs(int u) {
  vis[u] = 1;
  int len = sons[u].size() - 1;
  for (int i = 0; i <= len; ++i) {
    int v = sons[u][i];
    if (!vis[v]) dfs(v);
  }
  ans.push_back(u);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    sons[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
  }
  std::reverse(ans.begin(), ans.end());
  // 倒着dp, dp[x]维护从x结点出发能访问到的所有结点的集合
  for (int i = n - 1; i >= 0; --i) {
    int x = ans[i];
    int len = sons[x].size();
    dp[x][x] = 1;
    for (int k = 0; k < len; ++k) {
      int v = sons[x][k];
      dp[x] |= dp[v];
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", dp[i].count());
  }
  return 0;
}
