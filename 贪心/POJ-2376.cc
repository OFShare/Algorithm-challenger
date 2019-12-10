/*
 * Created by OFShare on 2019-11-28
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 3e4 + 5;
int n, t;

struct node {
  int start_, end_;
}A[maxn];

bool cmp(const node &lhs, const node &rhs) {
  return lhs.start_ < rhs.start_;
}

int main() {
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].start_, &A[i].end_);
  }
  std::sort(A + 1, A + 1 + n, cmp);
  if (A[1].start_ > 1) {
    printf("-1\n");
    return 0;
  }
  int currentR = A[1].end_;
  bool updated = false;
  int count = 1;
  int currentMax = 0;
  for (int i = 2; i <= n; ++i) {
    // 对于新的区间A[i], 分三种情况讨论
    if (A[i].end_ <= currentR)
      continue;
    else if (A[i].start_ <= currentR + 1) {
      if (A[i].end_ > currentMax) {
        updated = true;
        currentMax = A[i].end_;
      }
    } else {
      if (!updated) {
        printf("-1\n");
        return 0;
      } else {
        currentR = currentMax;
        ++count;
        currentMax = 0;
        updated = false;
        --i;
      }
    }
  }
  if (currentR < t && currentMax < t) {
    printf("-1\n");
    return 0;
  }
  if (updated) ++count;
  printf("%d\n", count);
  return 0;
}
