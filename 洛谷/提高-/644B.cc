/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 22:05:10 PM
 * File Name     : 644B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 50 + 5;
int t, n, A[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &A[i]);
    }
    std::sort(A + 1, A + 1 + n);
    int mi = 1e9;
    for (int i = 1; i <= n - 1; ++i) {
      mi = std::min(mi, std::abs(A[i] - A[i + 1]));
    }
    printf("%d\n", mi);
  }
  return 0;
}
