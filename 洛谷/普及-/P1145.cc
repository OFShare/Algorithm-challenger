/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 21:19:30 PM
 * File Name     : P1145.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int k;
int main() {
  std::cin >> k;

  // 枚举m, 光标从0开始
  for (int m = k + 1; ; ++m) {
    // kill k个坏人
    bool found = true;
    int cursor = 0;
    for (int i = 1; i <= k; ++i) {
      // 从当前光标走m步的位置
      cursor = (cursor + m - 1) % (2 * k - i + 1);
      if (cursor < k) {
        found = false;
        break;
      }
    }
    if (found) {
      std::cout << m << std::endl;
      break;
    }
  }
  return 0;
}
