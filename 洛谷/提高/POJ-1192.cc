/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-16 15:12:11 PM
 * File Name     : POJ-1192.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n, cost[N], dp[N][3];
struct Node {
  int x, y, c;
}A[N];
std::vector<int> sons[N];

// dp[u][0], 不选它时的最大点权和
// dp[u][1], 选它时的最大点权和
void dfs(int u, int pre) {
  dp[u][0] = 0;
  dp[u][1] = cost[u];
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    if (v != pre) {
      dfs(v, u);
      dp[u][0] = std::max(dp[u][0], std::max(dp[v][0], dp[v][1]));
      dp[u][1] += std::max(0, dp[v][1]);
    }
  }
  dp[u][0] = std::max(dp[u][0], 0);
  dp[u][1] = std::max(dp[u][1], cost[u]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &A[i].x, &A[i].y, &A[i].c);
    cost[i] = A[i].c;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      // 相邻
      if (std::abs(A[i].x - A[j].x) + std::abs(A[i].y - A[j].y) == 1) {
        sons[i].push_back(j);
        sons[j].push_back(i);
      }
    }
  }
  dfs(1, -1);
  printf("%d\n", std::max(dp[1][0], dp[1][1]));
  return 0;
}
