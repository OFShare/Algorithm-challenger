/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-02 22:27:58 PM
 * File Name     : CF810B.cc
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
ll n, f;
struct Node {
  ll quantity, customer, contribute;
  // 按贡献排序
  bool operator<(const Node &rhs) const {
    return contribute > rhs.contribute;
  }
}A[N];

int main() {
  scanf("%lld %lld", &n, &f);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &A[i].quantity, &A[i].customer);
    A[i].contribute = std::min(2 * A[i].quantity, A[i].customer) - std::min(A[i].quantity, A[i].customer);
  }
  std::sort(A + 1, A + 1 + n);
  // 排序后取前f大的即可
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i <= f) ans += A[i].contribute;
    ans += std::min(A[i].quantity, A[i].customer); 
  }
  printf("%lld\n", ans);
  return 0;
}
