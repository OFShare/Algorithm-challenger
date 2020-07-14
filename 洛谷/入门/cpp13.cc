/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-13 11:53:36 AM
 * File Name     : cpp13.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

void print(int &x) {
  x++;
}
int main() {
  int x = 101;
  print(std::ref(x));
  printf("%d\n", x);
  return 0;
}
