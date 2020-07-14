/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 19:05:30 PM
 * File Name     : P1714.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e5 + 5;
int n, m, A[N], s[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    s[i] = s[i - 1] + A[i];
  }
  // 单调队列, 维护前缀和的最小值
  std::deque<int> que;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, A[i]);
    if (!que.empty()) ans = std::max(ans, s[i] - que.front());
    if (!que.empty() && i - m >= 1 && que.front() == s[i - m]) que.pop_front();
    while (!que.empty() && que.back() > s[i]) que.pop_back();
    que.push_back(s[i]);
  }
  printf("%d\n", ans);
  return 0;
}
