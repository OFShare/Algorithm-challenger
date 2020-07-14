/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 17:30:00 PM
 * File Name     : P1803.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
int n;
struct node {
  int start, end;
}A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].start, &A[i].end);
  }
  std::sort(A + 1, A + 1 + n, [](const node &lhs, const node &rhs) {
    return lhs.end < rhs.end;
  });
  int ans = 1, R = A[1].end;
  for (int i = 2; i <= n; ++i) {
    if (R <= A[i].start) ++ans, R = A[i].end;
  }
  printf("%d\n", ans);
  return 0;
}
