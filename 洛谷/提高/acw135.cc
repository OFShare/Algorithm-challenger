/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 12:03:51 PM
 * File Name     : acw135.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e5 + 5;
int n, m;
ll s[N], A[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
    s[i] = s[i - 1] + A[i];
  }
  // 单调队列, 注意第i个元素进来时, 得先更新以第i个元素结尾时的答案, 然后将第i个元素放进队列
  std::deque<ll> que;
  
  ll ans = -1e18;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, A[i]);
    if (!que.empty()) ans = std::max(ans, s[i] - que.front());
    if (i - m >= 1 && !que.empty() && s[i - m] == que.front()) que.pop_front();
    while (!que.empty() && que.back() >= s[i]) que.pop_back();
    que.push_back(s[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
