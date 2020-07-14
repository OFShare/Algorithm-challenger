/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-04 12:09:49 PM
 * File Name     : U53204.cc
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
const int INF = 1e9;
int n, m, cost[N], value[N], dp[N][N];
std::vector<int> sons[N];

// 当进入根节点u时, 表明选择根结点后(即已经装进背包)的状态都已记录好了
// 这时根节点记录的状态就是一个泛化物品所携带的信息
// 每次合并都是一个泛化物品和一件物品合并, 所有合并的时间复杂度为O(C)
// 因为有N个结点(物品), 所以总的时间复杂度为O(N * C)
// 整个合并过程类似前缀和

void dfs(int u) {
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i];
    // 选儿子结点, 先把父亲状态赋给儿子
    std::memcpy(dp[v], dp[v] + N - 2, sizeof dp[u]);
    for (int j = 0; j <= m; ++j)
      if (j - cost[v] > 0)
        dp[v][j] = dp[u][j - cost[v]] + value[v];
      // j - cost[v]必须>0才有意义, 因为父亲结点u必须选了才能选儿子节点v
      else if (j - cost[v] == 0)
        dp[v][j] = -INF;
    dfs(v);

    // 不选儿子结点
    // do nothing

    // 选和不选合并
    for (int j = 0; j <= m; ++j) 
      dp[u][j] = std::max(dp[u][j], dp[v][j]);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  // 所有结点费用都是1
  std::fill(cost, cost + N - 2, 1);
  for (int i = 1; i <= n; ++i) {
    int u, c;
    scanf("%d %d", &u, &c);
    sons[u].push_back(i);
    value[i] = c;
  }
  // 整个树的初始状态, 必须选择根节点0
  std::fill(dp[0], dp[0] + N - 2, -INF);
  dp[0][cost[0]] = value[0];
  dp[0][0] = 0;
  m += 1;
  dfs(0);

  int ans = 0;
  for (int j = 0; j <= m; ++j) ans = std::max(ans, dp[0][j]);
  printf("%d\n", ans);

  // std::cout << "====" << std::endl;
  // std::cout << "dp[0][0]: " << dp[0][0] << std::endl;
  // std::cout << "dp[0][1]: " << dp[0][1] << std::endl;
  // std::cout << "dp[0][2]: " << dp[0][2] << std::endl;
  // std::cout << "dp[0][3]: " << dp[0][3] << std::endl;
  // 
  // std::cout << "dp[1][0]: " << dp[1][0] << std::endl;
  // std::cout << "dp[1][1]: " << dp[1][1] << std::endl;
  // std::cout << "dp[1][2]: " << dp[1][2] << std::endl;
  // std::cout << "dp[1][3]: " << dp[1][3] << std::endl;
  return 0;
}
