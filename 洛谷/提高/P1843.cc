/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-16 23:08:46 PM
 * File Name     : POJ-3104.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
ll n, A[N], k;

bool check(ll x) {
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    ll left = std::max(0LL, A[i] - x);
    // cnt += std::ceil(left * 1.0 / k);
    cnt += (left + k - 1) / k;
  }
  return cnt <= x;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  scanf("%lld", &k);
  ll L = 0, R = 1e9, ans;
  for (int i = 0; i < 50; ++i) {
    ll mid = L + (R - L) / 2;
    if (check(mid)) R = mid;
    else L = mid + 1;
  }
  if (check(L) && check(R)) ans = L;
  else ans = R;
  printf("%lld\n", ans);
  return 0;
}
