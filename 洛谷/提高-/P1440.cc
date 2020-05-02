/*
 * Author        : xxxx
 * E-mail        : xxxx
 * Created Time  : 2020-03-19 22:36:46 PM
 * File Name     : P1440.cc
 */

#include <bits/stdc++.h>

const int N = 2e6 + 5;
int n, m;

struct node {
  int value, position;
};
// 单调队列, 即value是按升序排列的, 且队列里最多只有m个元素(1.严格升序, 2.最多m个元素, 这两个条件)
// 那么此时前m个元素的最小值就是队列的头元素
std::deque<node> que;

int main() {
  scanf("%d %d", &n, &m);
  std::vector<int> ans;

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (que.empty()) ans.push_back(0);
    else ans.push_back(que.front().value);
    
    // 现在考虑第i个元素要进入队列
    // 注意队列满足的两个条件, 1.严格升序, 2.最多m个元素
    while (!que.empty() && que.back().value >= x)
      que.pop_back();
    que.push_back({x, i});
    while (!que.empty() && i - que.front().position + 1 > m)
      que.pop_front();
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
