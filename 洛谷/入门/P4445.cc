/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 23:22:23 PM
 * File Name     : P4445.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
int main() {
  scanf("%d", &n);
  ll ans = 0, pre;
  for (int i = 1; i <= n; ++i) {
    ll a;
    scanf("%lld", &a);

    if (i == 1) {
      pre = a;
      continue;
    }
    ans += std::max(pre, a);
    pre = a;
  }
  printf("%lld\n", ans);
  return 0;
}
