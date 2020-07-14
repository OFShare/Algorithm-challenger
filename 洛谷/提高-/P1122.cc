/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-19 23:36:49 PM
 * File Name     : P1122.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e4 + 5;
int n, value[N], dp[N][3];
std::vector<int> sons[N];

// dp[u][1]表示以u为根的子树, 选根结点时, 最大的子树和
// dp[u][0]表示以u为根的子树, 不选根结点时, 最大的子树和
void dfs(int u, int pre) {
  dp[u][0] = 0;
  dp[u][1] = value[u];
  int len = sons[u].size() - 1;
  for (int i = 0; i <= len; ++i) {
    int v = sons[u][i];
    if (v != pre) {
      dfs(v, u);
      dp[u][0] = std::max(dp[u][0], std::max(dp[v][0], dp[v][1]));
      dp[u][1] += std::max(0, dp[v][1]);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &value[i]);
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    sons[u].push_back(v);
    sons[v].push_back(u);
  }
  dfs(1, -1);
  printf("%d\n", std::max(0, std::max(dp[1][0], dp[1][1])));
  return 0;
}
