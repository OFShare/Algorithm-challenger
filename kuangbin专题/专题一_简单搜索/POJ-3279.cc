/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 21:48:48 PM
 * File Name     : POJ-3279.cc
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

const int INF = 1e9;
const int N = 15 + 5;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int R, C;

// 记录最少次数
int ans = INF;
int mp[N][N], mp_copy[N][N];
// 每个位置翻转次数
int zero_op[N][N], zero_op_copy[N][N];

bool valid(int x, int y) {
  if (x >= 0 && x < R && y >= 0 && y < C) return true;
  else return false;
}
// 0变1, 1变0, 用~是不行的哟.
// ~0, 可以看成0000取反, 就变成1111了.
void flip(int x, int y) {
  mp_copy[x][y] = 1 - mp_copy[x][y];
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (valid(newx, newy))
      mp_copy[newx][newy] = 1 - mp_copy[newx][newy];
  }
}
bool all_zero(int i) {
  for (int j = 0; j < C; ++j)
    if (mp_copy[i][j] != 0)
      return false;
  return true;
}
int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; ++i) 
    for (int j = 0; j < C; ++j) 
      scanf("%d", &mp[i][j]);
  for (int i = 0; i < (1 << C); ++i) {
    std::memcpy(mp_copy, mp, sizeof mp);
    std::memset(zero_op_copy, 0, sizeof zero_op_copy);

    int op = 0;
    // 枚举第一行
    for (int j = 0; j < C; ++j) {
      if (i & (1 << j))
        flip(0, j), ++op, zero_op_copy[0][j]++; 
    }
    // 从第二行开始处理
    for (int j = 1; j < R; ++j) {
      for (int k = 0; k < C; ++k) {
        if (mp_copy[j - 1][k] == 1)
          flip(j, k), ++op, zero_op_copy[j][k]++;
      }
    }
    // 前R - 1行都被处理成0了, 再检查最后一行是否也全是0
    if (all_zero(R - 1)) {
      if (op < ans)
        ans = op, std::memcpy(zero_op, zero_op_copy, sizeof zero_op_copy);
    }
  }
  if (ans >= INF) printf("IMPOSSIBLE\n");
  else {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        printf("%d ", zero_op[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
