/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-06 16:47:13 PM
 * File Name     : P1750.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

int n, c;
std::stack<int> stk;
std::vector<int> ans;

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    while (!stk.empty() && x > stk.top()) {
      ans.push_back(stk.top()), stk.pop(); 
    }
    stk.push(x);
    if (stk.size() == c) {
      ans.push_back(stk.top()), stk.pop(); 
    }
  }
  while (!stk.empty()) {
    ans.push_back(stk.top()), stk.pop(); 

  }
  for (auto &ch: ans) {
    printf("%d ", ch);
  }
  return 0;
}
