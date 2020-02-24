/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 14:02:32 PM
 * File Name     : P1482.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int a, b, c, d;
int main() {
  scanf("%d/%d", &a, &b);
  scanf("%d/%d", &c, &d);
  
  int gcd = std::__gcd(a * c, b * d);
  // 第几列第几行, 先列后行
  printf("%d %d\n", b * d / gcd, a * c / gcd);
  return 0;
}
