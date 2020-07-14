/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-13 17:42:53 PM
 * File Name     : cpp20.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

struct A {

};

// constexpr 是 C++11 中的新关键字）
constexpr A a {}; 

int main() {
  throw a;
  int b     {2222};
  std::cout << "b: " << b << std::endl;
  std::cout << "empyt class size: " << (int)(sizeof a) << std::endl;
  return 0;
}
