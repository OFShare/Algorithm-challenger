/*
 * Created by OFShare on 2019-12-13
 *
 */

#include <iostream>
#include <cstring>

const int INF = 1e9;
const int maxn = 2e3 + 5;
int n, m;
char A[maxn];

int Add[26 + 5];
int Delete[26 + 5];
int dp[maxn][maxn];

int dfs(int L, int R) {
  if (dp[L][R] < INF)
    return dp[L][R];
  if (L == R || L > R)
    return 0;
  if (A[L] == A[R])
    dp[L][R] = dfs(L + 1, R - 1);
  // 删除A[L]
  dp[L][R] = std::min(dp[L][R], dfs(L + 1, R) + Delete[A[L] - 'a']);
  // 删除A[R]
  dp[L][R] = std::min(dp[L][R], dfs(L, R - 1) + Delete[A[R] - 'a']);

  // 在左边添加字符A[R]
  dp[L][R] = std::min(dp[L][R], dfs(L, R - 1) + Add[A[R] - 'a']);
  // 在右边添加字符A[L]
  dp[L][R] = std::min(dp[L][R], dfs(L + 1, R) + Add[A[L] - 'a']);

  return dp[L][R];
}

int main() {
  std::cin >> n >> m;
  std::cin >> A + 1;
  for (int i = 1; i <= n; ++i) {
    char c;
    int add_, delete_;
    std::cin >> c >> add_ >> delete_;
    Add[c - 'a'] = add_;
    Delete[c - 'a'] = delete_;
  }
  std::memset(dp, 0x3f3f3f, sizeof dp);
  std::cout << dfs(1, m);
  return 0;
}
