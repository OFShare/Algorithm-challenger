/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-09 15:34:22 PM
 * File Name     : UVA-10934.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;

// dp[i][j]: 用状态d(i,j)表示用i个球实验j次所能测试的楼的最高层数。
// 完整一点的描述应该是: 用状态d(i,j)表示用i个球实验j次, 在最坏情况下能够确定小球硬度时, 所能测试的楼的最高层数。
// dp[0][x] = 0, dp[x][0] = 0;
long long dp[N][N];
void func() {
  for (int i = 1; i <= N - 2; ++i) 
    for (int j = 1; j <= N - 2; ++j)
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] + 1;
}

long long k, n;
int main() {
  func();
  
  while (scanf("%lld %lld", &k, &n) && k) {
    int ans = -1;
    for (int i = 1; i <= 63; ++i) {
      if (dp[k][i] >= n) {
        ans = i;
        break;
      }
    }
    if (ans != -1) printf("%d\n", ans);
    else printf("More than 63 trials needed.\n");
  }
  return 0;
}
