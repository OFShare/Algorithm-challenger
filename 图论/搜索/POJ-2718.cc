/*
 * Created by OFShare on 2019-11-18
 *
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

const int maxn = 30 + 5;
int kase;

// 输入的元素个数
int n;

// 存储进行排列的元素
std::vector<int> vec;

// 全局ans
int ans = 0x3f3f3f;

int pow_(int cnt) {
  int ret = 1;
  for (int i = 0; i < cnt; ++i) {
    ret *= 10;
  }
  return ret;
}

int abs_(int x) {
  if (x > 0)
    return x;
  else
    return -1 * x;
}

int main() {
#ifdef Acui
  freopen("datain.txt", "r", stdin);
  freopen("dataout_my.txt", "w", stdout);
#endif
  char tmp[maxn];
  std::fgets(tmp, maxn - 2, stdin);
  std::sscanf(tmp, "%d", &kase);

  while (kase--) {
    vec.clear();
    ans = 0x3f3f3f;

    std::fgets(tmp, maxn - 2, stdin);
    int len = std::strlen(tmp);
    for (int i = 0; i < len; i+=2) {
      vec.push_back(tmp[i] - '0');
    }
    n = vec.size();
    std::sort(vec.begin(), vec.end());

    do {
      // 分成两半, 含前导0, 直接返回, 注意0可以单独存在
      if (n >= 3 && (vec[n - 1] == 0 || vec[n / 2 - 1] == 0))
        continue;
      int sum1 = 0, cnt = 0;
      for (int i = 0; i < n / 2; ++i) {
        sum1 += vec[i] * pow_(cnt++);
      }
      int sum2 = 0; cnt = 0;
      for (int i = n / 2; i < n; ++i) {
        sum2 += vec[i] * pow_(cnt++);
      }
      int difference = abs_(sum1 - sum2);
      ans = std::min(ans, difference);
    } while(std::next_permutation(vec.begin(), vec.end()));
    printf("%d\n", ans);
  }
  return 0;
}
