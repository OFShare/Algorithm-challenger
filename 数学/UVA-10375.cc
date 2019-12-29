/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
int p, q, r, s;
int A[maxn];

// 唯一分解定理
void decompose(int n, bool numerator) {
  for (int i = 2; 1L * i * i <= 1L * n; ++i) {
    while (n % i == 0) {
      if (numerator == true) A[i]++;
      else A[i]--;
      n /= i;
    }
  }
  if (n > 1) {
    if (numerator == true) A[n]++;
    else A[n]--;
  }
}

int main() {
  while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
    std::memset(A, 0, sizeof A);
    for (int i = 2; i <= p; ++i) {
      decompose(i, true);
    }
    for (int i = 2; i <= (r - s); ++i) {
      decompose(i, true);
    }
    for (int i = 2; i <= s; ++i) {
      decompose(i, true);
    }
    for (int i = 2; i <= (p - q); ++i) {
      decompose(i, false);
    }
    for (int i = 2; i <= q; ++i) {
      decompose(i, false);
    }
    for (int i = 2; i <= r; ++i) {
      decompose(i, false);
    }
    double ans = 1.0;
    for (int i = 2; i <= maxn - 5; ++i) {
        ans *= std::pow((double)i, (double)A[i]);
    }
    printf("%.5lf\n", ans);
  }
  return 0;
}
