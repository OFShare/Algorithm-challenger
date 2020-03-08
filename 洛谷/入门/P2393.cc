/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-28 00:35:13 AM
 * File Name     : P2393.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

long double ans = 0, tmp;
int main() {
  while (scanf("%Lf", &tmp) != EOF) {
    ans += tmp * 1e6;
  }
  printf("%.5Lf", ans / 1e6);
  return 0;
}
