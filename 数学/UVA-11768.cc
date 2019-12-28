/*
 * Created by OFShare on 2019-12-25
 *
 */

#include <bits/stdc++.h>

int n;

double a_x, a_y;
double b_x, b_y;
long long x_1, y_1;
long long x_2, y_2;

// 已知两点(x1, y1), (x2, y2)求
// 直线方程一般式通解: ax + by + c = 0
void Line(long long x1, long long y1, long long x2, long long y2, long long &a, long long &b, long long &c) {
  a = y2 - y1;
  b = x1 - x2;
  c = x2 * y1 - x1 * y2;
}

// ax + by = gcd(a, b) = d
// b是负数也可以, 建议b >= 0
void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
  if (b == 0) {
    d = a; x = 1; y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

// 平行
int horizon() {
  if (y_1 % 10 != 0) return 0;
  if (a_x > b_x) std::swap(a_x, b_x);
  return std::floor(b_x) - std::ceil(a_x) + 1L;
}

// 垂直
int vertical() {
  if (x_1 % 10 != 0) return 0;
  if (a_y > b_y) std::swap(a_y, b_y);
  return std::floor(b_y) - std::ceil(a_y) + 1L;
}

int solve() {
  if (x_1 == x_2) return vertical();
  if (y_1 == y_2) return horizon();

  long long a, b, c;
  Line(x_1, y_1, x_2, y_2, a, b, c);
  if (b < 0) {
    a = -1 * a; b = -1 * b; c = -1 * c;
  }
  a = 10 * a; b = 10 * b; c = c;

  long long d, x0, y0;
  exgcd(a, b, d, x0, y0);
  // 无整数解
  if (c % std::abs(d) != 0) return 0;

  // 特解, (10 * x11, 10 * y11)是扩大10倍的直线上的整10倍点, 再除以10即(x11, y11)便转换为题目给的含1位小数直线上的整点了
  long long x11 = x0 * (-c) / d;
  long long y11 = y0 * (-c) / d;

  if (a_x > b_x) std::swap(a_x, b_x);
  long long x1_tmp = std::ceil(a_x);
  long long x2_tmp = std::floor(b_x);
  if (x1_tmp > x2_tmp) return 0;
  // 算出进入x1_tmp的第一个整点
  d = std::abs(d);
  long long L_number = x11 + (x1_tmp - x11) / (b / d) * (b / d);
  if (L_number < x1_tmp)
    L_number += (b / d);
  long long R_number = x2_tmp;
  if (L_number > R_number) return 0;
  return (R_number - L_number) / (b / d) + 1L;
}

int main() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf %lf %lf", &a_x, &a_y, &b_x, &b_y);
    x_1 = a_x * 10, y_1 = a_y * 10;
    x_2 = b_x * 10, y_2 = b_y * 10;
    printf("%d\n", solve());
  }
  return 0;
}
