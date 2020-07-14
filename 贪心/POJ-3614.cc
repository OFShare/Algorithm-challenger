/**
 * Author: OFShare@outlook.com
 *
 * Date: 2020-01-14 Tuesday 22:20 PM
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

int C, L;

const int maxn = 2500 + 5;
bool vis[maxn];

struct node {
  int minSPF, maxSPF;
  bool operator< (const node &rhs) const {
    if (minSPF == rhs.minSPF)
      return maxSPF < rhs.maxSPF;
    return minSPF < rhs.minSPF;
  }
}cows[maxn];

struct node2 {
  int SPF, number;
  bool operator< (const node2 &rhs) const {
    return SPF < rhs.SPF;
  }
}lotion[maxn];

int main() {
  scanf("%d %d", &C, &L);
  for (int i = 1; i <= C; ++i) {
    scanf("%d %d", &cows[i].minSPF, &cows[i].maxSPF);
  }
  std::sort(cows + 1, cows + 1 + C);

  for (int i = 1; i <= L; ++i) {
    scanf("%d %d", &lotion[i].SPF, &lotion[i].number);
  }
  std::sort(lotion + 1, lotion + 1 + L);

  int cnt = 0;
  // (maxSPF, j)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;

  for (int i = 1; i <= L; ++i) {
    while (!que.empty())
      que.pop();
    for (int j = 1; j <= C; ++j) {
      if (!vis[j] && lotion[i].SPF >= cows[j].minSPF && lotion[i].SPF <= cows[j].maxSPF)
        que.push(std::make_pair(cows[j].maxSPF, j));
    }
    while (!que.empty() && lotion[i].number) {
      ++cnt;
      int index = que.top().second;
      que.pop();

      vis[index] = true;
      lotion[i].number--;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
