/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-07 13:02:27 PM
 * File Name     : acw128.cc
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
int q, x, cnt;
std::stack<int> stkL, stkR;
int sum[N], ans_max[N];

int main() {
  std::cin >> q;
  while (q--) {
    char op;
    std::cin >> op;
    if (op == 'I') {
      std::cin >> x;
      stkL.push(x);
      ++cnt;
      sum[cnt] = sum[cnt - 1] + x;
      if (cnt == 1) ans_max[cnt] = x;
      else ans_max[cnt] = std::max(ans_max[cnt - 1], sum[cnt]);
    } else if (op == 'Q') {
      std::cin >> x;
      printf("%d\n", ans_max[x]);
    } else if (op == 'L') {
      if (stkL.empty()) continue;
      int top = stkL.top();
      stkL.pop();
      stkR.push(top);
      --cnt;
    } else if (op == 'D') {
      if (stkL.empty()) continue;
      stkL.pop();
      --cnt;
    } else if (op == 'R') {
      if (stkR.empty()) continue;
      int top = stkR.top();
      stkR.pop();
      stkL.push(top);
      ++cnt;
      sum[cnt] = sum[cnt - 1] + top;
      if (cnt == 1) ans_max[cnt] = x;
      else ans_max[cnt] = std::max(ans_max[cnt - 1], sum[cnt]);
    }
  }
  return 0;
}
