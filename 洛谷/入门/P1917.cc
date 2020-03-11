/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 21:06:36 PM
 * File Name     : P1917.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

// 此题只需分析一下，就知道uim只要走到第1行第2格、第2行第1、3格，第3行第2格就必输。
char A[10 + 5];
int cnt = 0;
int main() {
  for (int i = 1; i <= 9; ++i) {
    std::cin >> A[i];
    if (A[i] != '-') ++cnt;
  }
  if (A[2] == 'X' || A[4] == 'X' || A[6] == 'X' || A[8] == 'X')
    std::cout << "xiaoa will win." << std::endl;
  else 
    std::cout << "Dont know." << std::endl;
  std::cout << cnt << std::endl;

  return 0;
}
