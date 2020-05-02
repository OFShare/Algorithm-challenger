/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 17:22:24 PM
 * File Name     : CF451B.cc
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
int n, A[N], A_copy[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    A_copy[i] = A[i];
  }
  std::sort(A_copy + 1, A_copy + 1 + n);
  int L = 0, R = n + 1;
  for (int i = 1; i <= n; ++i) {
    if (A[i] == A_copy[i]) ++L;
    else break;
  }
  if (L == n) {
    printf("yes\n1 1\n");
    return 0;
  }
  for (int i = n; i >= 1; --i) {
    if (A[i] == A_copy[i]) --R;
    else break;
  }
  for (int i = L + 1, j = R - 1; i <= R - 1; ++i, --j) {
    if (A[i] != A_copy[j]) {
      printf("no\n");
      return 0;
    }
  }
  printf("yes\n%d %d\n", L + 1, R - 1);
  return 0;
}
