/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 23:42:40 PM
 * File Name     : P2676.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e4 + 5;
ll n, b, A[N];

int main() {
  scanf("%lld %lld", &n, &b);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  std::sort(A + 1, A + 1 + n, std::greater<ll>());

  ll s = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    s += A[i];
    ++ans;
    if (s >= b) break;
  }
  printf("%lld\n", ans);
  return 0;
}
