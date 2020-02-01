/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 11:33:14 AM
 * File Name     : POJ-1321.cc
 */

#include <cstdio>

const int N = 8 + 2;
int n, k, tot;

char mp[N][N];

// 判断是否合法
bool valid(int x, int y) {
  if (mp[x][y] != '#')
    return false;
  for (int i = 1; i < x; ++i) 
    if (mp[i][y] == 'A') 
      return false;
  for (int j = 1; j < y; ++j) 
    if (mp[x][j] == 'A')
      return false;
  return true;
}

// 字母'A'表示棋子
void dfs(int cur, int k_sum) {
  if (k_sum == k){
    ++tot;
    return ;
  }
  if (cur == n + 1) {
    return ;
  }

  // 这一行尝试放一个棋子
  for (int i = 1; i <= n; ++i) {
    if (valid(cur, i)) {
      mp[cur][i] = 'A';
      dfs(cur + 1, k_sum + 1);
      mp[cur][i] = '#';
    }
  }
  // 这一行一个棋子都不放
  dfs(cur + 1, k_sum + 0);
}

int main() {
  while (scanf("%d %d", &n, &k) && n + k != -2) {
    for (int i = 1; i <= n; ++i) 
      scanf("%s", mp[i] + 1);
    tot = 0;
    dfs(1, 0);
    printf("%d\n", tot);
  }
  return 0;
}
