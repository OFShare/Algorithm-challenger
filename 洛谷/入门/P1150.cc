/*
 * Created by OFShare on 2019-12-07
 *
 */

#include <bits/stdc++.h>

int n, k;
int main() {
  scanf("%d %d", &n, &k);

  int ans = n;
  while (n / k) {
    ans += n / k;
    n = n / k + n % k;
  }
  printf("%d\n", ans);
  return 0;
}
