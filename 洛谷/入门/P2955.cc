/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 22:03:07 PM
 * File Name     : P2955.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
int n;
char tmp[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", tmp + 1);
    if ((tmp[std::strlen(tmp + 1)] - '0') % 2 == 0) printf("even\n");
    else printf("odd\n");
  }
  return 0;
}
