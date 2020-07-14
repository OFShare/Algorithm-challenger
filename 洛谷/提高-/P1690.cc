/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-06 14:19:47 PM
 * File Name     : P1690.cc
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
const ll INF = 1e18;
ll n, dis[N][N], A[N], p;

void floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dis[i][k] <= INF && dis[k][j] <= INF && dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
      }
    }
  }
}
int main() {
  scanf("%lld", &n);
  std::memset(dis, 0x3f3f3f, sizeof dis);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ll d;
      scanf("%lld", &d);
      dis[i][j] = d;
    }
  }
  floyd();
  scanf("%lld", &p);
  for (int i = 1; i <= p; ++i) {
    scanf("%lld", &A[i]);
  }
  std::sort(A + 1, A + 1 + p);
  ll ans = 1e18;
  do {
    int pre_id = 1;
    ll current = 0;
    for (int i = 1; i <= p; ++i) {
      current += dis[pre_id][A[i]];
      pre_id = A[i];
    }
    current += dis[pre_id][n];
    ans = std::min(ans, current);
  } while (std::next_permutation(A + 1, A + 1 + p));
  printf("%lld\n", ans);
  return 0;
}
