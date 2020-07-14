/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-10 17:14:29 PM
 * File Name     : POJ-3122.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int T, n, F;
// double PI = 3.141592653589793
double PI = acos(-1.0);

double area[N];

bool check(double x) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += (int)(area[i] / x);
  }
  return cnt >= F;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &F);
    F += 1;
    double L = 0, R = -1e9;
    for (int i = 1; i <= n; ++i) {
      double r;
      scanf("%lf", &r);
      area[i] = PI * r * r * 1;
      R = std::max(R, area[i]);
    }
    // 实数域上的二分, [L, R]
    for (int i = 0 ; i < 50; ++i) {
      double mid = L + (R - L) * 0.5;
      if (check(mid)) L = mid;
      else R = mid;
    }
    printf("%.4f\n", (L + (R - L) * 0.5));
  }
  return 0;
}
