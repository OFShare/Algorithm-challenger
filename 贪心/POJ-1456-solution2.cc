/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-14 00:27:27 AM
 * File Name     : POJ-1456-solution2.cc
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
struct node {
  int profit, deadline;
  bool operator<(const node &rhs) const {
    return deadline < rhs.deadline;
  }
  bool operator>(const node &rhs) const {
    return profit > rhs.profit; 
  }
}A[N];
int n;

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i)
      scanf("%d %d", &A[i].profit, &A[i].deadline);
  
    // 按截止日期排序, 依次考虑最先截止的物品
    // 因为每天最多只能卖一件, 所以在考虑第i天的时候, 优先队列里最多有i - 1个物品
    // 前面que.size()天每天都卖了一件, 如果que.size() < A[i].deadline, 说明第i件物品可以加入优先队列
    // 如果满了, 如果队列里最便宜的物品利润小于第i天的, 就把它弹出, 让第i天的物品加入优先队列里
    std::priority_queue<node, std::vector<node>, std::greater<node> > que;
    std::sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; ++i) {
      if (que.size() < A[i].deadline) que.push(A[i]);
      else {
        node nd = que.top();
        if (nd.profit < A[i].profit)
          que.pop(), que.push(A[i]);
      }
    }
    int ans = 0;
    while (!que.empty()) {
      node nd = que.top();
      ans += nd.profit;
      que.pop();
    }
    printf("%d\n", ans);
  }
  return 0;
}
