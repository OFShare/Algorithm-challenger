/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-01 22:56:44 PM
 * File Name     : P2240.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n, T;
struct Node {
  int m, v;
  double rate;
  bool operator<(const Node &rhs) const {
    return rate > rhs.rate;
  }
}A[N];

int main() {
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].m, &A[i].v);
    A[i].rate = A[i].v * 1.0 / A[i].m;
  }
  // 按单位重量的价值贪心
  std::sort(A + 1, A + 1 + n);
  double ans = 0.0;
  for (int i = 1; i <= n; ++i) {
    ans += A[i].rate * std::min(A[i].m, T);
    T = T - std::min(A[i].m, T);
  }
  printf("%.2lf\n", ans);
  return 0;
}
