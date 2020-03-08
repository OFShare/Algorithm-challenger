/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 23:37:39 PM
 * File Name     : P3954.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int A, B, C;
int main() {
  scanf("%d %d %d", &A, &B, &C);
  printf("%d\n", (int)(A * 0.2 + B * 0.3 + C * 0.5));
  return 0;
}
