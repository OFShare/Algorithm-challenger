/*
 * Created by OFShare on 2019-11-17
 *
 */

#include <bits/stdc++.h>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
std::map< std::string, int > mp;

// 一维和二维的映射关系:
// (i, j):  i * 4 + j;
//   x   :  (x / 4, x % 4)

int find_zero(std::string str) {
  for (int i = 0; i < 8; ++i) {
    if (str[i] - '0' == 0)
      return i;
  }
}

int bfs(std::string start) {
  std::queue< std::pair<std::string, int> > que;
  std::set<std::string> st;
  que.push({start, 0});
  st.insert(start);

  while (!que.empty()) {
    std::string str = que.front().first;
    int d = que.front().second;
    que.pop();
    // 记录每个状态距离起点的距离
    mp[str] = d;

    int pos1 = find_zero(str);
    int x1 = pos1 / 4, y1 = pos1 % 4;
    for (int i = 0; i < 4; ++i) {
      int xx = x1 + dx[i], yy = y1 + dy[i];
      if (xx >= 0 && xx <= 1 && yy >= 0 && yy <= 3) {
        int pos2 = xx * 4 + yy;
        std::string tmp = str;
        std::swap(tmp[pos1], tmp[pos2]);
        if (st.count(tmp) == 0) {
          que.push({tmp, d + 1});
          st.insert(tmp);
        }
      }
    }
  }
  return -1;
}

int main() {
  // 先遍历整个解空间, 并将结果存在std::map里
  bfs(std::string("01234567"));

  int A[8];
  while (scanf("%d %d %d %d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4], &A[5], &A[6], &A[7]) != EOF ) {
    std::string str;
    for (int i = 0; i < 8; ++i)
      str += A[i] + '0';
    printf("%d\n", mp[str]);
  }
  return 0;
}
