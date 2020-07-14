/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-02 17:00:55 PM
 * File Name     : HDU-4607.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int t, n, m, tree_len;
std::vector<int> sons[N];

int dp[N], depth[N];
// dp[u]表示经过u结点的最长链, depth[u]表示从u结点向下能走的最长路径
void dfs(int u, int pre) {
  int mx1 = 0, mx2 = 0;
  bool updated = false;
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    if (v != pre) {
      dfs(v, u);
      updated = true;
      depth[u] = std::max(depth[u], depth[v] + 1);
      if (depth[v] + 1 >= mx1) mx2 = mx1, mx1 = depth[v] + 1;
      else if (depth[v] + 1 > mx2) mx2 = depth[v] + 1;
    }
  }
  // 递归的边界
  if (!updated) {
    dp[u] = 0;
    depth[u] = 0;
    return ;
  }
  dp[u] = std::max(dp[u], mx1 + mx2);
  tree_len = std::max(tree_len, dp[u]);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) sons[i].clear();
    tree_len = 0;
    std::memset(depth, -0x3f3f3f, sizeof depth);
    std::memset(dp, -0x3f3f3f, sizeof dp);

    for (int i = 1; i <= n - 1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      sons[u].push_back(v);
      sons[v].push_back(u);
    }
    dfs(1, -1);
    while (m--) {
      int k;
      scanf("%d", &k);
      // 特判
      if (n == 1) {
        printf("0\n");
        continue;
      }
      int number = tree_len + 1;
      if (k <= number) printf("%d\n", k - 1);
      else printf("%d\n", 2 * (k - number) + tree_len);
    }
  }
  return 0;
}
