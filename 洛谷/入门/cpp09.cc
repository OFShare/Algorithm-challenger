/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-31 13:58:21 PM
 * File Name     : cpp09.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

void outOfMem() {
  std::cerr << "\nUnable to satisfy request for memory\n";
  std::abort();
}

int main() {
  std::set_new_handler(outOfMem);
  auto it = new int[1000000000000LL];
  return 0;
}
