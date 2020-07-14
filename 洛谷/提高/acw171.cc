/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-26 12:10:07 PM
 * File Name     : acw171.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 46 + 5;
ll w, n, A[N], ans;
std::vector<int> pre;

// 搜索到A数组的pos位置, 此时重量和为sum, 下标限制为dest时, 的这个状态
// flag维护是否是在搜后一半
void dfs(int pos, ll sum, const int &dest, bool flag) {
  // 剪枝
  if (sum > w) return ;

  // 递归的边界
  if (pos == dest) {
    // 更新全局答案ans
    if (flag) {
      auto it = std::upper_bound(pre.begin(), pre.end(), w - sum) - pre.begin() - 1;
      if (it >= 0 && it < pre.size()) 
        ans = std::max(ans, pre[it] + sum), assert(pre[it] + sum + 0LL <= w + 0LL);
      return ;
    }
    pre.push_back(sum);
    return ;
  }
  // 剪枝
  if (pos > n) return ;

  // 不选
  dfs(pos + 1, sum, dest, flag);
  // 选
  dfs(pos + 1, sum + A[pos], dest, flag);
}
int main() {
  scanf("%lld %lld", &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &A[i]);
  }
  // 优化: 对A数组从大到小排序, 再暴搜
  std::sort(A + 1, A + 1 + n, std::greater<ll>());
  // 先搜前一半
  dfs(1, 0, 1 + (n - 1) / 2 + 1, false);
  std::sort(pre.begin(), pre.end());
  // 再搜后一半
  dfs(1 + (n - 1) / 2 + 1, 0, n + 1, true);
  printf("%lld\n", ans);
  return 0;
}
