/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-17 18:04:21 PM
 * File Name     : CFAlarm_Clock.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll t, a, b, c, d;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if (b >= a) printf("%lld\n", b);
    else if (c - d <= 0) printf("-1\n");
    else printf("%lld\n", b + ((a - b + c - d - 1)  / (c - d)) * c);
  }
  return 0;
}
