/*
 * Created by OFShare on 2019-12-23
 *
 */

#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>

int X;

std::map<int, int> mp;
void factor(int n) {
  for (int i = 2; 1L * i * i <= 1L * n; ++i) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n > 1)
    mp[n]++;
}

long long factorial(int n) {
  if (n == 1 || n == 0)
    return 1;
  return 1L * n * factorial(n - 1);
}

int combination(int n) {
  long long result = factorial(n);
  for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    result = result / factorial(it -> second);
  }
  return result;
}

int main() {
  while (scanf("%d", &X) != EOF) {
    mp.clear();
    factor(X);
    int number = 0;
    for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
      number += it -> second;
    }
    printf("%d %d\n", number, combination(number));
  }
  return 0;
}
