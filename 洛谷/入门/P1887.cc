/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 15:19:22 PM
 * File Name     : P1887.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int N, M;
int main() {
  scanf("%d %d", &N, &M);
  int p = N / M;
  int r = N % M;

  for (int i = 1; i <= M - r; ++i)
    printf("%d ", p);
  for (int i = M - r + 1; i <= M; ++i)
    printf("%d ", p + 1);
  return 0;
}
