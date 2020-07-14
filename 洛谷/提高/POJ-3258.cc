/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-15 22:19:49 PM
 * File Name     : POJ-3258.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 + 5;
int L, n, m, A[N];

bool check(int x) {
  int cnt = 0, cur = 0;
  while (1) {
    int it = std::lower_bound(A + 1, A + 1 + n, x + cur) - A;
    if (it == n + 1) {
      if (L - cur < x) return false;
      break;
    } else {
      cur = A[it];
      ++cnt;
    }
  }
  return n - cnt <= m;
}
int main() {
  scanf("%d %d %d", &L, &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A + 1, A + 1 + n);
  int lb = 0, ub = L + 1;
  for (int i = 0; i < 50; ++i) {
    int mid = lb + (ub - lb) / 2;
    if (check(mid)) lb = mid;
    else ub = mid - 1;
  }
  int ans;
  if (check(lb) && check(ub)) ans = ub;
  else ans = lb;
  printf("%d\n", ans);
  return 0;
}
