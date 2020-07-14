/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <cstdio>
#include <cstring>

int n, k, MOD;

class matrix {
  public:
    int data[35][35];
    int row;
    int col;
  public:
    matrix() {
      row = col = n;
    }
    void zeros() {
      std::memset(data, 0, sizeof data);
    }
    void ones() {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i == j) data[i][j] = 1;
          else data[i][j] = 0;
        }
      }
    }
    matrix operator*(const matrix &rhs) const {
      matrix C;
      C.zeros();
      for (int k = 1; k <= col; ++k) {
        for (int i = 1; i <= row; ++i) {
          for (int j = 1; j <= rhs.col; ++j) {
            C.data[i][j] = (C.data[i][j] % MOD + data[i][k] % MOD * rhs.data[k][j] % MOD) % MOD;
          }
        }
      }
      return C;
    }

    matrix operator+(const matrix &rhs) const {
      matrix C;
      C.zeros();
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          C.data[i][j] = (data[i][j] % MOD + rhs.data[i][j] % MOD) % MOD;
        }
      }
      return C;
    }
};

// 矩阵快速幂: A ^ n
matrix pow(const matrix &A, int n) {
  matrix result;
  matrix x = A;
  result.ones();
  while (n) {
    if (n & 1) result = result * x;
    //n = n >> 1;
    n >>= 1;
    x = x * x;
  }
  return result;
}

// S(n) = A + A ^ 2 + A ^ 3 + ... + A ^ n
matrix S(int n, const matrix &A) {
  if (n == 1) {
    return A;
  }
  if (n == 2) {
    return A + pow(A, 2);
  }
  if (n % 2 == 0) {
    matrix I;
    I.ones();
    return S(n / 2, A) * (I + pow(A, n / 2));
  } else {
    return S(n - 1, A) + pow(A, n);
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &MOD);
  matrix A;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &A.data[i][j]);
    }
  }
  matrix result = S(k, A);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", result.data[i][j]);
    }
    printf("\n");
  }
  return 0;
}
