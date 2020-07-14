/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 20:16:33 PM
 * File Name     : P2947.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, A[N], ans[N];
struct Node {
  int height, id;
};

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  // 单调栈
  std::deque<Node> que;
  for (int i = n; i >= 1; --i) {
    while (!que.empty() && A[i] >= que.front().height) que.pop_front();
    if (que.empty()) ans[i] = 0;
    else ans[i] = que.front().id;
    que.push_front({A[i], i});
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
