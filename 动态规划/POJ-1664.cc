/*
 * Created by OFShare on 2019-12-11
 *
 */

#include <cstdio>

int t;
int m, n;

int dfs(int mm, int nn) {
  if (nn == 1 || mm ==0)
    return 1;
  int sum = 0;
  sum += dfs(mm, nn- 1);
  if (mm - nn >= 0)
    sum += dfs(mm - nn, nn);
  return sum;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &m, &n);
    printf("%d\n", dfs(m, n));
  }
  return 0;
}
