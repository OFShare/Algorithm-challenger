/*
 * Created by OFShare on 2019-12-28
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e7 + 5;
long long n;
std::map<long long, long long> mp;

// 唯一分解定理
void decompose(long long n) {
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n > 1) mp[n]++;
}

int main() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int kase = 0;
  while (scanf("%lld", &n) && n) {
    mp.clear();
    decompose(n);
    if (mp.size() <= 1) {
      printf("Case %d: %lld\n", ++kase, 1 + n);
      continue;
    }
    long long ans = 0;
    for (auto &ch: mp) {
      ans += std::pow(ch.first, ch.second);
    }
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}
