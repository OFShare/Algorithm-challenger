/**
 * Author: OFShare@outlook.com
 *
 * Date: 2020-01-14 Tuesday 23:08 PM
 */

#include <cstdio>
#include <string>
#include <cstring>

const int maxn = 1e3 + 5;
int P;

int dp[maxn][maxn];
// dp[i][j]: 有i个球, j层楼, 为了确定球的硬度, (在最坏情况下选择最优策略时)最少需要实验的次数.
// (在最坏情况下选择最优策略时): 即代码里的里面取max, 最外层取min.
// 决策是在那一层丟小球做实验, 转移是小球破与不破
int dfs(int ball, int building) {
  if (dp[ball][building] != -1)
    return dp[ball][building];

  if (ball == 1)
    return building;
  if (building == 1)
    return 1;
  if (building == 0)
    return 0;

  int ans = 0x3f3f3f;
  for (int i = 1; i <= building; ++i) {
    int tmp = std::max(dfs(ball - 1, i - 1), dfs(ball, building - i)) + 1;
    ans = std::min(ans, tmp);
  }
  return dp[ball][building] = ans;
}

int main() {
  scanf("%d", &P);
  for (int i = 1; i <= P; ++i) {
    std::memset(dp, -1, sizeof dp);

    int kase, Balls, Building;
    scanf("%d %d %d", &kase, &Balls, &Building);
    printf("%d %d\n", kase, dfs(Balls, Building));
  }
  return 0;
}
