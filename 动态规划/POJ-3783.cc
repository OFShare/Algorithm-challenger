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
