/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-07 16:02:13 PM
 * File Name     : CF545D.cc
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
int n, A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A + 1, A + 1 + n);
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (sum <= A[i]) ++ans, sum += A[i];
  }
  printf("%d\n", ans);
  return 0;
}
