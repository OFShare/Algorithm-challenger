/*
 * Created by OFShare on 2020-01-28, 春节期间
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n;

namespace AC {
// 默认初始化为0
int tr[N][26], tot;
int e[N], fail[N];

// 构造字典树
void insert(char *s) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];
  }
  e[u]++;
}

// 构造trie图, 因为是trie图, 而不是trie树.
// 如果某个节点到根节点构成环, 即有多条路径可以从当前节点向上走回到根节点,
// 那么有效的路径还是最开始构造trie树的那条路径, 其它的路径只是优化构造fail指针的效率.
// 用当前节点u去更新u的子节点
// fail指针指向当前串的最长后缀, 这个后缀也是某个串的前缀, 和KMP的next指针相似
std::queue<int> q;
void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < 26; i++) {
      if (tr[u][i])
        fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
      else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}

// 当查询到t[i]时, u节点表示1~i的子串最长的后缀
int query(char *t) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    for (int j = u; j && e[j] != -1; j = fail[j]) {
      res += e[j], e[j] = -1;
    }
  }
  return res;
}
}  // namespace AC

char s[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s + 1), AC::insert(s);
  scanf("%s", s + 1);
  AC::build();
  printf("%d", AC::query(s));
  return 0;
}
