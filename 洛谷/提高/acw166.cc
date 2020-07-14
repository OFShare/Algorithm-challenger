/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-23 22:59:06 PM
 * File Name     : acw166.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 9;
// row[i]表示第i行可以填那些数字(集合), col[i]表示第i列可以填那些数字(集合), cell[i][j]表示(i, j)这个3 * 3的九宫格可以填那些数字(集合)
int row[N], col[N], cell[N][N];

// ones[i]表示数字i含有多少个1, mp[i]表示数字i, 二进制下1对应的下标是多少
int ones[1 << N], mp[1 << N];
char str[105];

// (x, y)这个坐标可以填的数字组成的十进制数
inline int get(int x, int y) {
  return row[x] & col[y] & cell[x / 3][y / 3];
}
// 返回x的最右边为1的十进制数
inline int lowbit(int x) {
  return x & (-x);
}
// 从这个状态搜下去, 能否搜到答案
bool dfs(int cnt) {
  // 递归的边界
  if (cnt == 0) {
    printf("%s\n", str);
    return true;
  }
  // 备份数组必须定义为局部
  int b_row[N], b_col[N], b_cell[N][N];
  char b_str[105];
  std::memcpy(b_row, row, sizeof row);
  std::memcpy(b_col, col, sizeof col);
  std::memcpy(b_cell, cell, sizeof cell);
  std::memcpy(b_str, str, sizeof str);
  
  // 找到填数最少的位置
  int mi = 10, x, y;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (str[i * N + j] == '.') {
        if (ones[get(i, j)] < mi) mi = ones[get(i, j)], x = i, y = j;  
      }
    }
  }
  // 尝试在(x, y)填数字
  for (int i = get(x, y); i; i -= lowbit(i)) {
    int number = mp[lowbit(i)];
    row[x] -= 1 << number;
    col[y] -= 1 << number;
    cell[x / 3][y / 3] -= 1 << number;
    str[x * N + y] = number + '1';
    if (dfs(cnt - 1)) return true;
    // 回溯
    row[x] += 1 << number;
    col[y] += 1 << number;
    cell[x / 3][y / 3] += 1 << number;
    str[x * N + y] = '.';
  }
  // 回溯
  std::memcpy(row, b_row, sizeof b_row);
  std::memcpy(col, b_col, sizeof b_col);
  std::memcpy(cell, b_cell, sizeof b_cell);
  std::memcpy(str, b_str, sizeof b_str);

  return false;
}
void init() {
  for (int i = 0; i < N; ++i) row[i] = col[i] = (1 << N) - 1;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cell[i][j] = (1 << N) - 1;
}
int main() {
  for (int i = 0; i < (1 << N); ++i)
    for (int j = i; j; j -= lowbit(j))
      ones[i]++;
  for (int i = 0; i < N; ++i) mp[1 << i] = i;

  while (scanf("%s", str) && str[0] != 'e') {
    init();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (str[i * N + j] == '.') ++cnt;
        else {
          row[i] -= 1 << (str[i * N + j] - '1');
          col[j] -= 1 << (str[i * N + j] - '1');
          cell[i / 3][j / 3] -= 1 << (str[i * N + j] - '1');
        }
      }
    }
    dfs(cnt);
  }
  return 0;
}
