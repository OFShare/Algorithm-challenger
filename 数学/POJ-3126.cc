/*
 * Created by OFShare on 2019-12-22
 *
 */

#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

// 自定义std::to_string, std::pow
namespace std {
  std::string to_string(int x) {
    std::string str;
    while (x) {
      str += x % 10 + '0';
      x /= 10;
    }
    std::reverse(str.begin(), str.end());
    return str;
  }

  int pow(int base, int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
      result *= base;
    }
    return result;
  }
}

const int maxn = 1e5;
bool is_prime[maxn];

int T;
bool check_prime(int n) {
  for (int i = 2; 1L * i * i <= 1L * n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void find_prime() {
  for (int i = 1000; i <= 9999; ++i) {
    if (check_prime(i))
      is_prime[i] = true;
  }
}

int string_2_int(std::string x) {
  int sum = 0;
  int cnt = 0;
  for (int i = x.size() - 1; i >= 0; --i) {
    sum += (x[i] - '0') * std::pow(10, cnt++);
  }
  return sum;
}

int dis[maxn];
bool vis[maxn];
int bfs(int startt, int endd) {
  std::memset(dis, 0x3f3f3f, sizeof dis);
  dis[startt] = 0;
  std::queue<int> que;
  que.push(startt);

  while(!que.empty()) {
    int x = que.front();
    que.pop();
    if (x == endd)
      return dis[x];
    if (vis[x])
      continue;
    vis[x] = true;

    std::string str = std::to_string(x);
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j <= 9; ++j) {
        if (i == 0 && j == 0)
          continue;
        std::string middle = str;
        if (middle[i] - '0' != j) {
          middle[i] = j + '0';
          int nxt = string_2_int(middle);
          if (!vis[nxt] && is_prime[nxt]) {
            // 可能有好几个相同的数字都在队列里, 但他们都没有被标记过, 所以取相同数字dis最小的
            dis[nxt] = std::min(dis[nxt], dis[x] + 1);
            que.push(nxt);
            //printf("\n#### x -> nxt: %d -> %d\n", x, nxt);
            //printf("#### dis[nxt]: %d\n", dis[nxt]);
          }
        }
      }
    }
  }

  // impossible
  return -1;
}

int main() {
  find_prime();
  scanf("%d", &T);
  while (T--) {
    std::memset(vis, 0, sizeof vis);
    int start, end;
    scanf("%d %d", &start, &end);
    int d = bfs(start, end);
    if (d == -1)
      printf("Impossible\n");
    else
      printf("%d\n", d);
  }
  return 0;
}
