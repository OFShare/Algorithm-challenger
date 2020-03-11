/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 14:28:13 PM
 * File Name     : P5082.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e7 + 5;
int n;
double A[N], B[N];

int main() {
  scanf("%d", &n);
  double sum_1 = 0, sum_2 = 0, sum_3 = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%lf", &A[i]), sum_1 += A[i];
  for (int i = 1; i <= n; ++i)
    scanf("%lf", &B[i]), sum_2 += B[i], sum_3 += (A[i] - B[i]);
  printf("%.6lf\n", (sum_1 * 3 - sum_2 * 2) * 1.0 / sum_3);
  return 0;
}
