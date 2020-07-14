/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-03 20:50:14 PM
 * File Name     : cpp10.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int main() {
  int a = 10;
  decltype((a)) b = a;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  return 0;
}
