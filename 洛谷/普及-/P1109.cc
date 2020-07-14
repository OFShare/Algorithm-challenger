/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-13 00:39:25 AM
 * File Name     : P1109.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 50 + 5;
int n, A[N];
int L, R;

int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &A[i]), sum += A[i];
  scanf("%d %d", &L, &R);
  if (sum < n * L || sum > n * R) {
    printf("-1\n");
    return 0;
  }

  int a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    if (A[i] > R) a += A[i] - R;
    if (A[i] < L) b += L - A[i];
  }
  printf("%d\n", std::max(a, b));
  return 0;
}
