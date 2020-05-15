/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 15:35:29 PM
 * File Name     : CF845C.cc
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
int n;
struct Node {
  int start, end;
  bool operator<(const Node &rhs) const {
    return start < rhs.start;
  }
  bool operator>(const Node &rhs) const {
    return end > rhs.end;
  }
}A[N];

// 优先队列维护
std::priority_queue<Node, std::vector<Node>, std::greater<Node> > que;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].start, &A[i].end);
  }
  std::sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; ++i) {
    if (que.size() <= 1) que.push(A[i]);
    else {
      Node top = que.top(); que.pop();
      if (top.end < A[i].start) que.push(A[i]);
      else printf("NO\n"), exit(0);
    }
  }
  printf("YES\n");
  return 0;
}
