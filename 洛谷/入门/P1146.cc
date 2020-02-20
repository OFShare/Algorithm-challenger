/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 15:19:26 PM
 * File Name     : P1146.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n;
int A[N];

int main() {
  scanf("%d", &n);
  printf("%d\n", n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j)
        A[j] = 1 - A[j];
    }
    for (int j = 1; j <= n; ++j) 
      printf("%d", A[j]);
    printf("\n");
  }
  return 0;
}
