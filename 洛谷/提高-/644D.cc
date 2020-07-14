/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 22:33:06 PM
 * File Name     : 644D.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll t, n, k;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &k);
    ll mi = 1e9;
    for (ll i = 1; 1LL * i * i <= n; ++i) {
      ll a = i, b = n / a;
      if (a * b == n) {
        if (a <= k) mi = std::min(mi, b);
        if (b <= k) mi = std::min(mi, a);
      }
    }
    printf("%lld\n", mi);
  }
  return 0;
}
