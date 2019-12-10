#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const int maxn = 1e3 + 5;
int n, d;
struct node {
  float start, end;
  bool operator<(node &rhs) {
    return start < rhs.start;
  }
}A[maxn];

int kase = 0;
int main() {
  while (scanf("%d %d", &n, &d) && (n + d)) {
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (y > d)
        ok = false;
      // 转换为区间
      float dis = d * d - y * y;
      A[i].start = x - std::sqrt(dis);
      A[i].end = x + std::sqrt(dis);
    }
    if (!ok) {
      printf("Case %d: -1\n", ++kase);
      continue;
    }
    std::sort(A + 1, A + 1 + n);

    int ans = 1;
    float R = A[1].end;
    for (int i = 2; i <= n; ++i) {
      // 没有交集
      if (A[i].start > R) {
        ++ans;
        R = A[i].end;
      }
      // 有交集
      else {
        R = std::min(R, A[i].end);
      }
    }
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}
