/*
 * Created by OFShare on 2019-11-17
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
//Aizu-0121.cc:18:10: error: cannot convert ‘int (*)[5]’ to ‘int**’ for argument ‘1’ to ‘int bfs(int**)’

// c++11新特性, -std=c++11
using matrix = int (*)[5];

// 预先分配的内存, 类似内存池
int poolMatrix[maxn][3][5];
int poolNumber = 0;

std::map< std::string, int> mp;

bool is_answer_state(matrix m) {
  int count = 0;
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (m[i][j] != count++)
        return false;
    }
  }
  return true;
}

std::string matrix2string(matrix m) {
  std::string str;
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 4; ++j) {
      str += m[i][j] + '0';
    }
  }
  return str;
}

void print(matrix m) {
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 4; ++j) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

void copyMatrix(matrix x, matrix y) {
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 4; ++j) {
      y[i][j] = x[i][j];
    }
  }
}

int bfs(matrix m) {
  std::queue< std::pair<matrix, int> > que;
  // 判重, 对于走过的状态就不需要走了
  std::set<std::string> st;
  que.push({m, 0});
  st.insert(matrix2string(m));

  while (!que.empty()) {
    matrix m1 = que.front().first;
    int d1 = que.front().second;
    que.pop();
    // 记录从起点到这个状态最少的步数
    std::string tp = matrix2string(m1);
    mp[tp] = d1;

    // 找到0, 对应的坐标
    int zero_x, zero_y;
    for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= 4; ++j) {
        if (m1[i][j] == 0) {
          zero_x = i;
          zero_y = j;
        }
      }
    }

    for (int i = 0; i < 4; ++i) {
      int xx = zero_x + dx[i];
      int yy = zero_y + dy[i];
      if (xx >= 1 && xx <= 2 && yy >= 1 && yy <= 4) {
        // 交换
        std::swap(m1[zero_x][zero_y], m1[xx][yy]);
        // 深拷贝
        matrix cp = poolMatrix[poolNumber++];
        copyMatrix(m1, cp);
        // 还原
        std::swap(m1[zero_x][zero_y], m1[xx][yy]);

        std::string str = matrix2string(cp);
        if (st.count(str) == 0) {
          que.push({cp, d1 + 1});
          st.insert(str);
        }
      }
    }
  }
  return -1;
}

int main() {
  int A[3][5];
  int count = 0;
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 4; ++j) {
      A[i][j] = count++;
    }
  }
  // 先遍历整个解空间, 并将结果存在std::map里
  bfs(A);

  while (scanf("%d %d %d %d %d %d %d %d", &A[1][1], &A[1][2], &A[1][3], &A[1][4],&A[2][1], &A[2][2], &A[2][3], &A[2][4]) != EOF ) {
    std::string str = matrix2string(A);
    printf("%d\n", mp[str]);
  }
  return 0;
}
