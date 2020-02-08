/**
 * Author: OFShare@outlook.com
 *
 * Date: 2020-01-13 Monday 23:50 PM
 */

#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

const int maxn = 5e3 + 5;
int t;
int n;
bool vis[maxn];

struct node {
  int length, weight;
  bool operator< (const node &rhs) const {
    if (length == rhs.length)
      return weight < rhs.weight;
    return length < rhs.length;
  }
}A[maxn];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &A[i].length, &A[i].weight);
    }
    std::sort(A + 1, A + 1 + n);

    std::memset(vis, 0, sizeof vis);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        ++cnt;
        int pre = A[i].weight;

        for (int j = i + 1; j <= n; ++j) {
          if (A[j].weight >= pre && !vis[j]) {
            vis[j] = true;
            pre = A[j].weight;
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
