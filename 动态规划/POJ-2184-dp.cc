/*
 * Created by OFShare on 2019-12-03
 *
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const int M = 2e5 + 5;
const int INF = 1e9;
const int maxn = 1e2 + 5;
const int Constant = 1e3;
int n, sum;
int dp[3][M];
int cnt[3][M];

int smartness_[maxn], funness_[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &smartness_[i], &funness_[i]);
    smartness_[i] += Constant;
    sum += smartness_[i];
  }
  // 初始化
  for (int j = 0; j <= sum; ++j)
    dp[0 & 1][j] = -INF;
  dp[0 & 1][0] = 0;
  cnt[0 & 1][0] = 0;

  for (int i = 1; i <= n; ++i) {
    int smartness = smartness_[i], funness = funness_[i];
    for (int j = 0; j <= sum; ++j) {
      // 不选
      cnt[i & 1][j] = cnt[(i - 1) & 1][j];
      dp[i & 1][j] = dp[(i - 1) & 1][j];

      // 选
      if (j - smartness >= 0) {
        if (dp[(i - 1) & 1][j - smartness] + funness + j - (cnt[(i - 1) & 1][j - smartness] + 1) * Constant > dp[i & 1][j] + j - cnt[(i - 1) & 1][j] * Constant) {
          cnt[i & 1][j] = cnt[(i - 1) & 1][j - smartness] + 1;
          dp[i & 1][j] = dp[(i - 1) & 1][j - smartness] + funness;
        }
      }
    }
  }
  int ans = 0;
  for (int j = sum; j >= 0; --j) {
    if (dp[n & 1][j] >= 0 && j - cnt[n & 1][j] * Constant >= 0) {
      ans = std::max(ans, dp[n & 1][j] + j - cnt[n & 1][j] * Constant);
    }
  }
  printf("%d\n", ans);
  return 0;
}
