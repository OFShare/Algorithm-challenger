/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-25 16:12:03 PM
 * File Name     : POJ-3076.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

// 备份状态
#define backup() { \
  std::memcpy(b_row, row, sizeof row); \
  std::memcpy(b_col, col, sizeof col); \
  std::memcpy(b_cell, cell, sizeof cell); \
  std::memcpy(b_str, str, sizeof str); \
}

// 恢复状态
#define restore() { \
  std::memcpy(row, b_row, sizeof b_row); \
  std::memcpy(col, b_col, sizeof b_col); \
  std::memcpy(cell, b_cell, sizeof b_cell); \
  std::memcpy(str, b_str, sizeof b_str); \
}

// 更新状态
#define update() { \
  row[i] -= 1 << number; \
  col[j] -= 1 << number; \
  cell[i / 4][j / 4] -= 1 << number; \
  str[i][j] = number + 'A'; \
  cnt--; \
}

const int N = 16;
// row[i]表示第i行可以填那些数字(集合), col[i]表示第i列可以填那些数字(集合), cell[i][j]表示(i, j)这个4 * 4的九宫格可以填那些数字(集合)
int row[N], col[N], cell[N][N];

// ones[i]表示数字i含有多少个1, mp[i]表示数字i, 二进制下1对应的下标是多少
int ones[1 << N], mp[1 << N];
char str[N + 5][N + 5];

// (x, y)这个坐标可以填的数字组成的十进制数(集合)
inline int get(int x, int y) {
  return row[x] & col[y] & cell[x / 4][y / 4];
}
// 返回x的最右边为1的十进制数
inline int lowbit(int x) {
  return x & (-x);
}
// 从这个状态搜下去, 能否搜到答案
bool dfs(int cnt) {
  // 递归的边界
  if (cnt == 0) return true;

  int b_row[N], b_col[N], b_cell[N][N];
  char b_str[N + 5][N + 5];
  // 先把进入当前状态的信息备份
  backup();

  // 对于空格来说, 当只有一个或零个可以填的选择
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (str[i][j] == '-') {
        // 填零个(即无解)
        if (ones[get(i, j)] == 0) {
          restore(); 
          return false;
        }
        // 填一个 
        if (ones[get(i, j)] == 1) {
          int number = mp[get(i, j)];
          row[i] -= 1 << number;
          col[j] -= 1 << number;
          cell[i / 4][j / 4] -= 1 << number;
          str[i][j] = number + 'A';
          cnt--;
        }
      }
    }
  }
  // 递归的边界
  if (cnt == 0) return true;

  // 考虑处理某一(行, 列, 4 * 4宫格), 对于某个未选的字母来说, 如果它不能出现在任何一个'-'标识的位置, 则返回false
  // 如果它只有一个位置可以填, 则直接填上

  // 考虑行
  for (int i = 0; i < N; ++i) {
    // sor维护并集, drawn维护以填的集合, heap维护可选的只能填在某一个空格的集合(把出现两次的剔除)
    int sor = 0, drawn = 0, heap = (1 << N) - 1;
    for (int j = 0; j < N; ++j) {
      if (str[i][j] != '-') {
        heap &= ~(sor & (1 << str[i][j] - 'A'));
        drawn |= (1 << str[i][j] - 'A');
        sor |= (1 << str[i][j] - 'A');
      } else {
        heap &= ~(sor & (get(i, j)));
        sor |= (get(i, j));
      }
    }
    // 无解
    if (sor != (1 << N) - 1) {
      restore();
      return false;
    }
    heap &= ~drawn;
    // 枚举每个可选的字母
    for (int k = heap; k; k -= lowbit(k)) {
      int number = mp[lowbit(k)];
      for (int j = 0; j < N; ++j) {
        if (str[i][j] == '-' && ((1 << number) & get(i, j)) != 0) 
          update();
      }
    }
  }
  // 递归的边界
  if (cnt == 0) return true;

  // 考虑列
  for (int j = 0; j < N; ++j) {
    // heap维护还可以选的字母的集合, all维护所有'-'格子的并集, sor维护所有格子的并集
    int heap = (1 << N) - 1, all = 0, sor = 0;
    for (int i = 0; i < N; ++i) {
      if (str[i][j] != '-')
        heap -= 1 << (str[i][j] - 'A'), sor |= 1 << (str[i][j] - 'A');
      if (str[i][j] == '-')
        all |= get(i, j), sor |= get(i, j);
    }
    // 无解
    if (sor != (1 << N) - 1) {
      restore();
      return false;
    }
    // 枚举每个可选的字母
    for (int k = heap; k; k -= lowbit(k)) {
      int number = mp[lowbit(k)];
      // 交集为空
      if (((1 << number) & all) == 0) {
        restore();
        return false;
      }
      for (int i = 0; i < N; ++i) {
        // 只有一个'-'标识的地方可以填
        if (str[i][j] == '-') {
          bool found = true;
          if ((1 << number & get(i, j)) == 0) continue;
          if ((1 << number & get(i, j)) != 0) {
            for (int u = 0; u < N; ++u) {
              if (u != i && str[u][j] == '-' && (1 << number & get(u, j)) != 0) {
                found = false;
                break;
              }
            }
          }
          if (found) {
            update();
            break;
          }
        }
      }
    }
  }
  // 递归的边界
  if (cnt == 0) return true;

  // 考虑每个4 * 4九宫格
  for (int i = 0; i < N; i += 4) {
    for (int j = 0; j < N; j += 4) {
      // sor维护并集, drawn维护以填的集合, heap维护可选的只能填在某一个空格的集合(把出现两次的剔除)
      int sor = 0, drawn = 0, heap = (1 << N) - 1;
      for (int dx = 0; dx < 4; ++dx) {
        for (int dy = 0; dy < 4; ++dy) {
          if (str[i + dx][j + dy] != '-') {
            heap &= ~(sor & (1 << str[i + dx][j + dy] - 'A'));
            drawn |= (1 << str[i + dx][j + dy] - 'A');
            sor |= (1 << str[i + dx][j + dy] - 'A');
          } else {
            heap &= ~(sor & (get(i + dx, j + dy)));
            sor |= (get(i + dx, j + dy));
          }
          
        }
      }
      // 无解
      if (sor != (1 << N) - 1) {
        restore();
        return false;
      }
      heap &= ~drawn;
      // 枚举每个可选的字母
      for (int k = heap; k; k -= lowbit(k)) {
        int number = mp[lowbit(k)];
        // std::cout << "number: " << (char)(number + 'A') << std::endl;
        bool updated = false;
        for (int dx = 0; dx < 4; ++dx) {
          for (int dy = 0; dy < 4; ++dy) {
            if (str[i + dx][j + dy] == '-' && ((1 << number) & get(i + dx, j + dy)) != 0) {
              row[i + dx] -= 1 << number; 
              col[j + dy] -= 1 << number;
              cell[(i + dx) / 4][(j + dy) / 4] -= 1 << number;
              str[i + dx][j + dy] = number + 'A';
              cnt--;
              updated = true;
              break;
            }
          }
          if (updated) break;
        }
      }
    }
  }
  // 递归的边界
  if (cnt == 0) return true;

  // 找到填数最少的位置
  int mi = 16, x, y;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (str[i][j] == '-') {
        if (ones[get(i, j)] < mi) mi = ones[get(i, j)], x = i, y = j;  
      }
    }
  }

  for (int i = get(x, y); i; i -= lowbit(i)) {
    int number = mp[lowbit(i)];
    row[x] -= 1 << number;
    col[y] -= 1 << number;
    cell[x / 4][y / 4] -= 1 << number;
    str[x][y] = number + 'A';
    if (dfs(cnt - 1)) return true;
    // 回溯
    row[x] += 1 << number;
    col[y] += 1 << number;
    cell[x / 4][y / 4] += 1 << number;
    str[x][y] = '-';
  }
  // 回溯
  restore()
    return false;
}
void init() {
  for (int i = 0; i < N; ++i) row[i] = col[i] = (1 << N) - 1;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      cell[i][j] = (1 << N) - 1;
}
int main() {
  debug();
  for (int i = 0; i < (1 << N); ++i)
    for (int j = i; j; j -= lowbit(j))
      ones[i]++;
  for (int i = 0; i < N; ++i) mp[1 << i] = i;

  while (scanf("%s", str[0]) != EOF) {
    init();
    for (int i = 1; i < N; ++i) scanf("%s", str[i]);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (str[i][j] == '-') ++cnt;
        else {
          row[i] -= 1 << (str[i][j] - 'A');
          col[j] -= 1 << (str[i][j] - 'A');
          cell[i / 4][j / 4] -= 1 << (str[i][j] - 'A');
        }
      }
    }
    dfs(cnt);
    for (int i = 0; i < N; ++i) 
      printf("%s\n", str[i]);
    printf("\n");
  }
  return 0;
}
