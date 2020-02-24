/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 15:26:15 PM
 * File Name     : P1851.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int s;
// 计算x的所有约数的和, 约数不包含它本身
int func(int x) {
  int ret = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      int a = i;
      int b = x / i;
      ret += a;
      if (b != x && a != b)
        ret += b;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &s);
  int A, B;
  for (int i = s; ; ++i) {
    A = i;
    B = func(A);
    // 忽略那些自己是自己的
    if (A == B)
      continue;
    if (func(B) == A)
      break;
  }
  printf("%d %d\n", A, B);
}
