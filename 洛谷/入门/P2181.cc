/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 13:39:57 PM
 * File Name     : P2181.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

unsigned long long n;
int main() {
  scanf("%lld", &n);
  printf("%lld\n", n * (n -1) / 2 * (n - 2) / 3 * (n - 3) / 4);
  return 0;
}
