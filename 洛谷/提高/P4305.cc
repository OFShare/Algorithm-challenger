/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 16:47:58 PM
 * File Name     : P4305.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 + 5;
int T, n, A[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    std::unordered_map<int, bool> mp;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i) {
      if (mp.find(A[i]) == mp.end()) {
        printf("%d ", A[i]);
        mp[A[i]] = true;
      }
    }
    printf("\n");
  }
  return 0;
}
