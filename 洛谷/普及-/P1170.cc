/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 21:05:58 PM
 * File Name     : P1170.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, x11, y11, x22, y22;
int main() {
  std::cin >> n;
  while (n--) {
    std::cin >> x11 >> y11 >> x22 >> y22;
    // 两整点之间整点的个数
    int ret = std::__gcd(std::abs(x11 - x22), std::abs(y11 - y22)) - 1;
    if (ret == 0) std::cout << "no\n";
    else std::cout << "yes\n";
  }
  return 0;
}
