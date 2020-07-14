/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-07 23:19:23 PM
 * File Name     : P1843.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, A, B;
std::priority_queue<int, std::vector<int>, std::less<int> > que;

int main() {
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    que.push(x);
  }
  int cur = 0;
  while (1) {
    int top = que.top();
    que.pop();
    // 找到了
    if (cur >= top) printf("%d\n", cur / A), exit(0);
    top -= B;
    cur += A;
    que.push(top);
  }
  return 0;
}
