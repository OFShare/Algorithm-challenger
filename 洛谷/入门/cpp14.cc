/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-13 15:13:07 PM
 * File Name     : cpp14.cc
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
  unsigned int n = std::thread::hardware_concurrency();
  std::cout << n << " concurrent threads are supported.\n";
}
