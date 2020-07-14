/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-16 22:45:48 PM
 * File Name     : POJ-3273.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, m, A[N];

bool check(int x) {
  int cnt = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    // 特判
    if (A[i] > x) return false;
    sum += A[i];
    if (sum > x) ++cnt, sum = 0, --i;
  }
  if (sum && sum <= x) ++cnt;
  return cnt <= m;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  int L = 0, R = 1e9, ans;
  for (int i = 0; i < 50; ++i) {
    int mid = L + (R - L) / 2;
    if (check(mid)) R = mid;
    else L = mid + 1;
  }
  if (check(L) && check(R)) ans = L;
  else ans = R;
  printf("%d", ans);
  return 0;
}
