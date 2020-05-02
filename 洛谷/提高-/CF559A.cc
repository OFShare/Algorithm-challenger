/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 18:03:45 PM
 * File Name     : CF559A.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll a, b, c, d, e, f;

int main() {
  scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
  ll ans = (c + d + e) * (c + d + e) - a * a - c * c - e * e;
  printf("%lld\n", ans);
  return 0;
}
