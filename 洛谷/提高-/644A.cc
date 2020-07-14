/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 21:39:59 PM
 * File Name     : 644A.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int t;

int main() {
  scanf("%d", &t);
  while (t--) {
    int a, b, mi = 1e9;
    scanf("%d %d", &a, &b);
    if ((a + a) * (a + a) >= (a * b * 2)) 
      mi = std::min(mi, (a + a) * (a + a));
    if ((a + b) * (a + b) >= (a * b * 2)) 
      mi = std::min(mi, (a + b) * (a + b));
    if ((b + a) * (b + a) >= (a * b * 2))
      mi = std::min(mi, (b + a) * (b + a));
    if ((b + b) * (b + b) >= (a * b * 2))
      mi = std::min(mi, (b + b) * (b + b));
    if (a * a >= (a * b * 2))
      mi = std::min(mi, a * a);
    if (b * b >= (a * b * 2))
      mi = std::min(mi, b * b);
    printf("%d\n", mi);
  }
  return 0;
}
