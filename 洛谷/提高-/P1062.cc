/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-21 17:36:59 PM
 * File Name     : P1062.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll k, n;
std::vector<int> vec;
// 将ｘ转成二进制
void solve(int x) {
  while (x) {
    int r = x % 2;
    x /= 2;
    vec.push_back(r);
  }
}
int main() {
  std::cin >> k >> n;
  solve(n);
  ll ans = 0;
  for (int i = 0; i < vec.size(); ++i)
    ans += vec[i] * std::pow(k, i);
  std::cout << ans << std::endl;
  return 0;
}
