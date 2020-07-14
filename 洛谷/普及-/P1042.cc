/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 15:52:38 PM
 * File Name     : P1042.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2500 * 25 + 5;
char match[N];

int main() {
  int len = 0;
  for (int i = 1; ; ++i) {
    char ch;
    std::cin >> ch;
    if (ch == 'E') break;
    match[i] = ch;
    ++len;
  }
  // 特判
  if (len == 0) {
    std::cout << "0:0\n";
    std::cout << std::endl;
    std::cout << "0:0\n";
    return 0;
  }
  // 模拟11分制
  int win = 0;
  int lose = 0;
  for (int i = 1; i <= len; ++i) {
    if (match[i] == 'W') ++win;
    else ++lose;
    if (std::abs(win - lose) >= 2 && (win >= 11 || lose >= 11)) {
      std::cout << win << ":" << lose << std::endl;
      win = 0, lose = 0;
    }
  }
  // 始终要输出
  if (win || lose || 1) {
    std::cout << win << ":" << lose << std::endl;
  }
  std::cout << std::endl;
  win = 0, lose = 0;

  // 模拟21分制
  for (int i = 1; i <= len; ++i) {
    if (match[i] == 'W') ++win;
    else ++lose;
    if (std::abs(win - lose) >= 2 && (win >= 21 || lose >= 21)) {
      std::cout << win << ":" << lose << std::endl;
      win = 0, lose = 0;
    }
  }
  if (win || lose) {
    std::cout << win << ":" << lose << std::endl;
  }
  return 0;
}
