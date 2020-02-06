/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-05 18:25:20 PM
 * File Name     : POJ-3087.cc
 */

#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#include <string>

void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

int T, C;
std::string s1, s2, target;
std::set<std::string> st;

struct node {
  std::string s;
  int step;
};
int bfs(node s) {
  st.clear();
  std::queue<node> que;
  que.push(s);

  while (!que.empty()) {
    node p = que.front();
    que.pop();

    std::string s = p.s, tmp;
    int step = p.step;
    // 找到了
    if (s == target) {
      return step;
    }
    st.insert(s);

    // 转移即洗牌
    for (int i = 0; i < C; ++i) {
      tmp += s[i + C];
      tmp += s[i];
    }
    if (st.count(tmp) == 0) {
      st.insert(tmp);
      que.push({tmp, step + 1});
    }
  }
  return -1;
}
int main() {
  std::cin >> T;
  for (int kase = 1; kase <= T; ++kase) {
    std::cin >> C;
    std::cin >> s1 >> s2 >> target;
    std::cout << kase << " " << bfs({s1 + s2, 0}) << std::endl; 
  }
  return 0;
}
