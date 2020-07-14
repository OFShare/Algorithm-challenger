/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-17 17:37:35 PM
 * File Name     : POJ-3045.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 + 5;
int n, sum[N];
struct Node {
  int w, s;
  bool operator<(const Node &rhs) const {
    return std::max(rhs.w - s, -rhs.s) < std::max(w - rhs.s, -s);
  }
}A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].w, &A[i].s);
  }
  // 排序后贪心
  std::sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + A[i].w;
  }
  // 可能所有的值都为负值,此处必须初始化为负无穷
  int ans = -1e9;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, sum[n] - sum[i] - A[i].s);
  }
  printf("%d\n", ans);
  return 0;
}
