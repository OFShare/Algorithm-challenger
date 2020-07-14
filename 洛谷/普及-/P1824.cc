/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-10 15:13:49 PM
 * File Name     : P1824.cc
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
int n, c;
struct Node {
  int pos;
  bool operator<(const Node &rhs) const {
    return pos < rhs.pos;
  }
}A[N];

bool check(int x) {
  int cnt = 1, pre = 1;
  for (int i = 2; i <= n; ++i) {
    if (A[i].pos - A[pre].pos >= x) {
      ++cnt;
      pre = i;
    }
  }
  return cnt >= c;
}
int main() {
  scanf("%d %d", &n, &c);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i].pos);
  }

  std::sort(A + 1, A + 1 + n);
  int L = 1e9, R = -1e9;
  for (int i = 1; i <= n - 1; ++i) {
    L = std::min(L, A[i + 1].pos - A[i].pos);
  }
  R = std::max(R, A[n].pos - A[1].pos) + 1;

  // 整数域上的二分, [L, R)
  for (int i = 0; i < 50; ++i) {
    int mid = L + (R - L) / 2;
    if (check(mid)) L = mid;
    else R = mid;
  }
  // assert(L == R);
  // printf("L: %d, R: %d\n", L, R);
  printf("%d\n", L);
  return 0;
}
