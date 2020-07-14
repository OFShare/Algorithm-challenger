/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-15 11:45:07 AM
 * File Name     : P1404.cc
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
const double eps = -1e-18;
ll n, m, A[N];
// dp[i]维护前i个元素前缀和的最小值
double B[N], sum[N], dp[N];

bool check(double x) {
  sum[0] = 0;
  dp[0] = 1e12;
  for (int i = 1; i <= n; ++i) {
    B[i] = A[i] - x;
    sum[i] = sum[i - 1] + B[i];
    dp[i] = std::min(sum[i], dp[i - 1]);
  }
  // 枚举以B[i]结尾最大的B[i] - B[j]的值, 且j ~ i的长度>= m
  for (int i = 1; i <= n; ++i) {
    int j = i - m;
    if (j >= 0) {
      double mi;
      if (j == 0) mi = 0.0;
      else mi = dp[j];

      if (sum[i] - mi >= eps) return true;
    }
  }
  return false;
}
int main() {
  scanf("%lld %lld", &n, &m);
  // 因为答案要*1000并且舍弃小数 所以可以把原数列的每一项*10000 最后得到的答案/10就好
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
    A[i] *= 10000;
  }
  double L = 0.0, R = 1e9, ans;
  for (int i = 0; i < 500; ++i) {
    double mid = L + (R - L) / 2;
    if (check(mid)) L = mid, ans = mid;
    else R = mid;
  }
  // 实数域二分可能有误差, L, R可能都得尝试, 也可以用ans
  // printf("%.0lf\n", (floor)(ans / 10));
  printf("%.0lf\n", (floor)(L / 10));
  // printf("%.0lf\n", (floor)(R / 10));
  return 0;
}
