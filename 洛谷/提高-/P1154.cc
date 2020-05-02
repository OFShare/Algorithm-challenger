/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-28 12:28:57 PM
 * File Name     : P1154.c
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
int n, A[N];
bool vis[N];

bool valid(int k) {
  // 注意是k, 2 * k, 3 * k, ... 
  for (int i = k; i < N; i += k) {
    if (vis[i]) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  // 预处理
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int index = std::abs(A[i] - A[j]);
      vis[index] = true;
    }
  }

  // 枚举可能的ｋ, 至少有n个
  for (int k = n; ; ++k) {
    if (valid(k)) {
      printf("%d\n", k);
      break;
    }
  }
  return 0;
}
