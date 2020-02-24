/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 15:57:20 PM
 * File Name     : P1534.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
int main() {
  scanf("%d", &n);
  int pre = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    pre = pre + a + b - 8;
    ans += pre;
  }
  printf("%d\n", ans);
}
