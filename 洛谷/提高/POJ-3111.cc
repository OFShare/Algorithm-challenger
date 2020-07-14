/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-17 23:30:49 PM
 * File Name     : POJ-3111.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <functional>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, k;
struct Node {
  int v, w;
}A[N];

double B[N];
bool check(double x) {
  for (int i = 1; i <= n; ++i) {
    B[i] = A[i].v - x * A[i].w;
  }
  // 从大到小排序, 然后取前面k个
  std::sort(B + 1, B + 1 + n, std::greater<double>());
  double sum = 0;
  for (int i = 1; i <= k; ++i) {
    sum += B[i];
  }
  return sum >= 0;
}

bool cmp(const std::pair<double, int> &lhs, const std::pair<double, int> &rhs) {
  return lhs.first > rhs.first;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].v, &A[i].w);
  }
  double L = 0, R = 1e12;
  for (int i = 0; i < 70; ++i) {
    double mid = L + (R - L) / 2.0;
    if (check(mid)) L = mid;
    else R = mid;
  }
  std::vector<std::pair<double, int> > ans;
  for (int i = 1; i <= n; ++i) {
    ans.push_back({A[i].v - L * A[i].w, i});
  }
  // std::sort(ans.begin(), ans.end(), [](const std::pair<double, int> &lhs, const std::pair<double, int> &rhs) {
  //   return lhs.first > rhs.first; 
  // });
  std::sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < k; ++i) {
    printf("%d ", ans[i].second);
  }
  return 0;
}
