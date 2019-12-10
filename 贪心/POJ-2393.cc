/*
 * Created by OFShare on 2019-12-10
 *
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int maxn = 1e4 + 5;
long long  n, S;
long long price[maxn], quantity[maxn];

int main() {
  scanf("%lld %lld", &n, &S);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &price[i], &quantity[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (i == 1) continue;
    price[i] = std::min(price[i], price[i - 1] + S * 1);
  }
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += price[i] * quantity[i];
  }
  printf("%lld\n", sum);
  return 0;
}
