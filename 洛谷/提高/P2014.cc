/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-01 13:40:58 PM
 * File Name     : P2014.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e2 + 5; 
int n, m, score[N], size[N], dp[N][N];
std::vector<int> sons[N];

// dp[u][j]表示以结点u为根, 选j门课(看成背包容量且恰好装满), 能获得的最大学分
void dfs(int u) {
  dp[u][0] = 0;
  size[u] = 1;
  // 每个儿子看成一组背包
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    dfs(v);
    size[u] += size[v];
    // 类似分组背包, k枚举第i组背包(即第i个儿子)选几门课
    for (int j = m; j >= 0; --j) {
      for (int k = 0; k <= size[v]; ++k) {
        if (j - k >= 0)
          dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k]);
      }
    }
  }
  // 根结点u本身看成一组背包, 且必须取它
  for (int j = m; j >= 0; --j) {
    if (j - 1 >= 0) {
      // dp[u][j] = std::max(dp[u][j], dp[u][j - 1] + score[u]);
      dp[u][j] = dp[u][j - 1] + score[u];
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k, s;
    scanf("%d %d", &k, &s);
    sons[k].push_back(i);
    score[i] = s;
  }
  m += 1;
  score[0] = 0;
  std::memset(dp, -0x3f3f3f, sizeof dp);
  dfs(0);
  printf("%d\n", dp[0][m]);
  return 0;
}
