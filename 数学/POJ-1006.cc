/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-18 17:52:28 PM
 * File Name     : POJ-1006.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int p, e, i, d;
int main() {
  int kase = 0;
  while (scanf("%d %d %d %d", &p, &e, &i, &d)) {
    if (p + e + i + d == -4) break;
    // 暴力枚举可能的天数
    for (int day = d + 1; ;) {
      if ((day - p) % 23 == 0 && (day - e) % 28 == 0 && (day - i) % 33 == 0) {
        printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, day - d);
        break;
      }
      if ((day - e) % 28 == 0 && (day - i) % 33 == 0) day += 28 * 33;
      else if ((day - i) % 33 == 0) day += 33;
      else if ((day - e) % 28 == 0) day += 28;
      else if ((day - p) % 23 == 0) day += 23;
      else day += 1;
    }

  }
  return 0;
}
