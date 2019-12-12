/*
 * Created by OFShare on 2019-12-12
 *
 */

#include <cstdio>

const int MOD = 1e6;
const int maxn = 1e3 + 5;
int T, A, S, B;
int ant[maxn];
int dp[maxn][maxn * 100];
int sum[maxn][maxn * 100];

int main() {
  scanf("%d %d %d %d", &T, &A, &S, &B);
  for (int i = 1; i <= A; ++i) {
    int kind;
    scanf("%d", &kind);
    ant[kind]++;
  }

  for (int i = 1; i <= T; ++i) {
    for (int j = 0; j <= A; ++j) {
      if (i == 1) {
        if (j <= ant[i]) {
          dp[i][j] = 1;
          if (j - 1 >= 0)
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
          else
            sum[i][j] = dp[i][j] % MOD;
        }
        else {
          dp[i][j] = 0;
          if (j - 1 >= 0)
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
          else
            sum[i][j] = dp[i][j] % MOD;
        }
        continue;
      }
      if (ant[i] <= j) {
        // 先更新dp数组
        if (j - ant[i] == 0)
          dp[i][j] = sum[i - 1][j] % MOD;
        else
          dp[i][j] = (sum[i - 1][j] - sum[i - 1][j - ant[i] - 1]) % MOD;
        // 再更新sum数组
        if (j - 1 >= 0)
          sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
        else
          sum[i][j] = dp[i][j] % MOD;
      } else {
        dp[i][j] = (sum[i - 1][j] ) % MOD;
        if (j - 1 >= 0)
          sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
        else
          sum[i][j] = dp[i][j] % MOD;
      }
    }
  }
  int ans = 0;
  for (int j = S; j <= B; ++j) {
    ans = (ans + dp[T][j]) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
