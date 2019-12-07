/*
 * Created by OFShare on 2019-12-07
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
int n;
int A[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }

  int cnt = 0;
  while (true) {
    bool updated = false;
    for (int i = 1; i <= n - 1; ++i) {
      if (A[i] > A[i + 1]) {
        ++cnt;
        std::swap(A[i], A[i + 1]);
        updated = true;
      }
    }
    if (!updated)
      break;
  }
  printf("%d\n", cnt);
  return 0;
}
