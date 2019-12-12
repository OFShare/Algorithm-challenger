/*
 * Created by OFShare on 2019-12-12
 *
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const int INF = 1e9;
const int maxn = 4e4 + 5;
int t, n;
// dp[i]: 长度为i时, 的最小值
int dp[maxn];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    std::fill(dp, dp + n + 5, INF);
    for (int i = 1; i <= n; ++i) {
      int a;
      scanf("%d", &a);
      *std::lower_bound(dp + 1, dp + 1 + n, a) = a;
    }
    printf("%d\n", std::lower_bound(dp + 1, dp + 1 + n, INF) - (dp + 1));
  }
  return 0;
}
