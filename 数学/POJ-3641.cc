/*
 * Created by OFShare on 2019-12-23
 *
 */

#include <cstdio>

long long p, a;

bool is_prime(long long n) {
  for (int i = 2; 1L * i * i <= 1L * n; ++i)
    if (n % i == 0)
      return false;
  return true;
}

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

int main() {
  while (scanf("%lld %lld", &p, &a) && (p + a)) {
    if (!is_prime(p) && pow_mod(a, p, p) == a % p) {
      printf("yes\n");
    } else
      printf("no\n");
  }
  return 0;
}
