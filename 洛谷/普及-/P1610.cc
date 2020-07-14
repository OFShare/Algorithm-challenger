/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-19 19:15:18 PM
 * File Name     : P1610.cc
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
int n, dist, pos[N];

int main() {
  scanf("%d %d", &n, &dist);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &pos[i]);
  }
  if (n == 1) printf("0\n"), exit(0);

  std::sort(pos + 1, pos + 1 + n);
  int ans = 0, L = pos[1];
  for (int i = 2; i <= n - 1; ++i) {
    if (pos[i + 1] - L <= dist) ++ans;
    else L = pos[i];
  }
  printf("%d\n", ans);
  return 0;
}
