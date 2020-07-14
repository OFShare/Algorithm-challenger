/**
 * Author: OFShare@outlook.com
 *
 * Date: 2020-01-02 Thursday 23:20 PM
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

const int maxn = 1e2 + 5;
int n, m, k;

class matrix {
  public:
    long long data[maxn][maxn];
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
      for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
          if (i == j) data[i][j] = 1;
          else data[i][j] = 0;
        }
      }
    }
    matrix operator*(const matrix &rhs) const {
      matrix C(row, rhs.col);
      C.zeros();
      for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= rhs.col; ++j) {
          for (int k = 1; k <= col; ++k) {
            C.data[i][j] = (C.data[i][j] + data[i][k] * rhs.data[k][j]);
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

matrix pow(matrix mat, int size, int n) {
  matrix result(size, size);
  result.ones();
  matrix x(mat);

  while (n) {
    if (n & 1) result = result * x;
    x = x * x;
    n >>= 1;
  }
  return result;
}

int main() {
  while (scanf("%d %d %d", &n, &m, &k) && (n + m + k)) {
    matrix mat(n + 1, n + 1), init(n + 1, 1);
    mat.zeros();
    mat.data[n + 1][n + 1] = 1;
    init.zeros();
    init.data[n + 1][1] = 1;

    for (int i = 1; i <= k; ++i) {
      char tmp[10];
      int a, b;
      scanf("%s", tmp);
      if (tmp[0] == 'g') {
        scanf("%d", &a);
        mat.data[a][a] = 1;
        mat.data[a][n + 1] += 1;
      } else if (tmp[0] == 'e') {
        scanf("%d", &a);
        for (int r = 1; r <= n + 1; ++r)
          mat.data[a][r] = 0;
      } else {
        scanf("%d %d", &a, &b);
        std::vector<int> vec_tmp;
        vec_tmp.push_back(-1);
        for (int r = 1; r <= n + 1; ++r)
          vec_tmp.push_back(mat.data[a][r]);
        for (int r = 1; r <= n + 1; ++r)
          mat.data[a][r] = mat.data[b][r];
        for (int r = 1; r <= n + 1; ++r)
          mat.data[b][r] = vec_tmp[r];
      }
    }
    //matrix tmp = pow(mat, n + 1, m);
    //printf("\n#####\n");
    //for (int i = 1; i <= n +1; ++i) {
      //for (int j = 1; j <= n + 1; ++j) {
        //printf("%d ", tmp.data[i][j]);
      //}
      //printf("\n");
    //}
    //printf("\n#####\n");
    matrix res = pow(mat, n + 1, m) * init;
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", res.data[i][1]);
    }
    printf("\n");
  }
  return 0;
}
