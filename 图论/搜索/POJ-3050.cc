/*
 * Created by OFShare on 2019-11-25
 *
 */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int mp[6][6];
std::set<std::string> st;

void dfs(int i, int j, int step, std::string str) {
  str += mp[i][j] + '0';
  // 递归的边界
  if (step == 5) {
    st.insert(str);
    return;
  }
  for (int k = 0; k < 4; ++k) {
    int xx = i + dx[k], yy = j + dy[k];
    if (xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5)
      dfs(xx, yy, step + 1, str);
  }
}

int main() {
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= 5; ++j)
      scanf("%d", &mp[i][j]);
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= 5; ++j)
      dfs(i, j, 0, "");
  printf("%d", (int)st.size());
  return 0;
}
