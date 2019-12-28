/*
 * Created by OFShare on 2019-12-21
 *
 */

#include <cstdio>

//
bool is_prime(int n) {
  for (int i = 2; 1L * i * i <= 1L * n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// x ^ y % MOD
long long mod_pow(long long x, long long y, long long MOD) {
  long long result = 1;
  while (y > 0) {
    if (y & 1) result = result * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return result % MOD;
}

bool Carmichael_number(int n) {
  for (long long a = 2; a <= n - 1; ++a) {
    if (mod_pow(a, n, n) != a)
      return false;
  }
  return true;
}

int number;
int main() {
  while (scanf("%d", &number) && number) {
    if (!is_prime(number) && Carmichael_number(number)) {
      printf("The number %d is a Carmichael number.\n", number);
    } else {
      printf("%d is normal.\n", number);
    }
  }
  return 0;
}

