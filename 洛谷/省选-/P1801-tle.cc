/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-07 21:05:43 PM
 * File Name     : P1801.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e5 + 5;
int m, n, A[N], q[N], cnt_get, cnt_q = 1;
std::vector<int> vec;

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &q[i]);
  }
  std::vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    auto it = std::lower_bound(vec.begin(), vec.end(), A[i]);
    vec.insert(it, A[i]);
    while (vec.size() == q[cnt_q]) {
      ++cnt_q;
      ans.push_back(vec[++cnt_get - 1]);
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
