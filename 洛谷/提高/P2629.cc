/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 17:23:54 PM
 * File Name     : P2629.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 * 2 + 5;
ll n, s[N], A[N];

int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= 2 * n; ++i) {
    if (i <= n) scanf("%lld", &A[i]);
    else A[i] = A[i - n];
    s[i] = s[i - 1] + A[i];
  }
  // for (int i = 1; i <= 2 * n; ++i) {
  //   std::cout << "s[i]: " << s[i] << std::endl;
  // }
  // 单调队列, 维护最小值
  std::deque<ll> que;
  int ans = 0;
  for (int k = 1; k <= 2 * n - 1; ++k) {
    if (!que.empty() && k - n >= 1 && que.front() == s[k - n]) que.pop_front();
    while (!que.empty() && que.back() > s[k]) que.pop_back();
    que.push_back(s[k]);
    if (k - n >= 0 && que.front() - s[k - n] >= 0) {
      ans += 1;
      // std::cout << "k: " << k << std::endl;
      // std::cout << "que.front(): " << que.front() << std::endl;
      // std::cout << "s[k - n]: " << s[k - n] << std::endl;
    }
  }
  printf("%d\n", ans);
  return 0;
}
