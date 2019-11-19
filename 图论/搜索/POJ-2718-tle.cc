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

// 是否访问过
bool vis[maxn];

// 存储进行排列的元素
std::vector<int> vec;

// dfs时, 当前在栈里的元素
std::vector<int> vec2;

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

void dfs(int x) {
  vis[x] = true;
  vec2.push_back(x);
  // 递归的边界, 找到一个全排列
  if (vec2.size() == n) {
    // 分成两半, 含前导0, 直接返回, 注意0可以单独存在
    if (n >= 3 && (vec[n - 1] == 0 || vec[n / 2 - 1] == 0))
      return;
    bool is_ok1 = true, is_ok2 = true;
    int sum1 = 0, cnt = 0;
    for (int i = 0; i < n / 2; ++i) {
      sum1 += vec2[i] * pow_(cnt++);
    }
    int sum2 = 0; cnt = 0;
    for (int i = n / 2; i < n; ++i) {
      sum2 += vec2[i] * pow_(cnt++);
    }
    int difference = abs_(sum1 - sum2);
    ans = std::min(ans, difference);
    return ;
  }
  for (int i = 0; i < vec.size(); ++i) {
    int adj = vec[i];
    if (!vis[adj]) {
      dfs(adj);
      // 回溯
      vis[adj] = false;
      vec2.pop_back();
    }
  }
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
    vec2.clear();
    ans = 0x3f3f3f;
    std::memset(vis, 0, sizeof vis);

    std::fgets(tmp, maxn - 2, stdin);
    int len = std::strlen(tmp);
    for (int i = 0; i < len; i+=2) {
      vec.push_back(tmp[i] - '0');
    }
    n = vec.size();
    // 打表预先算出来的答案
    if (n == 10) {
      printf("247\n");
      continue;
    }
    // 从每个点出发, 搜索全排列
    for (int i = 0; i < n; ++i) {
      std::memset(vis, 0, sizeof vis);
      vec2.clear();
      dfs(vec[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
