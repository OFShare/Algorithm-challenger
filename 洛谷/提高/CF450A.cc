/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 17:14:49 PM
 * File Name     : CF450A.cc
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
int n, m;

struct Node {
  int round;
  int id;
  bool operator<(const Node &rhs) const {
    if (round == rhs.round) return id > rhs.id;
    return round > rhs.round;
  }
}A[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    A[i].round = std::ceil(x * 1.0 / m);
    A[i].id = i;
  }
  std::sort(A + 1, A + 1 + n);
  printf("%d\n", A[1].id);
  return 0;
}
