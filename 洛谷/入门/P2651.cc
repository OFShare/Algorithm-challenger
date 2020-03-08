/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 22:00:43 PM
 * File Name     : P2651.cc
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
ll t, n, A[N];

int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%lld", &A[i]);

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
      if (i == 2) continue;
      ll gcd = std::__gcd(A[i], A[2]);
      A[2] /= gcd;
      if (A[2] == 1) {
        flag = true;
        break;
      }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
