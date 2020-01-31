/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-01-31 12:33:43 PM
 * File Name     : P3796.cc
 */

#include <bits/stdc++.h>

const int N = 1e6 + 6;
int n;
int g_in[155];
char s[155][75];
char text[N];

namespace AC {

const int N = 1e6 + 6;
int tr[N][26], tot;
int fail[N];
int ids[N], count[N];

void init() {
  std::memset(tr, 0, sizeof tr);
  std::memset(ids, 0, sizeof ids);
  std::memset(fail, 0, sizeof fail);
  std::memset(count, 0, sizeof count);
  tot = 0;
}

// 构造字典树
void insert(const char *s, const int id) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];
  }
  ids[u] = id;
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
int query(const char *t) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    for (int j = u; j; j = fail[j]) {
      count[j]++; 
    }
  }
  
  for (int i = 1; i <= tot; ++i) {
    if (ids[i]) {
      res = std::max(res, count[i]);
      g_in[ids[i]] = count[i];
    }
  }
  return res;
}
}  // namespace AC


int main() {
  while (scanf("%d", &n) && n) {
    AC::init();
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1), AC::insert(s[i], i);
    scanf("%s", text + 1);
    AC::build();

    int ret = AC::query(text);
    printf("%d\n", ret);
    for (int i = 1; i <= n; ++i) {
      if (g_in[i] == ret) 
        printf("%s\n", s[i] + 1);
    }
  }
  return 0;
}
