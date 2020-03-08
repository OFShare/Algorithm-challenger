/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 23:00:26 PM
 * File Name     : P3742.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n;
char x[N], y[N], z[N];

int main() {
  scanf("%d", &n);
  scanf("%s %s", x + 1, y + 1);
  for (int i = 1; i <= n; ++i) {
    if (y[i] > x[i]) {
      printf("-1\n");
      return 0;
    } else
      z[i] = y[i];
  }
  printf("%s", z + 1);
  return 0;
}
