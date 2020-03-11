/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 20:35:48 PM
 * File Name     : P2666.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4;
int n, cnt[N + 10];
void init() {
  for (int a = 0; a * a <= N; ++a) {
    for (int b = 0; b * b <= N; ++b) {
      if (a * a + b * b <= N) cnt[a * a + b * b]++;
      else break;
    }
  }
}
int main() {
  init();
  scanf("%d", &n);
  int ans = 0;
  for (int c = 0; c * c <= n; ++c) {
    for (int d = 0; d * d <= n; ++d) {
      if (c * c + d * d <= n) ans += cnt[n - c * c - d * d];
      else break;
    }
  }
  printf("%d\n", ans); 
  return 0;
}
