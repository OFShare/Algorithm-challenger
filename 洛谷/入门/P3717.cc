/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 16:53:33 PM
 * File Name     : P3717.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

const int N = 1e2 + 5;
int n, m, r;
int vis[N][N];

int main() {
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int k1 = 1; k1 <= n; ++k1) {
      for (int k2 = 1; k2 <= n; ++k2) {
        if ((x - k1) * (x - k1) + (y - k2) * (y - k2) <= r * r)
          vis[k1][k2] = 1;
      }
    }
  }
  int ans = 0;
  for (int k1 = 1; k1 <= n; ++k1) 
    for (int k2 = 1; k2 <= n; ++k2) 
      if (vis[k1][k2])
        ++ans;
  printf("%d\n", ans);
  return 0;
}
