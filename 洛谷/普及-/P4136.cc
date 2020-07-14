/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 22:39:35 PM
 * File Name     : P4136.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
int main() {
  while (scanf("%d", &n) && n) {
    int sum = n * n - 1;
    if (sum % 2 == 1) printf("Alice\n");
    else printf("Bob\n");
  }
  return 0;
}
