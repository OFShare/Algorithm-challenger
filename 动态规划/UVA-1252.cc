/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-09 17:30:20 PM
 * File Name     : UVA-1252.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 128 + 5, M = (1 << 11) + 5;
int m, n, obj[N];

// 已经选了的特征构成集合S, 其中属于'心中要猜的物品'的特征构成的集合为a
// dp[S][a]表示在最优决策下, 至少还要询问几次才能保证猜对.
// 递归的边界是: 如果在所有物品里, 在询问了S的情况下, 只有一个物品有(等于)a的特征, 那么就不需要询问了, 返回0.
int dp[M][M];
int dfs(int S, int a) {
  if (dp[S][a] != -1)
    return dp[S][a];
  // 递归的边界
  int cnt_tmp = 0;
  for (int i = 1; i <= n; ++i)
    // 和S取交集, 表示只考虑询问了的特征下的物品, 然后计算和a相等的个数,
    // 如果只有一个, 表示只有一个物品符合询问所获得的答案, 所以就不需要询问了, 返回0
    if ((obj[i] & S) == a) ++cnt_tmp;
  if (cnt_tmp == 1)
    return dp[S][a] = 0;

  int ans = INF;
  // 枚举决策
  for (int i = 0; i < m; ++i) {
    if ((S & (1 << i)) == 0)
      ans = std::min(ans, std::max(dfs(S | (1 << i), a | (1 << i)), dfs(S | (1 << i), a)) + 1);
  }
  return dp[S][a] = ans;
}
int main() {
  debug();
  while (std::cin >> m >> n) {
    if (m + n == 0) break;
    std::memset(obj, 0, sizeof obj);
    std::memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) 
      for (int j = 0; j < m; ++j) {
        char x;
        std::cin >> x;
        if (x == '1')
          obj[i] |= (1 << j);
      }
    int ret = dfs(0, 0);
    printf("%d\n", ret);
  }
  return 0;
}
