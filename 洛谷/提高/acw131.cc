/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-07 17:23:11 PM
 * File Name     : acw131.cc
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
ll n, left[N], right[N], A[N];

int main() {
  while (scanf("%lld", &n) && n) {
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &A[i]);
    }
    // 单调栈, 从左往右扫一遍
    std::deque<std::pair<ll, int> > que;
    for (int i = 1; i <= n; ++i) {
      while (!que.empty() && que.back().first >= A[i]) que.pop_back();
      if (que.empty()) left[i] = 0;
      else left[i] = que.back().second;
      que.push_back({A[i], i});
    }
    // 单调栈, 从右往左再扫一遍
    que.clear();
    for (int i = n; i >= 1; --i) {
      while (!que.empty() && que.back().first >= A[i]) que.pop_back();
      if (que.empty()) right[i] = n + 1;
      else right[i] = que.back().second;
      que.push_back({A[i], i});
    }
    // 更新答案
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = std::max(ans, (right[i] - left[i] - 1) * A[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
