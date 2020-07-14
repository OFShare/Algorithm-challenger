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
}A;

matrix Multiply(const matrix &lhs, const matrix &rhs) {
  matrix C;
  C.zeros();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k)
        C.data[i][j] = (C.data[i][j] + (lhs.data[i][k] % MOD) * (rhs.data[k][j] % MOD)) % MOD;
    }
  }
  return C;
}

matrix Add(const matrix &lhs, const matrix &rhs) {
  matrix C;
  C.zeros();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      C.data[i][j] = (lhs.data[i][j] % MOD + rhs.data[i][j] % MOD) % MOD;
    }
  }
  return C;
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
matrix S(int n) {
  if (n == 1) {
    return A;
  }
  if (n == 2) {
    return Add(A, pow(A, 2));
  }
  if (n % 2 == 0) {
    matrix I;
    I.ones();
    return Multiply(S(n / 2), Add(I, pow(A, n / 2)));
  } else {
    return Add(S(n - 1), pow(A, n));
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &MOD);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &A.data[i][j]);
    }
  }
  matrix result = S(k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", result.data[i][j]);
    }
    printf("\n");
  }
  return 0;
}
