/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 17:40:59 PM
 * File Name     : P1223.cc
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
int n;
struct node {
  int number, access_time;
}A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i].access_time);
    A[i].number = i;
  }
  std::sort(A + 1, A + 1 + n, [](const node &lhs, const node &rhs) {
    if (lhs.access_time == rhs.access_time) return lhs.number < rhs.number;
    return lhs.access_time < rhs.access_time;
  });
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (n - i) * A[i].access_time;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", A[i].number);
  }
  printf("\n");
  printf("%.2lf\n", ans / n);
  return 0;
}
