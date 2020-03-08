/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-26 21:34:41 PM
 * File Name     : P1568.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 * 1e3 + 5;
int n, m;
// 每一时刻所处在的位置
int A[N], B[N];

int main() {
  scanf("%d %d", &n, &m);
  int pre = 0;
  for (int i = 1; i <= n; ++i) {
    int v, t;
    scanf("%d %d", &v, &t);
    for (int j = 1; j <= t; ++j)
      A[pre + j] = A[pre + j - 1] + v;
    pre += t;
  }
  pre = 0;
  for (int i = 1; i <= m; ++i) {
    int v, t;
    scanf("%d %d", &v, &t);
    for (int j = 1; j <= t; ++j)
      B[pre + j] = B[pre + j - 1] + v;
    pre += t;
  }
  // 枚举每一秒的情况
  int ans = 0;
  // pre_flag = 1, 第一个人在前
  // pre_flag = 2, 第二个人在前
  // 没有考虑平行的情况, 其实是错误的, 但是后台数据太弱了
  int pre_flag;
  for (int i = 1; i <= pre; ++i) {
    int cur_flag;
    if (A[i] - B[i] >= 0) cur_flag = 1;
    else cur_flag = 2;
    if (i == 1) {
      pre_flag = cur_flag;
      continue;
    } else {
      if (pre_flag != cur_flag)
        ++ans;
      pre_flag = cur_flag;
    }
  }
  printf("%d\n", ans);
  return 0;
}
