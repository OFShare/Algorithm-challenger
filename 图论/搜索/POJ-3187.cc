/*
 * Created by OFShare on 2019-11-25
 *
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int n, sum;
int A[15];

bool is_ok() {
  int tmp[15];
  for (int i = 0; i <= n; ++i)
    tmp[i] = A[i];

  int round = n - 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 1; j <= round; ++j)
      tmp[j] = tmp[j] + tmp[j + 1];
    --round;
  }
  if (tmp[1] == sum)
    return true;
  else
    return false;
}

int main() {
  scanf("%d %d", &n, &sum);
  for (int i = 1; i <= n; ++i)
    A[i] = i;
  do {
    if (is_ok())
      break;
  } while(std::next_permutation(A + 1, A + 1 + n));
  for (int i = 1; i <= n; ++i) {
    if (i == 1)
      printf("%d", A[i]);
    else
      printf(" %d", A[i]);
  }
  return 0;
}
