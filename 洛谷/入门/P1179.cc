/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 15:52:20 PM
 * File Name     : P1179.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int L, R;
int count(int i) {
  int ret = 0;
  while (i) {
    if (i % 10 == 2) ++ret;
    i /= 10;
  }
  return ret;
}
int main() {
  scanf("%d %d", &L, &R);
  int ans = 0;
  for (int i = L; i <= R; ++i) {
    ans += count(i);
  }
  printf("%d\n", ans);
  return 0;
}
