/*
 * Created by OFShare on 2019-12-21
 *
 */

#include <cstdio>

long long gcd(long long a, long long b) {
  return b == 0 ? a: gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a  / gcd(a, b) * b;
}

int main() {
  long long x, y;
  while (scanf("%lld %lld", &x, &y) != EOF) {
    printf("%lld %lld\n", gcd(x, y), lcm(x, y));
  }
  return 0;
}
