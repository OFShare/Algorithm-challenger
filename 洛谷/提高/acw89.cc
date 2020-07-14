/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-12 15:28:53 PM
 * File Name     : acw89.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll a, b, p, ret = 1;

int main() {
  scanf("%lld %lld %lld", &a, &b, &p);
  while (b) {
    if (b & 1) ret = (ret * a) % p;
    b >>= 1;
    a = a * a % p;
  }
  printf("%lld\n", ret % p);
  return 0;
}
