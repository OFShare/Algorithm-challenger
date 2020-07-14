/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <cstdio>

const int MOD = 1e4;
const int maxn = 1e4 + 5;
int n;
int F[maxn * maxn];

// 找F % MOD 下的循环节
int repetend() {
  F[0] = 0 % MOD; F[1] = 1 % MOD;
  for (int i = 2; ; ++i) {
    F[i] = ((F[i -1] % MOD) + (F[i - 2] % MOD) ) % MOD;
    F[i + 1] = ((F[i] % MOD) + (F[i - 1] % MOD) ) % MOD;
    if (F[i] == F[0] && F[i + 1] == F[1]) {
      return i;
    }
  }
}

int main() {
  int k = repetend();
  while (scanf("%d", &n) && n != -1) {
    int index = n % k;
    printf("%d\n", F[index]);
  }
  return 0;
}
