/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-21 10:21:12 AM
 * File Name     : P1017.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, base;
std::vector<char> vec;

void solve() {
  while (n) {
    int remainder = n % base;
    // n /= base;
    // if (remainder < 0) remainder -= base, n += 1;
    if (remainder < 0) remainder -= base;
    n = (n - remainder) / base;
    if (remainder >= 10) vec.push_back(remainder - 10 + 'A');
    else vec.push_back(remainder + '0');
  }
}
int main() {
  std::cin >> n >> base;
  std::cout << n << "=";
  solve();
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i];
  std::cout << "(base" << base << ")";
  return 0;
}
