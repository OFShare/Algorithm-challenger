/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 18:19:41 PM
 * File Name     : CF808E.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
ll n, m, dp[N * 5];
struct Node {
  ll weight, cost, ratio;
  bool operator<(const Node &rhs) const {
    return ratio > rhs.ratio;
  }
}A[N];

int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &A[i].weight, &A[i].cost);
    A[i].ratio = A[i].cost * 6 / A[i].weight;
  }
  // 按单位重量的价值贪心
  std::sort(A + 1, A + 1 + n);
  // sum维护前i个物品的重量, 类似前缀和
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    ll w = A[i].weight, c = A[i].cost;
    sum += w;
    // 01背包, 第i个物品选或者不选
    for (int j = sum; j >= std::max(w, sum - 50); --j) {
      dp[j] = std::max(dp[j], dp[j - w] + c);
    }
  }
  ll ans = 0;
  for (int i = m; i >= 0; --i) ans = std::max(ans, dp[i]);
  printf("%lld\n", ans);
}
