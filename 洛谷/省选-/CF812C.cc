/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-26 14:43:43 PM
 * File Name     : CF812C.cc
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
ll n, S, A[N];

bool check(ll k) {
  std::vector<ll> vec;
  for (int i = 1; i <= n; ++i) {
    vec.push_back(A[i] + i * k);
  }
  std::sort(vec.begin(), vec.end());
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += vec[i];
  }
  return ans <= S;
}
int main() {
  scanf("%lld %lld", &n, &S);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  // 二分选取的物品的件数, [L, R)
  ll L = 0, R = n + 1;
  for (int i = 0; i <= 50; ++i) {
    ll mid = L + (R -L) / 2;
    if (check(mid)) L = mid;
    else R = mid;
  }
  ll k = L;
  std::vector<ll> vec;
  for (int i = 1; i <= n; ++i) {
    vec.push_back(A[i] + i * k);
  }
  std::sort(vec.begin(), vec.end());
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += vec[i];
  }
  printf("%lld %lld\n", k, ans);
  return 0;
}
