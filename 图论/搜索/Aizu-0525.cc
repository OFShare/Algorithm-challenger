/*
 * Created by OFShare on 2019-11-25
 *
 */

#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>

const int maxn = 10005;
int n, m;
int mp[15][maxn];

void flip_row(int row, int matrix[][maxn]) {
  for (int j = 0; j < m; ++j)
    if (matrix[row][j] == 1)
      matrix[row][j] = 0;
    else
      matrix[row][j] = 1;
}

int main() {
  while (scanf("%d %d", &n, &m) && (n + m)) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &mp[i][j]);
      }
    }

    int tmp[15][maxn];
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
      std::memcpy(tmp, mp, sizeof mp);
      for (int k = 0; k < n; ++k) {
        // 翻转第k行
        if (i & (1 << k)) {
          flip_row(k, tmp);
        }
      }

      int sum = 0;
      for (int j = 0; j < m; ++j) {
        int sum_1 = 0;
        for (int k = 0; k < n; ++k)
          sum_1 += tmp[k][j];
        sum += std::max(sum_1, n - sum_1);
      }
      ans = std::max(ans, sum);
    }
    printf("%d\n", ans);
  }
}
