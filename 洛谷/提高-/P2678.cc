/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-12 22:39:38 PM
 * File Name     : P2678.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 + 5;
int L, n, m, A[N];

bool check(int x) {
  int keep = 0, pre_id = 0;
  for (int i = 1; i <= n; ++i) {
    if (A[i] - A[pre_id] >= x) {
      ++keep;
      pre_id = i;
    }
  }
  if (L - A[pre_id] < x) return false;
  return n - keep <= m;
}
int main() {
  scanf("%d %d %d", &L, &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }

  // 整数域二分, [L, R)
  int leftt = 1, rightt = L + 1;
  for (int i = 0; i < 50; ++i) {
    int mid = leftt + (rightt - leftt) / 2;
    if (check(mid)) {
      leftt = mid;
    }
    else {
      rightt = mid;
    }
  }
  printf("%d\n", leftt);
  return 0;
}
