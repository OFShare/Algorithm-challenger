/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 17:19:37 PM
 * File Name     : P1652.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 50 + 5;
int n, x[N], y[N], r[N], x11, y11, x2, y2;
// 判断x11, y11是否在第i个圆里面
bool in_circle(int x11, int y11, int i) {
  if ((x11 - x[i]) * (x11 - x[i]) + (y11 - y[i]) * (y11 - y[i]) <= r[i] * r[i])
    return true;
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &x[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &y[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &r[i]);
  scanf("%d %d %d %d", &x11, &y11, &x2, &y2);
  // 枚举圆
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    // 如果两个点都在同一个圆里, 则对答案没有贡献, 否则对贡献加一
    if (in_circle(x11, y11, i) && in_circle(x2, y2, i)) continue;
    if (in_circle(x11, y11, i) || in_circle(x2, y2, i)) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
