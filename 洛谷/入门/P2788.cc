/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 16:45:25 PM
 * File Name     : P2788.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int ans = 0;

int main() {
  debug();
  int a;
  while (std::cin >> a)
    ans += a;
  printf("%d\n", ans);
  return 0;
}
