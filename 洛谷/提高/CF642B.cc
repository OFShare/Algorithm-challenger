/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-14 22:47:16 PM
 * File Name     : CF642B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 30 + 5;
int t, n, k, A[N], B[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &B[i]);
    }
    std::sort(A + 1, A + 1 + n);
    std::sort(B + 1, B + 1 + n);
    std::reverse(B + 1, B + 1 + n);
    for (int i = 1; i <= k; ++i) {
      if (A[i] < B[i]) A[i] = B[i];
      else break;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += A[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
