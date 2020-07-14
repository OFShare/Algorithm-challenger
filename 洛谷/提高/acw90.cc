/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-12 15:09:52 PM
 * File Name     : acw90.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll a, b, p, ret;

int main() {
  scanf("%lld %lld %lld", &a, &b, &p);
  // b 用二进制拆分, a * b = a + a + ... + a, 一共b个a相加
  while (b) {
    if (b & 1) ret = (ret + a) % p;
    b >>= 1;
    a = a * 2 % p;
  }
  printf("%lld\n", ret);
  return 0;
}
