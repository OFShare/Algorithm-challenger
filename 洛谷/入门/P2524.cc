/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 21:15:21 PM
 * File Name     : P2524.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 9 + 5;
int n;
char A[N];

int factor(int x) {
  if (x == 0 || x == 1) return 1;
  else return factor(x - 1) * x;
}
// 康托展开
int cantor() {
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = i + 1; j <= n; ++j)
      if (A[j] < A[i]) ++cnt;
    ret += cnt * factor(n - i);
  }
  return ret;
}
int main() {
  scanf("%d %s", &n, A + 1);
  printf("%d\n", cantor() + 1);
  return 0;
}
