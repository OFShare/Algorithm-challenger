/*
 * Created by OFShare on 2019-12-23
 *
 */

#include <cstdio>

long long pow_mod(int base, int n, int MOD) {
  long long result = 1;
  long long x = base;
  while (n) {
    if (n & 1) result = result * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return result % MOD;
}

int T, M, H;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &M, &H);
    long long result = 0;
    for (int i = 1; i <= H; ++i) {
      int A, B;
      scanf("%d %d", &A, &B);
      result = (result % M + pow_mod(A, B, M) % M ) % M;
    }
    printf("%lld\n", result);
  }
  return 0;
}
