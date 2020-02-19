/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 15:59:10 PM
 * File Name     : P1720.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
int main() {
  scanf("%d", &n);
  if (n == 0) printf("0.00\n");
  else if (n == 1) printf("1.00\n");
  else {
    double a = 0, b = 1;
    for (int i = 2; ; ++i) {
      double c = a + b;
      if (i == n) {
        printf("%.2lf\n", c * 1.0);
        break;
      }
      a = b;
      b = c;
    }
  }
  return 0;
}
