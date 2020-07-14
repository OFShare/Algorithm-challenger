/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-14 22:41:45 PM
 * File Name     : CF642A.cc
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
    int n, m;
    scanf("%d %d", &n, &m);
    if (n == 1) printf("0\n");
    else if (n == 2) printf("%d\n", m);
    else if (n >= 3) printf("%d\n", 2 * m);
  }
  return 0;
}
