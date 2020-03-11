/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 14:37:28 PM
 * File Name     : P5015.cc
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
char A[N];

int main() {
  fgets(A + 1, N - 2, stdin);
  int ans = 0;
  for (int i = 1; i <= std::strlen(A + 1) - 1; ++i) 
    if (A[i] != ' ') ++ans;
  printf("%d\n", ans);
  return 0;
}
