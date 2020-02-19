/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 16:11:36 PM
 * File Name     : P1664.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, ans = 0;
int consective_day = 0, lost_day = 0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 1) {
      consective_day -= (int)std::pow(2, lost_day - 1);
      consective_day = std::max(consective_day, 0);
      ++consective_day;
      lost_day = 0;
      assert(consective_day >= 1);
      if (consective_day >= 365) ans += 6;
      else if (consective_day >= 120) ans += 5;
      else if (consective_day >= 30) ans += 4;
      else if (consective_day >= 7) ans += 3;
      else if (consective_day >= 3) ans += 2;
      else if (consective_day >= 1) ans += 1;
    } else {
      ++lost_day;
    }
  }
  printf("%d\n", ans);
  return 0;
}
