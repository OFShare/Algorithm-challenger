/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 11:58:37 AM
 * File Name     : P1088.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n, m, A[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  while (m--) {
    std::next_permutation(A + 1, A + 1 + n);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", A[i]);
  }
  return 0;
}
