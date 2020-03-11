/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 11:14:13 AM
 * File Name     : P2669.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int K;
std::vector<ll> vec;
void init() {
  vec.push_back(-1);
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i; ++j) 
      vec.push_back(i);
  }
}
int main() {
  init();
  scanf("%d", &K);
  ll ans = 0;
  for (int i = 1; i <= K; ++i)
    ans += vec[i];
  printf("%lld\n", ans);
  return 0;
}
