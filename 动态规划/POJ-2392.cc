/*
 * Created by OFShare on 2019-12-12
 *
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const int maxn = 400 + 5;
const int maxm = 4e4 + 5;
int n;
struct node {
  int height, altitude, quantity;
  bool operator<(node &rhs) {
    return altitude < rhs.altitude;
  }
}A[maxn];

int dp[maxn][maxm];
int main() {
  int mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &A[i].height, &A[i].altitude, &A[i].quantity);
    mx = std::max(mx, A[i].altitude);
  }

  std::memset(dp, -0x3f3f3f, sizeof dp);
  std::sort(A + 1, A + 1 +n);
  for (int j = 0; j <= A[1].altitude; ++j) {
    if (j % A[1].height == 0 && j / A[1].height <= A[1].quantity)
      dp[1][j] = A[1].quantity - j / A[1].height;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= A[i].altitude; ++j) {
      if (dp[i - 1][j] >= 0)
        dp[i][j] = A[i].quantity;
      else if(j - A[i].height >= 0 && dp[i][j - A[i].height] >= 1)
        dp[i][j] = dp[i][j - A[i].height] - 1;
      else
        dp[i][j] = -1;
    }
  }
  for (int j = mx; j >= 0; --j) {
    if (dp[n][j] >= 0){
      printf("%d\n", j);
      break;
    }
  }
  return 0;
}
