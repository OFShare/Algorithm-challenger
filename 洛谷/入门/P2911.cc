/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 21:58:45 PM
 * File Name     : P2911.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 20 + 20 + 40 + 5;
int A[N], s1, s2, s3;

int main() {
  scanf("%d %d %d", &s1, &s2, &s3);
  for (int i = 1; i <= s1; ++i) {
    for (int j = 1; j <= s2; ++j) {
      for (int k = 1; k <= s3; ++k) {
        A[i + j + k]++;
      }
    }
  }
  int maxNumber = 0;
  for (int i = 1; i <= N - 2; ++i) {
    maxNumber = std::max(maxNumber, A[i]);
  }
  for (int i = 1; i <= N - 2; ++i)
    if (A[i] == maxNumber) {
      printf("%d\n", i);
      break;
    }
  return 0;
}
