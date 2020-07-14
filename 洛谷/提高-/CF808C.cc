/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 00:18:05 AM
 * File Name     : CF808C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n, w;

struct Node {
  int cap, id, volume;
}A[N];

int main() {
  scanf("%d %d", &n, &w);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i].cap);
    A[i].id = i;
    A[i].volume = A[i].cap;
    sum += std::ceil(A[i].cap / 2.0);
  }
  if (sum > w) printf("-1"), exit(0);

  std::sort(A + 1, A + 1 + n, [](const Node &lhs, const Node &rhs) {
    return lhs.volume > rhs.volume; 
  });
  for (int i = 1; i <= n; ++i) {
    A[i].cap = std::ceil(A[i].volume / 2.0);
    w -= A[i].cap;
  }
  // 模拟, 注意不能超过杯子容量, 排序后贪心的选择前面的杯子尽量装
  for (int i = 1; i <= n; ++i) {
    int left = A[i].volume - A[i].cap;
    if (left <= w) A[i].cap = A[i].volume, w -= left;
    else A[i].cap += w, w = 0;
  }
  // for (int i = 1; i <= n; ++i) {
  //   std::cout << "id: " << A[i].id << "cap: " << A[i].cap << std::endl;
  // }
  std::sort(A + 1, A + 1 + n, [](const Node &lhs, const Node &rhs) {
    return lhs.id < rhs.id;
  });
  for (int i = 1; i <= n; ++i) {
    printf("%d ", A[i].cap);
  }
  return 0;
}
