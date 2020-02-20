/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 15:46:46 PM
 * File Name     : P1161.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    double a;
    int t;
    scanf("%lf %d", &a, &t);
    for (int j = 1; j <= t; ++j)
      ans ^= (int)(a * j);
  }
  printf("%d\n", ans);
  return 0;
}
