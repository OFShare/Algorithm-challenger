/*
 * Created by OFShare on 2019-12-07
 *
 */

#include <bits/stdc++.h>

const int maxn = 3e4 + 5;
int n, k;
int A[maxn];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    A[a]++;
  }

  int cnt = 0;
  for (int i = 1; i <= maxn - 3; ++i) {
    if (A[i] >= 1)
      ++cnt;
    if (cnt == k) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("NO RESULT\n");
  return 0;
}
