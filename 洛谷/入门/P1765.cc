/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 23:08:17 PM
 * File Name     : P1765.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e2 + 5;
// 每个字母最少需要按得次数
std::map<char, int> mp;
void init() {
  mp['a'] = 1; mp['b'] = 2; mp['c'] = 3;
  mp['d'] = 1; mp['e'] = 2; mp['f'] = 3;
  mp['g'] = 1; mp['h'] = 2; mp['i'] = 3;
  mp['j'] = 1; mp['k'] = 2; mp['l'] = 3;
  mp['m'] = 1; mp['n'] = 2; mp['o'] = 3;
  mp['p'] = 1; mp['q'] = 2; mp['r'] = 3; mp['s'] = 4;
  mp['t'] = 1; mp['u'] = 2; mp['v'] = 3;
  mp['w'] = 1; mp['x'] = 2; mp['y'] = 3; mp['z'] = 4;
  mp['*'] = 1;
  mp[' '] = 1;
  mp['#'] = 1;
}
char A[N];

int main() {
  init();
  std::fgets(A + 1, N, stdin);
  int len = strlen(A + 1) - 1, ans = 0;
  for (int i = 1; i <= len; ++i) {
    ans += mp[A[i]];
  }
  printf("%d\n", ans);
  return 0;
}
