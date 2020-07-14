/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 16:41:10 PM
 * File Name     : P1094.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e4 + 5;
int w, n, A[N];

int main() {
  scanf("%d %d", &w, &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &A[i]);

  // 排序后贪心
  std::sort(A + 1, A + 1 + n);
  int L = 1, R = n, ans = 0;
  while (L <= R) {
    if (A[L] + A[R] <= w) ++ans, ++L, --R;
    else ++ans, --R;
  }
  printf("%d\n", ans);
  return 0;
}
