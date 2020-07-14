/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-08 07:41:22 AM
 * File Name     : POJ-2411.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 11 + 1;
ll h, w;
// dp[i][j]表示铺满前i行, 且第i行的状态为j时的方案数
ll dp[N][1 << N];
bool valid[1 << N];

int main() {
  while (scanf("%lld %lld", &h, &w) && h + w) {
    if (h < w) std::swap(h, w);
    
    for (int j = 0; j < 1 << w; ++j) {
      int cnt = 0, has_odd = 0;
      for (int i = 0; i < w; ++i) {
        if (j & (1 << i)) has_odd |= cnt, cnt = 0;
        else cnt ^= 1;
      }
      valid[j] = has_odd | cnt? 0: 1;
    }
   
    std::memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= h; ++i) {
      for (int j = 0; j < 1 << w; ++j) {
        for (int k = 0; k < 1 << w; ++k) {
          if ((j & k) == 0 && valid[(j | k)])
            dp[i][j] += dp[i - 1][k];
        }
      }
    }
    printf("%lld\n", dp[h][0]);
  }
  return 0;
}
