/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <bits/stdc++.h>

const int MOD = 10001;
const int maxn = (1e2 + 5) * 2;
int T;
int X[maxn];
int main() {
  scanf("%d", &T);
  for (int i = 1; i <= 2 * T - 1; i += 2) {
    scanf("%d", &X[i]);
  }
  // 枚举a, b
  for (int a = 0; a <= 10000; ++a) {
    for (int b = 0; b <= 10000; ++b) {
      bool flag = true;
      for (int i = 1; i <= 2 * T - 1; ++i) {
        if (i % 2 == 1) {
          X[i + 1] = (a * X[i] + b) % MOD;
        } else {
          if (X[i + 1] != (a * X[i] + b) % MOD) {
            flag = false;
            break;
          }
        }
      }
      // 找到一组a, b满足
      if (flag) {
        for (int i = 2; i <= 2 * T; i += 2) {
          printf("%d\n", X[i]);
        }
        return 0;
      }
    }
  }
  return 0;
}
