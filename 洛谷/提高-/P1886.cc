/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 13:57:50 PM
 * File Name     : P1886.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6 + 5;
ll n, k, A[N];

int main() {
  scanf("%lld %lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  // 单调队列, 递增 
  std::deque<ll> que;
  std::vector<ll> ans_min, ans_max;
  for (int i = 1; i <= n; ++i) {
    if (i - k >= 1 && !que.empty() && A[i - k] == que.front()) que.pop_front();
    while (!que.empty() && que.back() >= A[i]) que.pop_back();
    que.push_back(A[i]);
    if (i >= k) ans_min.push_back(que.front());
  }
  que.clear();
  // 单调队列, 递减
  for (int i = 1; i <= n; ++i) {
    if (i - k >= 1 && !que.empty() && A[i - k] == que.front()) que.pop_front();
    while (!que.empty() && que.back() <= A[i]) que.pop_back();
    que.push_back(A[i]);
    if (i >= k) ans_max.push_back(que.front());
  }
  for (auto &ch: ans_min) {
    printf("%lld ", ch);
  }
  printf("\n");
  for (auto &ch: ans_max) {
    printf("%lld ", ch);
  }
  return 0;
}
