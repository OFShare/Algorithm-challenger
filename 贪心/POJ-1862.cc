/*
 * Created by OFShare on 2019-12-10
 *
 */

#include <cstdio>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

priority_queue<double> s;

int main() {
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    double tmp;
    scanf("%lf", &tmp);
    s.push(tmp);
  }
  while(--n) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s. pop();
    s.push(2 * sqrt(a * b));
  }
  printf("%.3f\n", s.top());
  return 0;
}
