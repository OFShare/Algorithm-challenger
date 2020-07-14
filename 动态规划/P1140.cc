/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-15 17:40:11 PM
 * File Name     : P1140.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 1e2 + 5;
char A[N], B[N];
// 两个字符对应位置时的相似度
std::map<std::pair<char, char>, int> mp;

// 字符串A的前i个字符和字符串B的前j个字符, 最大的相似度
int dp[N][N];
int dfs(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  // 递归的边界
  if (i == 0 && j == 0)
    return 0;
  if (i && j == 0)
    return dfs(i - 1, j) + mp[{A[i], '-'}];
  if (j && i == 0)
    return dfs(i, j - 1) + mp[{'-', B[j]}];

  // 转移: 从最后一对字符考虑
  int ret = -INF;
  ret = std::max(ret, dfs(i - 1, j - 1) + mp[{A[i], B[j]}]);
  ret = std::max(ret, dfs(i - 1, j) + mp[{A[i], '-'}]);
  ret = std::max(ret, dfs(i, j - 1) + mp[{'-', B[j]}]);
  return dp[i][j] = ret;
}

void init() {
  mp[{'A', 'A'}] = 5; mp[{'A', 'C'}] = -1; mp[{'A', 'G'}] = -2; mp[{'A', 'T'}] = -1; mp[{'A', '-'}] = -3;
  mp[{'C', 'A'}] = -1; mp[{'C', 'C'}] = 5; mp[{'C', 'G'}] = -3; mp[{'C', 'T'}] = -2; mp[{'C', '-'}] = -4;
  mp[{'G', 'A'}] = -2; mp[{'G', 'C'}] = -3; mp[{'G', 'G'}] = 5; mp[{'G', 'T'}] = -2; mp[{'G', '-'}] = -2;
  mp[{'T', 'A'}] = -1; mp[{'T', 'C'}] = -2; mp[{'T', 'G'}] = -2; mp[{'T', 'T'}] = 5; mp[{'T', '-'}] = -1;
  mp[{'-', 'A'}] = -3; mp[{'-', 'C'}] = -4; mp[{'-', 'G'}] = -2; mp[{'-', 'T'}] = -1; mp[{'-', '-'}] = -10000000;
}
int main() {
  int len1, len2;
  scanf("%d %s", &len1, A + 1);
  scanf("%d %s", &len2, B + 1);

  init();
  std::memset(dp, -1, sizeof dp);
  printf("%d\n", dfs(len1, len2));
  return 0;
}
