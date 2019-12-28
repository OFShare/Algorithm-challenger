/*
 * Created by OFShare on 2019-12-25
 *
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

const int INF = 1e9;
const int maxn = 7e2 + 5;
struct node {
  int x, y;
}A[maxn];

int n;
int main() {
  while (scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &A[i].x, &A[i].y);
    }
    int ans = 2;
    for (int i = 1; i <= n; ++i) {
      std::vector<float> vec;
      for (int j = 1; j <= n; ++j) {
        if (i == j)
          continue;
        // 斜率不存在
        if (A[j].x - A[i].x == 0) {
          vec.push_back(INF);
          continue;
        }
        float k = 1.0 * (A[j].y - A[i].y) / (A[j].x - A[i].x);
        vec.push_back(k);
      }
      std::sort(vec.begin(), vec.end());

      // 求出连续相等的最大的一段
      float pre = vec[0];
      int cnt = 0;
      int cnt_max = 0;
      for (int j = 0; j < vec.size(); ++j) {
        if (pre == vec[j])
          ++cnt;
        else {
          cnt = 1;
          pre = vec[j];
        }
        cnt_max = std::max(cnt_max, cnt);
      }
      // 更新答案
      ans = std::max(ans, cnt_max + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
