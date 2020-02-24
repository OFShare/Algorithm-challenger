/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 16:25:00 PM
 * File Name     : P1614.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 3e3 + 5;
int n, m;
long long sum[N];

int main() {
  scanf("%d %d", &n, &m);
  if (n == 0 && m == 0) {
    printf("0\n");
    return 0;
  }
  // 前缀和
  for (int i = 1; i <= n; ++i) {
    long long a;
    scanf("%lld", &a);
    sum[i] = a + sum[i - 1];
  }
  long long ans = INF;
  for (int i = 1; i <= n; ++i) {
    int j = i + m -1;
    if (j > n) break;
    ans = std::min(ans, sum[j] - sum[i - 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
