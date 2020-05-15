/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 12:29:09 PM
 * File Name     : P1823.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll n, ans;

int main() {
  scanf("%lld", &n);
  // 单调队列 + 二分
  std::deque<ll > que;
  for (int i = 1; i <= n; ++i) {
    ll x;
    scanf("%lld", &x);
    if (!que.empty()) {
      auto it = std::upper_bound(que.rbegin(), que.rend(), x);
      ans +=  it - que.rbegin();
      // 判断第一个大于x的值是否存在
      if (it != que.rend()) ans += 1;
    }

    while (!que.empty()) {
      if (que.back() < x) que.pop_back();
      else break;
    }
    que.push_back(x);
  }
  printf("%lld\n", ans);
  return 0;
}
