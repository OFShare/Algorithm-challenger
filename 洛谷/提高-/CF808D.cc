/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 15:57:02 PM
 * File Name     : CF808D.cc
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
ll n, A[N], sum[N], total;

void work() {
  // 前缀和
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + A[i];
  } 
  auto it = std::lower_bound(sum + 1, sum + 1 + n, total);
  auto it2 = std::upper_bound(sum + 1, sum + 1 + n, total);
  if (it2 - it == 1) printf("YES\n"), exit(0);

  // 枚举第i个, 然后在前缀和上二分, 注意total - A[i]可以等于0, 所以要从sum + 0开始
  for (int i = 1; i <= n; ++i) {
    auto it = std::lower_bound(sum + 0, sum + 1 + i - 1, total - A[i]);
    auto it2 = std::upper_bound(sum + 0, sum + 1 + i - 1, total - A[i]);
    if (it2 - it == 1) {
      printf("YES\n");
      exit(0);
    }
  }
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
    total += A[i];
  }
  if (total % 2 != 0) printf("NO\n"), exit(0);
  total /= 2;
  work(), std::reverse(A + 1, A + 1 + n), work();
  printf("NO\n");
  return 0;
}
