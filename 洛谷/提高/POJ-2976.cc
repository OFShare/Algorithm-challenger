/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-18 11:13:25 AM
 * File Name     : POJ-2976.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
ll n, k, a[N], b[N];
double c[N];

bool check(double x) {
  for (int i = 1; i <= n; ++i) {
    c[i] = a[i] - x * b[i];
  }
  // 排序后贪心取前k大
  double sum = 0;
  std::sort(c + 1, c + 1 + n, std::greater<double>());
  for (int i = 1; i <= k; ++i) {
    sum += c[i];
  }
  return sum >= 0;
}
int main() {
  while (scanf("%lld %lld", &n, &k) && n + k) {
    k = n - k;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
    }
    double L = 0.0, R = 1.0;
    for (int i = 0; i < 50; ++i) {
      double mid = L + (R - L) / 2.0;
      if (check(mid)) L = mid;
      else R = mid;
    }
    // std::cout << "L: " << L << std::endl;
    // std::cout << "R: " << R << std::endl;
    printf("%d\n", (int)(100 * L + 0.5));
  }
  return 0;
}
