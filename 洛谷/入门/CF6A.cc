/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 14:25:13 PM
 * File Name     : CF6A.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 4 + 5;
int A[N];

int main() {
  for (int i = 1; i <= 4; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= 4; ++j) {
      for (int k = 1; k <= 4; ++k) {
        if (i != j && i != k && j != k) {
          if (A[i] + A[j] > A[k] && A[i] + A[k] > A[j] && A[j] + A[k] > A[i]) {
            printf("TRIANGLE\n"), exit(0);
          }
        }
      }
    }
  }
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= 4; ++j) {
      for (int k = 1; k <= 4; ++k) {
        if (i != j && i != k && j != k) {
          if (A[i] + A[j] >= A[k] && A[i] + A[k] >= A[j] && A[j] + A[k] >= A[i]) {
            printf("SEGMENT\n"), exit(0);
          }
        }
      }
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
