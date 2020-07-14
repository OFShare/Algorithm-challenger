/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <cstdio>
#include <string>
#include <cstring>

const int MOD = 1e4;
int n;

class matrix {
  public:
    long long data[3][3];
    int row;
    int col;
  public:
    matrix() {
      row = col = 2;
      data[1][1] = 1;
      data[1][2] = 1;
      data[2][1] = 1;
      data[2][2] = 0;
    }
    void clear() {
      std::memset(data, 0, sizeof data);
    }
    void ones() {
      data[1][1] = 1;
      data[1][2] = 0;
      data[2][1] = 0;
      data[2][2] = 1;
    }
    matrix operator*(matrix &rhs) const {
      matrix C;
      C.clear();
      for (int k = 1; k <= col; ++k) {
        for (int i = 1; i <= row; ++i) {
          for (int j = 1; j <= rhs.col; ++j) {
            C.data[i][j] = (C.data[i][j] % MOD + data[i][k] % MOD * rhs.data[k][j] % MOD) % MOD;
          }
        }
      }
      return C;
    }
};

// 矩阵快速幂: A ^ n
matrix pow(matrix &A, int n) {
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

int main() {
  while (scanf("%d", &n) && n != -1) {
    if (n == 0) {
      printf("0\n");
      continue;
    }
    if (n == 1) {
      printf("1\n");
      continue;
    }
    matrix A;
    matrix ret = pow(A, n - 1);
    int ans = ret.data[1][1];
    printf("%d\n", ans);
  }
  return 0;
}
