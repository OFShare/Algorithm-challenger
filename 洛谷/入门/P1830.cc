/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 11:35:47 AM
 * File Name     : P1830.cc
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
int n, m, x, y;
int cnt[N][N], last_cnt[N][N];

int main() {
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 1; i <= x; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int k1 = a; k1 <= c; ++k1) {
      for (int k2 = b; k2 <= d; ++k2) {
        cnt[k1][k2]++;
        last_cnt[k1][k2] = i;
      }
    }
  }
  for (int i = 1; i <= y; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (cnt[a][b]) printf("Y %d %d\n", cnt[a][b], last_cnt[a][b]);
    else printf("N\n");
  }
  return 0;
}
