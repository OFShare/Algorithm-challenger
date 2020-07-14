/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-07 21:33:40 PM
 * File Name     : P2777.cc
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
int n, A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A + 1, A + 1 + n, std::greater<int>());
  std::priority_queue<int, std::vector<int>, std::less<int> > que;
  // 贪心, 看每一位是否可以是冠军
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int top = 0;
    if (!que.empty()) top = que.top();
    if (A[i] + n >= top) ++ans;
    que.push(A[i] + i);
  }
  printf("%d\n", ans);
  return 0;
}
