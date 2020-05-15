/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-26 17:44:35 PM
 * File Name     : CF792D.cc
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
ll n, q;
char A[N];

// 二进制表示下最低位的1所表示的数(十进制下)
ll lowbit(ll x) {
  return x & (-x);
}
// 检查合法性
bool is_valid(ll x) {
  if (x >= 1 && x <= n) return true;
  return false;
}
int main() {
  scanf("%lld %lld", &n, &q);
  while (q--) {
    ll x;
    scanf("%lld %s", &x, A + 1);
    for (int i = 1; i <= std::strlen(A + 1); ++i) {
      if (A[i] == 'L') {
        ll tmp = x - lowbit(x) / 2;
        if (is_valid(tmp)) x = tmp;
      } else if (A[i] == 'R') {
        ll tmp = x + lowbit(x) / 2;
        if (is_valid(tmp)) x = tmp;
      } else if (A[i] == 'U') {
        ll tmp = x - lowbit(x);
        if (is_valid(tmp) && x == tmp + lowbit(tmp) / 2) {
          x = tmp;
          continue;
        }
        tmp = x + lowbit(x);
        if (is_valid(tmp) && x == tmp - lowbit(tmp) / 2) {
          x = tmp;
          continue;
        }
      }
    }
    printf("%lld\n", x);
  }
  return 0;
}
