/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 11:28:02 AM
 * File Name     : P2032.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e6 + 5;
int n, k, A[N];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }

  // 单调队列维护, <value, position>
  std::deque<std::pair<int, int> > que;
  for (int i = 1; i <= k; ++i) {
    while (!que.empty()) {
      if (que.back().first <= A[i]) que.pop_back();
      else break;
    }
    que.push_back({A[i], i});
  }
  printf("%d\n", que.front().first);
  for (int i = k + 1; i <= n; ++i) {
    if (i - k + 1 > que.front().second) que.pop_front();
    while (!que.empty()) {
      if (que.back().first <= A[i]) que.pop_back();
      else break;
    }
    que.push_back({A[i], i});
    printf("%d\n", que.front().first);
  }
  return 0;
}
