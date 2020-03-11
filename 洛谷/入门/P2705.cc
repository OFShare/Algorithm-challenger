/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 11:24:46 AM
 * File Name     : P2705.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int R, B, C, D, E;
int main() {
  scanf("%d %d %d %d %d", &R, &B, &C, &D, &E);
  int cnt1 = C + D;
  int cnt2 = E + E;
  int ans;
  if (cnt1 >= cnt2) {
    ans = R * C + B * D; 
  } else {
    if (R >= B) ans = B * (E + E) + (R - B) * C;
    else ans = R * (E + E) + (B - R) * D;
  }
  printf("%d\n", ans);
  return 0;
}
