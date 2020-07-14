/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-16 13:05:09 PM
 * File Name     : POJ-1985.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

// const int N = 80005;
const int N = 4e4 + 5;
int n, m, depth[N], dp[N];
std::vector<std::pair<int, int> > sons[N];

// 以u为根的子树, 维护depth[u], 和dp[u]
// depth[u]表示向下路径的最大值
// dp[u]表示经过u以及不经过u的最长链
void dfs(int u, int pre) {
  // depth[u] = dp[u] = 0;
  // 递归的边界
  if (sons[u].size() - 1 == 0 && u != 1) {
    depth[u] = dp[u] = 0;
    return ;
  }
  // a, b维护u的儿子结点的最大和次大的depth
  // 注意可能只有a, 也可能既有a也有b
  int a = 0, b = 0;
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i].first, w = sons[u][i].second;
    if (v != pre) {
      dfs(v, u);
      depth[u] = std::max(depth[u], depth[v] + w);
      dp[u] = std::max(dp[u], dp[v]);
      if (depth[v] + w > a) b = a, a = depth[v] + w;
      else if (depth[v] + w > b) b = depth[v] + w;
    }
  }
  dp[u] = std::max(dp[u], a + b);
  dp[u] = std::max(dp[u], depth[u]);
}
// 题目数据保证是一颗树
int main() {
  scanf("%d %d", &n, &m);
  if (n == 1) printf("0\n"), exit(0);
  // 初始化
  std::memset(depth, -0x3f3f3f, sizeof depth);
  std::memset(dp, -0x3f3f3f, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    sons[i].clear();
  }
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    char tmp[2];
    scanf("%d %d %d %s", &u, &v, &c, tmp);
    sons[u].push_back(std::make_pair(v, c));
    sons[v].push_back(std::make_pair(u, c));
  }
  dfs(1, -1);
  printf("%d\n", dp[1]);
  return 0;
}
