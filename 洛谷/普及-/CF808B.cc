/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-02 22:15:31 PM
 * File Name     : CF808B.cc
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
ll n, k, sum[N];
int main() {
  scanf("%lld %lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    ll x;
    scanf("%lld", &x);
    sum[i] = sum[i - 1] + x;
  }
  ll s = 0;
  for (int i = 1; i + k - 1 <= n; ++i) {
    s += (sum[i + k - 1] - sum[i - 1]);
  }
  printf("%.9lf\n", s * 1.0 / (n - k + 1));
  return 0;
}
