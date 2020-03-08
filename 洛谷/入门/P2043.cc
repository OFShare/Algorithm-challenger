/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-27 22:06:48 PM
 * File Name     : P2043.cc
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
// P ^ a
std::map<int, int> mp;
void func(int x) {
  for (int i = 2; ; ++i) {
    if (x == 1) break;
    while (x % i == 0) {
      mp[i]++;
      x /= i;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i)
    func(i);
  for (const auto &ch: mp) {
    int p = ch.first;
    int a = ch.second;
    printf("%d %d\n", p, a);
  }
  return 0;
}
