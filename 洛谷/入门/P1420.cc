/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 13:49:31 PM
 * File Name     : P1420.cc
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
  int pre, ans = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);

    if (i == 1) {
      ans = 1;
      cur = 1;
      pre = a;
      continue;
    }
    if (a - pre == 1) ++cur;
    else cur = 1;
    pre = a;
    ans = std::max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
