/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-11 23:55:07 PM
 * File Name     : P1011.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 20 + 5;
int a, n, m, x;
// A[i]: 从第i站出发车上的人数
int A[N];
// up, down, 记录每个车站上车和下车的人数
int up[N], down[N];

int main() {
  scanf("%d %d %d %d", &a, &n, &m, &x);
  // 枚举第二个车站上车的人数
  for (int number = 0; number <= 2000; ++number) {
    A[1] = a;
    A[2] = A[1] + number - number;
    up[1] = a;
    up[2] = number;
    down[2] = number;

    for (int i = 3; i <= n - 1; ++i) {
      up[i] = up[i - 1] + up[i - 2];
      down[i] = up[i -1];
      A[i] = A[i - 1] + up[i] - down[i]; 
    }
    // 找到了
    if (A[n - 1] == m) {
      printf("%d\n", A[x]);
      break;
    }
  }
  return 0;
}
