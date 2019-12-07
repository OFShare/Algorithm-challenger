/*
 * Created by OFShare on 2019-12-07
 *
 */

#include <bits/stdc++.h>

int k;
int A[6];

int func(int start) {
  int sum = 0;
  int cnt = 2;
  for (int i = start; i <= start + 3; ++i) {
    sum += A[i] * std::pow(10, cnt--);
  }
  return sum;
}

int main() {
  scanf("%d", &k);

  bool updated = false;
  for (int num = 10000; num <= 30000; ++num) {
    int tmp = num;
    for (int i = 5; i >= 1; --i) {
      A[i] = tmp % 10;
      tmp /= 10;
    }
    int sub1 = func(1);
    int sub2 = func(2);
    int sub3 = func(3);
    if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k ==0) {
      printf("%d\n", num);
      updated = true;
    }
  }
  if (!updated)
    printf("No\n");
  return 0;
}
