/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 22:27:32 PM
 * File Name     : P5660.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 8 + 5;
char A[N];

int main() {
  scanf("%s", A + 1);
  int cnt = 0;
  for (int i = 1; i <= 8; ++i)
    if (A[i] == '1') ++cnt;
  printf("%d\n", cnt);
  return 0;
}
