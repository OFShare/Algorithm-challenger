/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-22 21:19:10 PM
 * File Name     : P1597.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 255 + 5;
int ans[N];
char A[N];

int main() {
  debug();
  while (scanf("%c%c%c%c%c", &A[1], &A[2], &A[3], &A[4], &A[5]) != EOF) {

    if (A[1] == 'a')      ans['a'] = ((A[4] >= '0' && A[4] <= '9')? A[4] - '0': ans[A[4]]);
    else if (A[1] == 'b') ans['b'] = ((A[4] >= '0' && A[4] <= '9')? A[4] - '0': ans[A[4]]);
    else if (A[1] == 'c') ans['c'] = ((A[4] >= '0' && A[4] <= '9')? A[4] - '0': ans[A[4]]);
  }
  printf("%d %d %d\n", ans['a'], ans['b'], ans['c']);
  return 0;
}
