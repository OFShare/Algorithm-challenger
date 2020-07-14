/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-16 22:37:11 PM
 * File Name     : POJ-3150.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}
int n, m, d, k, MOD;

// 除0了, i / 0 或 i % 0 都会报浮点错误(Floating point exception)
class matrix {
  public:
    long long data[505][505];
    int row;
    int col;
  public:
    matrix(int ro, int co) {
      row = ro;
      col = co;
    }
    void zeros() {
      std::memset(data, 0, sizeof data);
    }
    void ones() {
      zeros();
      for (int i = 1; i <= row; ++i)
        data[i][i] = 1;
    }
    matrix operator*(matrix &rhs) {
      // 从第一行递推处理rhs
      for (int i = 2; i <= rhs.row; ++i) {
        for (int j = 1; j <= rhs.col; ++j) {
          int k1 = i - 1;
          int k2 = j - 1;
          if (k1 == 0) k1 += rhs.row;
          if (k2 == 0) k2 += rhs.row;
          rhs.data[i][j] = rhs.data[k1][k2];
        }
      }
      matrix C(row, rhs.col);
      C.zeros();
      for (int i = 1; i <= 1; ++i) {
        for (int j = 1; j <= rhs.col; ++j) {
          for (int k = 1; k <= col; ++k) {
            C.data[i][j] = (C.data[i][j] + data[i][k] * rhs.data[k][j]) % MOD;
          }
        }
      }
      return C;
    }

    matrix operator+(const matrix &rhs) const {
      matrix C(row, rhs.col);
      C.zeros();
      for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
          C.data[i][j] = (data[i][j] + rhs.data[i][j]);
        }
      }
      return C;
    }
};

// A ^ k
matrix matrix_pow(matrix A, int k) {
  matrix ans(A.row, A.col);
  ans.ones();
  while (k) {
    if (k & 1) ans = ans * A;
    A = A * A;
    k >>= 1;
  }
  return ans;
}
matrix multiply(matrix &lhs, matrix &rhs) {
  // 从第一行递推处理lhs
  for (int i = 2; i <= lhs.row; ++i) {
    for (int j = 1; j <= lhs.col; ++j) {
      int k1 = i - 1;
      int k2 = j - 1;
      if (k1 == 0) k1 += rhs.row;
      if (k2 == 0) k2 += rhs.row;
      lhs.data[i][j] = lhs.data[k1][k2];
    }
  }
  matrix C(lhs.row, rhs.col);
  C.zeros();
  for (int i = 1; i <= lhs.row; ++i) {
    for (int j = 1; j <= rhs.col; ++j) {
      for (int k = 1; k <= lhs.col; ++k) {
        C.data[i][j] = (C.data[i][j] + lhs.data[i][k] * rhs.data[k][j]) % MOD;
      }
    }
  }
  return C;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &d, &k);
  MOD = m;
  matrix A(n, n), B(n, 1);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &B.data[i][1]);
  // 构造转移矩阵, 因为这个矩阵是循环矩阵
  // 我们只需要保存第一行即可, 矩阵剩下的元素都可以递推出来
  // 对于循环矩阵A, B. A + B, A * B 任然是循环矩阵, A * B = B * A
  for (int j = 1; j <= n; ++j) {
    if (std::min(j - 1, n - (j - 1)) <= d) A.data[1][j] = 1;
    else A.data[1][j] = 0;
  }
  matrix ret = matrix_pow(A, k);
  ret = multiply(ret, B);
  for (int i = 1; i <= n; ++i) 
    printf("%lld ", ret.data[i][1]);
  return 0;
}
