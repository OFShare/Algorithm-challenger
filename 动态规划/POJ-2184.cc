/*
 * Created by OFShare on 2019-11-29
 *
 */

#include <cstdio>
#include <algorithm>

const int maxn = 100 + 5;
int n;
struct node {
  int smartness, funness;
}A[maxn];
int sum[maxn];

// 前i - 1层, 搜到的S, 和F
int ans = 0;
int choosed;
void dfs(int i, int S, int F) {
  // 剪枝
  if (sum[n] - sum[i - 1] + S + F + choosed <= ans)
    return;
  // 递归的边界
  if (i == n + 1) {
    if (S >= 0 && F >= 0)
      ans = std::max(ans, S + F + choosed);
    return ;
  }
  // 选
  dfs(i + 1, S + A[i].smartness, F + A[i].funness);
  // 不选
  dfs(i + 1, S, F);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &A[i].smartness, &A[i].funness);
    // 两正数一定选
    if (A[i].smartness >= 0 && A[i].funness >= 0 ) {
      ans += A[i].smartness + A[i].funness;
      i--;
      n--;
    }
    // 两负数一定不选
    else if (A[i].smartness < 0 && A[i].funness < 0) {
      ans += 0;
      i--;
      n--;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int tmp = A[i].smartness + A[i].funness;
    sum[i] += sum[i - 1] + (tmp >= 0 ? tmp: 0);
  }
  choosed = ans;
  dfs(1, 0, 0);
  printf("%d\n", ans);
  return 0;
}
