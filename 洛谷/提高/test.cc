/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 17:54:22 PM
 * File Name     : test.cc
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
  int a[5] = {0, };
  int b[5] = {1, 2, };
  int c[5] = {99};
  for (int i = 0; i < 5; ++i) {
    std::cout << "a: " << a[i] << std::endl;
  }
  for (int i = 0; i < 5; ++i) {
    std::cout << "b: " << b[i] << std::endl;
  }
  for (int i = 0; i < 5; ++i) {
    std::cout << "c: " << c[i] << std::endl;
  }
  return 0;
}
