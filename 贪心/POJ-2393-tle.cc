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
  // 更新price[j], 每存放一周是S, 二周就是2 * S, ..., N周就是 N * S
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i < j; ++i) {
      price[j] = std::min(price[j], price[i] + S * (j - i));
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += price[i] * quantity[i];
  }
  printf("%lld\n", sum);
  return 0;
}
