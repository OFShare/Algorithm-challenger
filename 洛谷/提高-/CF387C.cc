/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-25 17:29:10 PM
 * File Name     : CF387C.cc
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
char A[N];
int n;

// 从start开始找到x000...000这样的数, x不为0后面跟零
int find(int start) {
  if (start > n) return -1;

  int i;
  for (i = start + 1; i <= n; ++i) {
    if (A[i] != '0') break;
  }
  return i - 1;
}
int main() {
  scanf("%s", A + 1);
  n = std::strlen(A + 1);
  int x = find(1);
  int ans = 1;

  for (int y = find(x + 1); y <= n && y != -1; y = find(x + 1)) {
    if (x > y - x || (x == y - x && A[1] >= A[x + 1])) ++ans;
    else ans = 1;
    // 合并
    x = y;
  }
  printf("%d", ans);
  return 0;
}
