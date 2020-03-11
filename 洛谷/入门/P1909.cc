/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 21:32:02 PM
 * File Name     : P1909.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
int n, ans = INF;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 3; ++i) {
    int number, price;
    scanf("%d %d", &number, &price);
    ans = std::min(ans, (int)(std::ceil(n * 1.0 / number) * price));
  }
  printf("%d\n", ans);
  return 0;
}
