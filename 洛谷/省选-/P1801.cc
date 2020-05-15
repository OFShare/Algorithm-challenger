/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-07 22:00:55 PM
 * File Name     : P1801.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e5 + 5;
int m, n, A[N];
std::priority_queue<int, std::vector<int>, std::less<int> > que_max;
std::priority_queue<int, std::vector<int>, std::greater<int> > que_min;
std::vector<int> ans;

// 如果求第(k + 1)大的元素, 那么que_max里维护的便是前k大的元素, que_min维护的是第k + 1大, 第k + 2大,...的元素
// 所以答案就是que_min.top()
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &A[i]);
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    while (cnt < x) {
      ++cnt;
      que_max.push(A[cnt]);
      que_min.push(que_max.top());
      que_max.pop();
    }
    ans.push_back(que_min.top());
    que_max.push(que_min.top());
    que_min.pop();
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
