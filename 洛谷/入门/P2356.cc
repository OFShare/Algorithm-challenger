/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 17:30:47 PM
 * File Name     : P2356.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n;
int mp[N][N];

int check(int i, int j) {
  int ret = 0;
  for (int k = 1; k <= n; ++k) {
    ret += mp[k][j];
  }
  for (int k = 1; k <= n; ++k) {
    ret += mp[i][k];
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &mp[i][j]);
    }
  }
  int ans = 0;
  bool updated = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (mp[i][j] == 0) {
        updated = true;
        ans = std::max(ans, check(i, j));
      }
    }
  }
  if (updated == false) printf("Bad Game!\n");
  else printf("%d\n", ans);
  return 0;
}
