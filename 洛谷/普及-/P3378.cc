/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-06 20:58:51 PM
 * File Name     : P3378.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n;
std::priority_queue<int, std::vector<int>, std::greater<int> > que;

int main() {
  scanf("%d", &n);
  while (n--) {
    int op, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      que.push(x);
    } else if (op == 2) {
      int top = que.top();
      printf("%d\n", top);
    } else if (op == 3) {
      que.pop();
    }
  }
  return 0;
}
