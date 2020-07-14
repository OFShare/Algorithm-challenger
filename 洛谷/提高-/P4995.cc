/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-07 16:48:12 PM
 * File Name     : P4995.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e2 + 5;
ll n, h[N];

ll my_pow(int x, int base) {
  ll ret = 1;
  for (int i = 1; i <= base; ++i) ret *= x;
  return ret;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
  }
  std::sort(h + 1, h + 1 + n);
  h[0] = 0;
  ll ans = 0, cur = 0, L = 1, R = n;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) ans += my_pow(std::abs(h[cur] - h[R]), 2), cur = R, --R;
    else ans += my_pow(std::abs(h[cur] - h[L]), 2), cur = L, ++L; 
  }
  printf("%lld\n", ans);
  return 0;
}
