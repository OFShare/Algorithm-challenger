/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-14 23:03:49 PM
 * File Name     : CF642C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll t, n;

int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    if (n == 1) {
      printf("0\n");
      continue;
    }
    ll sum = 0, up = 3, h = 1;
    for (int i = 1; i <= n / 2; ++i) {
      sum += i * (up * 2+ h * 2);
      up += 2;
      h += 2;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
