/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-19 17:29:15 PM
 * File Name     : AT907.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
int main() {
  scanf("%d", &n);
  // a第一大, b第二大, 这样可以O(N)维护a, b
  int a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == a || x == b) continue;
    if (x > a) b = a, a = x;
    else if (x > b) b = x;
  }
  printf("%d\n", b);
  return 0;
}
