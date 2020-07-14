/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-05 21:06:36 PM
 * File Name     : CF485D.cc
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
int n, A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A + 1, A + 1 + n);
  n = std::unique(A + 1, A + 1 + n) - (A + 1);
  int ans = 0;
  // 枚举aj
  for (int j = 1; j <= n; ++j) {
    for (int ai = A[j]; ; ai += A[j]) {
      auto it = std::lower_bound(A + 1, A + 1 + n, ai) - A;
      if (A[it - 1] >= A[j]) ans = std::max(ans, A[it - 1] % A[j]);
      if (it == n + 1) break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
