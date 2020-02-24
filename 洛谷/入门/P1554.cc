/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-21 11:52:40 AM
 * File Name     : P1554.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 10 + 5;
int m, n, A[N];
void count(int i) {
  while (i) {
    ++A[i % 10];
    i /= 10;
  }
}
int main() {
  scanf("%d %d", &m, &n);
  for (int i = m; i <= n; ++i) {
    count(i);
  }
  for (int i = 0; i <= 9; ++i) 
    printf("%d ", A[i]);
  return 0;
}
