/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-27 13:32:23 PM
 * File Name     : P2657.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll A, B, cnt;

// 判断x是否是题目所说的wendy数
bool check(ll x) {
  std::vector<int> vec;
  int n = 0;
  while (x) {
    vec.push_back(x % 10);
    x /= 10;
    ++n;
  }
  if (n <= 1) return true;
  for (int i = 0; i < n - 1; ++i) {
    if (std::abs(vec[i] - vec[i + 1]) < 2) return false;
  }
  return true;
}
int main() {
  scanf("%lld %lld", &A, &B);
  for (int i = A; i <= B; ++i) {
    if (check(i)) ++cnt;
  }
  printf("%lld\n", cnt);
  return 0;
}
