/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 12:19:41 PM
 * File Name     : P2192.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, t5 = 0, t0 = 0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == 5) t5++;
    else t0++;
  }
  if (t0 == 0) printf("-1\n");
  if (t5 < 9 && t0 >= 1) printf("0\n");
  else {
    for (int i = 1; i <= t5 / 9 * 9; ++i)
      printf("5");
    for (int i = 1; i <= t0; ++i)
      printf("0");
  }
  return 0;
}
