/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 11:47:08 AM
 * File Name     : P1876.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll n;
int main() {
  scanf("%lld", &n);
  // 找n以内的平方数
  for (ll i = 1; i * i <= n; ++i) {
    ll a = i * i;
    printf("%lld ", a);
  }
  return 0;
}
