/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-07 16:12:40 PM
 * File Name     : P3817.cc
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
int n, x, A[N];

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  ll ans = 0, pre = 0;
  for (int i = 1; i <= n; ++i) {
    ll eat = std::max(0LL, pre + A[i] - x);
    A[i] -= eat;
    ans += eat;
    pre = A[i];
  }
  printf("%lld\n", ans);
  return 0;
}
