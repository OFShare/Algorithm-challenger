/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-08 22:07:02 PM
 * File Name     : P6023.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
ll n, m, k;
std::vector<ll> sons[N];

int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    ll p, q;
    scanf("%lld %lld", &p, &q);
    sons[p].push_back(q);
  }
  // 贪心, 答案在某一天把这n步都走完
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    ll cur = 0;
    for (int j = 0; j < sons[i].size(); ++j) {
      ll q = sons[i][j];
      cur += std::max(0LL, n - q);  
    }
    ans = std::max(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}
