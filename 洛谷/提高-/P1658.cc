/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-06 21:25:52 PM
 * File Name     : P1658.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 10 + 5;
int x, n, A[N], vis[1000 * 2];

int main() {
  scanf("%d %d", &x, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    vis[A[i]] = 1;
  }
  std::sort(A + 1, A + 1 + n);
  if (A[1] != 1) printf("-1\n"), exit(0);
  // 贪心, 考虑1 ~ sum都已经被ans枚硬币凑出来了, 添加下一枚硬币(1 <= x <= sum + 1), 转移到1 ~ sum + x, ans += 1
  int sum = 0, ans = 0;
  while (sum < x) {
    for (int i = sum + 1; i >= 1; --i) {
      if (vis[i]) {
        sum += i;
        ++ans;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
