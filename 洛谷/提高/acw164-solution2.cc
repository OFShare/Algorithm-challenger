/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-22 00:00:36 AM
 * File Name     : acw164-solution2.cc
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
int n, m;
bool vis[N];
std::set<int> sons[N];
std::bitset<N> dp[N];

// 从结点u出发能够遍历到的所有点的集合
std::bitset<N> dfs(int u) {
  // 记忆化
  if (vis[u]) return dp[u];

  vis[u] = true;
  dp[u][u] = 1;
  for (auto &v: sons[u]) {
    dp[u] |= dfs(v);
  }
  return dp[u];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    // 去掉自环
    if (u == v) continue;
    sons[u].insert(v);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", dfs(i).count());
  }
  return 0;
}
