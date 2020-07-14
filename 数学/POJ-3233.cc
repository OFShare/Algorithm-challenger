/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <cstdio>
#include <cstring>

int n, k, MOD;

struct matrix {
  int data[35][35];
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
}A, res;

void Multiply(const matrix &lhs, const matrix &rhs, matrix &C) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k)
        C.data[i][j] = (C.data[i][j] + (lhs.data[i][k] % MOD) * (rhs.data[k][j] % MOD)) % MOD;
    }
  }
}

void Add(const matrix &lhs, const matrix &rhs, matrix &C) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      C.data[i][j] = (lhs.data[i][j] % MOD + rhs.data[i][j] % MOD) % MOD;
    }
  }
}

// 矩阵快速幂: A ^ n
matrix pow(const matrix &A, int n) {
  matrix result;
  matrix x = A;
  result.ones();
  while (n) {
    if (n & 1) result = Multiply(result, x);
    n >>= 1;
    x = Multiply(x, x);
  }
  return result;
}

// S(n) = A + A ^ 2 + A ^ 3 + ... + A ^ n
void S(int n, matrix &result) {
  if (n == 1) {
    result = A;
    return ;
  }
  if (n == 2) {
    Add(A, pow(A, 2), result);
    return ;
  }
  if (n % 2 == 0) {
    matrix I, tmp, tmp2;
    I.ones();
    S(n / 2, result);
    Add(I, pow(A, n / 2), tmp);
    Multiply(result, tmp, tmp2);
    result = tmp2;
  } else {
    S(n - 1, result);
    matrix tmp;
    Add(result, pow(A, n), tmp);
    result = tmp;
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &MOD);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &A.data[i][j]);
    }
  }
  S(k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", res.data[i][j]);
    }
    printf("\n");
  }
  return 0;
}
