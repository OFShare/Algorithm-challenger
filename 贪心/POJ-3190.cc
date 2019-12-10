/*
 * Created by OFShare on 2019-12-10
 *
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

const int maxn = 5e5 + 5;
int n;
struct node {
  int start, end, id;
  bool operator<(node &rhs) const {
    return start < rhs.start;
  }
}A[maxn];

int ans[maxn];
// <右端点, stall的编号>
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].start, &A[i].end);
    A[i].id = i;
  }
  std::sort(A + 1, A + 1 + n);

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    // 新建stall
    if (que.empty() || que.top().first >= A[i].start) {
      ++cnt;
      ans[A[i].id] = cnt;
      que.push(std::make_pair(A[i].end, cnt));
    }
    // 不用新建
    else {
      int id = que.top().second;
      que.pop();
      ans[A[i].id] = id;
      // 弹出来, 新的进队列
      que.push(std::make_pair(A[i].end, id));
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
