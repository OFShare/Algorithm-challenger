/*
 * Created by OFShare on 2019-12-22
 *
 */

#include <cstdio>

const int maxn = 1e6 + 5;
int n;
bool is_prime[maxn];
int sum[maxn];

void find_prime() {
  for (int i = 2; i <= maxn - 5; ++i)
    is_prime[i] = true;
  for (int i = 2; i <= maxn - 5; ++i) {
    if (is_prime[i]) {
      for (long long j = 1L * i * i; j <= maxn - 5; j += i)
        is_prime[j] = false;
    }
  }

  for (int i = 2; i <= maxn - 5; ++i) {
    if (is_prime[i])
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1] + 0;
  }
}

int main() {
  find_prime();
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", sum[n]);
  }
  return 0;
}
