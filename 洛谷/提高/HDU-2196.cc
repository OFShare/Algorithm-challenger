/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-06 13:38:26 PM
 * File Name     : HDU-2196.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
const int INF = 1e9;
int n;
std::vector<std::pair<int, int> > sons[N];

// d[u]维护以结点u为根的子树, 最长和次长的路径
std::pair<int, int> d[N];
void dfs1(int u) {
  d[u] = {0, 0};
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i].first, w = sons[u][i].second;
    dfs1(v);
    // 尝试更新结点u维护的信息
    int ret = d[v].first + w;
    if (ret >= d[u].first) {
      d[u].second = d[u].first;
      d[u].first = ret;
    } else if (ret > d[u].second) {
      d[u].second = ret;
    }
  }
}

// 从根结点向下更新每个结点的最远路径
// 进入u结点时, g[u]和d[u]都已经更新好了, 用u结点的状态去更新它的儿子结点的状态
int g[N];
void dfs2(int u) {
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i].first, w = sons[u][i].second;
    // 更新g[v]
    // 来自v的父亲结点
    g[v] = std::max(g[v], g[u] + w);
    // 来自v的兄弟结点
    if (w + d[v].first == d[u].first) {
      g[v] = std::max(g[v], w + d[u].second);
    } else {
      g[v] = std::max(g[v], w + d[u].first);
    }
    dfs2(v);
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) sons[i].clear();
    for (int i = 2; i <= n; ++i) {
      int fa, cost;
      scanf("%d %d", &fa, &cost);
      sons[fa].push_back({i, cost});
    }
    dfs1(1);
    std::memset(g, -0x3f3f3f, sizeof g);
    g[1] = 0;
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
      printf("%d\n", std::max(d[i].first, g[i]));
    }
  }
  return 0;
}
