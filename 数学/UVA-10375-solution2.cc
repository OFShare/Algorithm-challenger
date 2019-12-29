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
    std::vector<double> vec1;
    std::vector<double> vec2;
    std::vector<double> vec3;
    for (int i = 2; i <= maxn - 5; ++i) {
      if (A[i] > 0) {
        while (A[i]--)
          vec1.push_back(i);
      } else {
        A[i] = -A[i];
        while (A[i]--)
          vec2.push_back(1.0 / i);
      }
    }
    for (int i = 0; i < std::min(vec1.size(), vec2.size()); ++i) {
      vec3.push_back(vec1[i]);
      vec3.push_back(vec2[i]);
    }
    if (vec1.size() > vec2.size()) {
      for (int i = vec2.size(); i < vec1.size(); ++i)
        vec3.push_back(vec1[i]);
    }
    if (vec1.size() < vec2.size()) {
      for (int i = vec1.size(); i < vec2.size(); ++i)
        vec3.push_back(vec2[i]);
    }

    double ans = 1.0;
    for (int i = 0; i < vec3.size(); ++i)
      ans *= vec3[i];
    printf("%.5lf\n", ans);
  }
  return 0;
}
