/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 15:14:02 PM
 * File Name     : CF811B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n, m, A[N], B[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= m; ++i) {
    std::memcpy(B, A, sizeof A);
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    int a = A[x], cnt = 0;
    // 统计l, r区间里, 比a小的个数
    for (int k = l; k <= r; ++k) {
      if (A[k] < a) ++cnt;
    }
    if (cnt == x - 1 - l + 1) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
