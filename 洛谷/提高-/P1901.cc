/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 11:43:20 AM
 * File Name     : P1901.cc
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
ll n, H[N], V[N], rec[N];

int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &H[i], &V[i]);
  }
  // 单调队列维护最近比它高的点
  // 从左向右扫一遍, <value, position>
  std::deque<std::pair<ll, int> > que;
  for (int i = 1; i <= n; ++i) {
    while (!que.empty()) {
      if (que.back().first <= H[i]) que.pop_back();
      else break;
    }
    if (!que.empty()) rec[que.back().second] += V[i];
    que.push_back({H[i], i});
  }

  // 从右往左扫一遍
  que.clear();
  for (int i = n; i >= 1; --i) {
    while (!que.empty()) {
      if (que.back().first <= H[i]) que.pop_back();
      else break;
    }
    if (!que.empty()) rec[que.back().second] += V[i];
    que.push_back({H[i], i});
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, rec[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
