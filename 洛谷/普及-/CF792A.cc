/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 16:27:37 PM
 * File Name     : CF792A.cc
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
ll n, A[N];

int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  std::sort(A + 1, A + 1 + n);
  ll min_ans = 1e18;
  for (int i = 1; i < n; ++i) {
    min_ans = std::min(min_ans, std::abs(A[i] - A[i + 1]));
  }
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (std::abs(A[i] - A[i + 1]) == min_ans) ++cnt;
  }
  printf("%lld %d\n", min_ans, cnt);
  return 0;
}
