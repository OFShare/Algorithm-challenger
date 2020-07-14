/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-14 21:13:37 PM
 * File Name     : HDU-1520.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 6e3 + 5;
int n, L, K, rating[N], degree[N], dp[N][2];
std::vector<int> sons[N];

// 维护以root为根的子树, 选择root和不选择root时, 分别能获得的最大值
void dfs(int root, int pre) {
  dp[root][0] = 0;
  dp[root][1] = rating[root];
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < sons[root].size(); ++i) {
    int v = sons[root][i];
    if (v != pre) {
      dfs(v, root);
      sum1 += std::max(dp[v][0], dp[v][1]);
      sum2 += dp[v][0];
    }
  }
  dp[root][0] = std::max(dp[root][0], sum1);
  dp[root][1] = std::max(dp[root][1], sum2 + rating[root]);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    std::memset(degree, 0, sizeof degree);
    for (int i = 1; i <= n; ++i) {
      sons[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &rating[i]);
    }
    while (scanf("%d %d", &L, &K) && L + K) {
      sons[L].push_back(K);
      sons[K].push_back(L);
      degree[L]++;
    }
    // 找到入度为0的点, 即根
    int root;
    for (int i = 1; i <= n; ++i) {
      if (degree[i] == 0) root = i;
    }
    // std::cout << "root: " << root << std::endl;
    dfs(root, -1);
    printf("%d\n", std::max(dp[root][0], dp[root][1]));
  }
  return 0;
}
