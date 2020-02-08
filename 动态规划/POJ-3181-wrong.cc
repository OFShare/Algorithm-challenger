/*
 * Created by OFShare on 2019-12-14
 *
 */

#include <cstdio>

const int maxn = 1e3 + 5;
int n, k;
int dp[maxn][maxn];

int main() {
  scanf("%d %d", &n, &k);
  dp[0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      // 不选
      dp[i][j] = dp[i - 1][j];
      // 加选一件
      if (j - i >= 0)
        dp[i][j] = dp[i][j] + dp[i][j - i];
    }
  }
  printf("%d\n", dp[k][n]);
  return 0;
}
