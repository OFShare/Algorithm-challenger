/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 22:14:20 PM
 * File Name     : P3150.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
// 拿到偶数的状态必胜
// 拿到奇数的状态必败
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    if (a & 1) printf("zs wins\n");
    else printf("pb wins\n");
  }
  return 0;
}
