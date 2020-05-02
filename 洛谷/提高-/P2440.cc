/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-12 23:08:27 PM
 * File Name     : P2440.cc
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
int n, k, A[N];

bool check(int x) {
  if (x == 0) return true;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += A[i] / x;
  }
  return cnt >= k;
}
int main() {
  scanf("%d %d", &n, &k);
  int L = 0, R = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    R = std::max(R, A[i]);
  }
  
  // 整数域二分, [L, R)
  for (int i = 0; i < 50; ++i) {
    int mid = L + (R - L) / 2;
    if (check(mid)) L = mid;
    else R = mid;
  }
  printf("%d\n", L);
  return 0;
}
