/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 10:30:28 AM
 * File Name     : HDU-2222.cc
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

const int N = 2e6 + 6;
int t, n;
char s[N];
char text[N];

// 注意读入重复的串
// AC自动机, 读入下标是从1开始的, 不过传参还是s, 而不是s + 1
// scanf("%s", s + 1), AC::insert(s, i);
namespace AC {

const int N = 1e6 + 6;
int tr[N][26], tot;
int fail[N];
// idy[i]: 记录每个模式串在Trie图上的终止节点
// count[i]: 记录匹配次数
int idy[N], count[N];

void init() {
  std::memset(tr, 0, sizeof tr);
  std::memset(idy, 0, sizeof idy);
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
  idy[id] = u;
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

// 当查询到t[i]时, u节点到根节点路径上的边构成的字符串, 表示1~i的子串最长的后缀
int query(const char *t) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    count[u]++; 
  }
  return res;
}

// 利用fail指针和count数组建立fail树
int edge_number = 0, head[N];

void init2() {
  edge_number = 0;
  std::memset(head, -1, sizeof head);
}

struct Edge {
  int w, v, next;
}edges[N];

void add_edge(int u, int v, int w) {
  ++edge_number;
  edges[edge_number].w = w;
  edges[edge_number].v = v;
  edges[edge_number].next = head[u];
  head[u] = edge_number;
}

// fail[x]是x的父节点, fail[x] ----> x
// 统计子树和
int dfs(int u) {
  for (int i = head[u]; i != -1; i = edges[i].next) {
    int v = edges[i].v;
    count[u] += dfs(v); 
  }
  return count[u];
}

void build_fail_tree() {
  init2();
  for (int i = 1; i <= tot; ++i) {
    add_edge(fail[i], i, 0);
  }
  dfs(0);
}

}  // namespace AC

int main() {
  scanf("%d", &t);
  while (t--) {
    AC::init();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
      scanf("%s", s + 1), AC::insert(s, i);
    scanf("%s", text + 1);

    AC::build();
    AC::query(text);
    AC::build_fail_tree();

    int ans = 0;
    for (int i = 1; i <= n; ++i) 
      if (AC::count[AC::idy[i]])
        ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
