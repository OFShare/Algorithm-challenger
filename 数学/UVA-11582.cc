/*
 * Created by OFShare on 2019-12-26
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e3 * 1e3 + 5;
int t;
unsigned long long a, b, n;

int pow_mod(unsigned long long a, unsigned long long b, int k) {
  unsigned long long result = 1;
  unsigned long long x = a;
  while (b) {
    if (b & 1) result = 1U * (result % k) * (x % k) % k;
    x = 1U * (x % k) * (x % k) % k;
    b >>= 1;
  }
  return (int)(result % k);
}

int A[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%llu %llu %llu", &a, &b, &n);
    A[0] = 0 % n;
    A[1] = 1 % n;
    int k;
    for (int i = 2; ; ++i) {
      A[i] = ((A[i - 1] % n) + (A[i - 2] % n)) % n;
      A[i + 1] = ((A[i] % n) + (A[i - 1] % n)) % n;
      // 寻找循环节
      if (A[i] == A[0] && A[i + 1] == A[1]) {
        k = i - 0;
        break;
      }
    }
    // a^b % k == (a % k) ^ b % k
    //int i = pow_mod(a, b, k);
    int i = pow_mod(a % k, b, k);
    printf("%d\n", A[i]);
  }
  return 0;
}
