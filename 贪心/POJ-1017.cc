/*
 * Created by OFShare on 2019-12-05
 *
 */

#include <cstdio>

const int A[] = {0, 5, 3, 1};

int main() {
  int a, b, c, d, e, f;
  while (scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) && (a + b + c + d + e + f)) {
    int ans = 0;
    // 6 * 6, 5 * 5, 4 * 4都要单独占用一个箱子
    ans += f + e + d;
    // 3 * 3单独占用的箱子
    ans += (c + 3) / 4;

    // 接着装2 * 2的, 可以来自装4 * 4的箱子剩下的, 也可以来自装3 * 3剩下的
    int number_2 = d * (36 - 16) / 4;
    number_2 += A[c % 4];

    if (b > number_2) {
      ans += (b - number_2 + 8) / 9;
    }

    int number_1 = ans * 36 - 6 * 6 * f - 5 * 5 * e - 4 * 4 * d - 3 * 3 * c - 2 * 2 * b;
    if (number_1  < a) {
      ans += (a - number_1 + 35) / 36;
    }

    printf("%d\n", ans);
  }
  return 0;
}
