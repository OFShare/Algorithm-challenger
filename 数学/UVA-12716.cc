/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <bits/stdc++.h>

const int maxn = 3e7 + 5;
int T, n;
int sum[maxn];

int gcd(int a, int b) {
  return b == 0? a: gcd(b, a % b);
}

// 有这样一个性质:
// a ^ b = c; a ^ c = b; b ^ c = a;
int XOR(int a, int b) {
  return a ^ b;
}

// 打表, 预先算出来结果
void table() {
  for (int c = 1; c <= maxn; ++c) {
    for (int a = c; a <= maxn; a += c) {
      int b = XOR(a, c);
      if (b < 1 || b > a)
        continue;
      if (/*c == a - b*/ gcd(a, b) == c) {
        sum[a]++;
        //printf("a: %d b: %d c: %d\n", a, b, c);
      }
    }
  }

  for (int i = 1; i <= maxn; ++i) {
    sum[i] = sum[i - 1] + sum[i];
  }
}

int main() {
  table();
  scanf("%d", &T);
  int kase = 0;
  while (T--) {
    scanf("%d", &n);
    printf("Case %d: %d\n", ++kase, sum[n]);
  }
  return 0;
}
