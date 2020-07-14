/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-08 17:27:55 PM
 * File Name     : acw138.cc
 */

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
const int MOD = 131;
char A[N];
int m;
ull dp[N];

// 多项式hash, 自然溢出
void init() {
  int len = std::strlen(A + 1);
  for (int i = 1; i <= len; ++i) {
    dp[i] = dp[i - 1] * MOD + A[i];
  }
}
ull mpow(ull base, ull cnt) {
  ull ret = 1, tmp = base;
  for (int i = 0; i < 64; ++i) {
    if ((cnt >> i) & 1) {
      ret *= tmp;
    }
    tmp = tmp * tmp;
  }
  return ret;
}
ull query(int L, int R) {
  return dp[R] - dp[L - 1] * mpow(MOD, R - L + 1);
}

int main() {
  scanf("%s %d", A + 1, &m);
  init();
  while (m--) {
    int l1, r1, l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    ull ret1 = query(l1, r1);
    ull ret2 = query(l2, r2);
    if (ret1 == ret2) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
