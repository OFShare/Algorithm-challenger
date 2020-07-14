/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-03 00:19:26 AM
 * File Name     : HDU-3593.cc
 */

#include <bits/stdc++.h>

const int N = 5e2 + 5;
const int NN = 1e5 + 5;
const int KG = 1e4 + 5;
const int INF = 1e9;
int n, G, cost[NN], value[NN], dp[N][10000 + 5];
bool is_leaf[100000 + 5];
std::vector<int> sons[NN];

// 当进入根节点u时, 表明选择根结点后(即它已经装进背包)的状态都已记录好了
// 这时根节点记录的状态就是一个泛化物品所携带的信息
// 每次合并都是一个泛化物品和一件物品合并, 所有合并的时间复杂度为O(C)
// 因为有N个结点(物品), 所以总的时间复杂度为O(N * C)
// 整个合并过程类似前缀和
void dfs(int u) {
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i];
    if (is_leaf[v]) {
      for (int j = G; j >= 0; --j) {
        if (j - cost[v] >= 0) 
          dp[u][j] = std::max(dp[u][j], dp[u][j - cost[v]] + value[v]);
      }
    }
    else {
      // 选儿子结点, 先把父亲状态赋给儿子
      std::memcpy(dp[v], dp[v] + KG - 2, sizeof dp[u]);
      for (int j = 0; j <= G; ++j)
        if (j - cost[v] >= 0) dp[v][j] = dp[u][j - cost[v]] + value[v];
        // 因为必须装儿子结点v, 所以装不了时, 此时状态非法, 赋为-INF即可
        else dp[v][j] = -INF;
      dfs(v);
      // 不选儿子结点
      // do nothing

      // 对于儿子结点v, 选和不选合并
      for (int j = 0; j <= G; ++j) 
        dp[u][j] = std::max(dp[u][j], dp[v][j]);
    }
  }
}
int main() {
  while (scanf("%d %d", &n, &G) != EOF) {
    for (int i = 0; i <= n; ++i) sons[i].clear();

    for (int i = 1, f; i <= n; ++i) {
      scanf("%d %d %d", &cost[i], &value[i], &f);
      if (i == f) sons[0].push_back(f);
      else sons[f].push_back(i);
    }
    // 找出叶子结点
    std::memset(is_leaf, 0, sizeof is_leaf);
    for (int i = 0; i <= n; ++i) 
      if (sons[i].size() == 0) 
        is_leaf[i] = true;

    // 整个树的初始状态, 必须选择根节点0
    std::fill(dp[0], dp[0] + KG - 2, -INF);
    dp[0][cost[0]] = value[0];
    dfs(0);
    int ans = 0;
    for (int i = G; i >= 0; --i) {
      ans = std::max(ans, dp[0][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
