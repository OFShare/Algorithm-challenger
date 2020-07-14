/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 16:19:32 PM
 * File Name     : P1102.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e5 + 5;
ll n, C;
ll number[N];

int main() {
  scanf("%lld %lld", &n, &C);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &number[i]);
  }

  ll ans = 0;
  std::sort(number + 1, number + 1 + n);
  // 枚举B, 找A是否存在
  for (int i = 1; i <= n; ++i) {
    ll B = number[i];
    ll A = B + C;
    ll cnt = std::upper_bound(number + 1, number + 1 + n, A) - std::lower_bound(number + 1, number + 1 + n, A);
    if (cnt) {
      ans += cnt;
      if (A == B) ans -= 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
