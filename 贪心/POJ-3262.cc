/*
 * Created by OFShare on 2019-12-10
 *
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

pii c[100010];

bool cmp(const pii a, const pii b) {
  return a.first * b.second < a.second * b.first;
}

int main() {
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d%d", &c[i].first, &c[i].second);
  }
  sort(c, c + n, cmp);
  long long ans = 0, t = 0;
  for(i = 0; i < n; ++i) {
    ans += t * c[i].second;
    t += 2 * c[i].first;
  }
  printf("%lld\n", ans);
  return 0;
}
