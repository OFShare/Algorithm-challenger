/*
 * Created by OFShare on 2019-12-24
 *
 */

#include <cstdio>

long long a, b;

// gcd(a, b)
long long gcd(long long a, long long b) {
  return b == 0 ? a: gcd(b, a % b);
}

// 注意d是可以为负数的
// ax + by = gcd(a, b), d = gcd(a, b)
// ax + by = c 有解
// 先求ax + by = gcd(a, b)的一组特解, (x0, y0)
// 因为有解 gcd(a, b) | c , 所以ax + by = c 的一组特解, (x1, y1) = (x0 * c / gcd(a, b), y0 * c / gcd(a, b))

// 所以ax + by = c 的通解为(k取任意整数):
// ax + by = -c通解也是一样的
// (x2, y2) = (x1 + k* b / gcd(a, b), y1 - k * a / gcd(a, b))
void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
  if (b == 0) {
    d = a; x = 1; y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int main() {
  while (scanf("%lld %lld", &a, &b) != EOF) {
    if (gcd(a, b) != 1) {
      printf("sorry\n");
    } else {
      long long d0, x0, y0;
      exgcd(a, b, d0, x0, y0);
      long long x1 = x0, y1 = y0;

      // 寻找最小的非负x2
      if (x1 <= 0) {
        for (int k = 0; ; ++k) {
          long long x2 = x1 + k * b / gcd(a, b);
          long long y2 = y1 - k * a / gcd(a, b);
          if ( x2 >= 0) {
            printf("%lld %lld\n", x2, y2);
            break;
          }
        }
      } else {
        long long pre_x2, pre_y2;
        for (int k = 0; ; --k) {
          long long x2 = x1 + k * b / gcd(a, b);
          long long y2 = y1 - k * a / gcd(a, b);
          if ( x2 >= 0) {
            pre_x2 = x2;
            pre_y2 = y2;
          } else {
            break;
          }
        }
        printf("%lld %lld\n", pre_x2, pre_y2);
      }
    }
  }
  return 0;
}
