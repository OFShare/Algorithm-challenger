/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 16:50:30 PM
 * File Name     : P1634.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

long long x, n;
long long dfs(int i) {
  // 递归的边界
  if (i == 0)
    return 1;
  long long tmp = dfs(i - 1);
  return tmp * x + tmp;
}
int main() {
  scanf("%lld %lld", &x, &n);
  long long ret = dfs(n);
  printf("%lld\n", ret);
  return 0;
}
