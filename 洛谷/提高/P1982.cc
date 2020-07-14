/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 14:47:49 PM
 * File Name     : P1982.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
ll n, p, A[N], dp[N], score[N];

int main() {
  scanf("%lld %lld", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  // dp[i]: 以第i个元素结尾的连续的最大值
  for (int i = 1; i <= n; ++i) {
    dp[i] = A[i];
    dp[i] = std::max(dp[i], dp[i - 1] + A[i]);
  }
  // 再重复利用dp数组, 现在dp数组的含义是前i个元素中最大的连续值(不一定以第i个元素结尾, 类似前缀和), 即题目要求的特征值
  for (int i = 1; i <= n; ++i) {
    if (i == 1) continue;
    dp[i] = std::max(dp[i], dp[i - 1]);
  }
  // for (int i = 1; i <= n; ++i) {
  //   std::cout << "dp: " << dp[i] << std::endl;
  // }
  ll ans = -1e18;
  for (int i = 1; i <= n; ++i) {
    if (i == 1) score[i] = dp[i];
    else score[i] = ans;
    ans = std::max(ans, score[i] + dp[i]);
  }
  ans = -1e18;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, score[i]);
  }
  if (ans < 0) printf("-"), ans *= -1;
  printf("%lld\n", ans % p);
  return 0;
}
