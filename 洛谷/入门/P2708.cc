/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 23:27:00 PM
 * File Name     : P2708.cc
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
char A[N];

int main() {
  scanf("%s", A + 1);
  int ans = 0, len = std::strlen(A + 1);
  for (int i = 1; i <= len; ++i) {
    if (i == 1) continue;
    if (A[i] != A[i - 1]) ++ans;
  }
  if (A[len] == '0') ++ans;
  printf("%d\n", ans);
  return 0;
}
