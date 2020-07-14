/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 19:04:07 PM
 * File Name     : P5019.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, A[N];

// dp[i]: 前i个道路铺平的最少的天数(即全部变为0最少的操作次数)
int dp[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &A[i]);
  for (int i = 1; i <= n; ++i) {
    if (i == 1) dp[i] = A[i];
    else {
      if (A[i] > A[i - 1]) dp[i] = dp[i - 1] + A[i] - A[i - 1];
      else dp[i] = dp[i - 1];
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
