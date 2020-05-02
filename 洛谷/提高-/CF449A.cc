/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 18:08:29 PM
 * File Name     : CF449A.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll n, m, k;

int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  if (k > n + m - 2) {
    printf("-1\n"); 
    return 0;
  }

  ll ans = 0;
  if (k <= n - 1) {
    ans = std::max(ans, m * (n / (k + 1)));
  } else {
    ans = std::max(ans, (m / (k - (n - 1) + 1)) * 1);
  }

  if (k <= m - 1) {
    ans = std::max(ans, n * (m / (k + 1)));
  } else {
    ans = std::max(ans, (n / (k - (m - 1) + 1)) * 1);
  }
  printf("%lld\n", ans);
  return 0;
}
