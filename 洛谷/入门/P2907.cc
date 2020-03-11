/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 21:54:37 PM
 * File Name     : P2907.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll n, k;
// x头牛, 最终将会有多少群奶牛在平静地吃草
ll dfs(ll x) {
  ll x1 = (x + k) / 2;
  ll x2 = (x - x1);
  if (x1 + x2 == x && x1 - x2 == k && x1 > 0 && x2 > 0) return dfs(x1) + dfs(x2);
  else return 1;
}
int main() {
  scanf("%lld %lld", &n, &k);
  ll ret = dfs(n);
  printf("%lld\n", ret);
  return 0;
}
