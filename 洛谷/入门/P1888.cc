/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 12:04:29 PM
 * File Name     : P1888.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::vector<ll> vec;
int main() {
  for (int i = 1; i <= 3; ++i) {
    ll a;
    scanf("%lld", &a);
    vec.push_back(a);
  }

  std::sort(vec.begin(), vec.end());
  ll gcd = std::__gcd(vec[0], vec[2]);
  printf("%lld/%lld\n", vec[0] / gcd, vec[2] / gcd);
  return 0;
}
