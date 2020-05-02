/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-29 15:10:43 PM
 * File Name     : P1160.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n;
// 用fa 和 son 数组维护节点i的父亲节点和儿子节点
int fa[N], son[N];

int main() {
  scanf("%d", &n);
  // 初始化, 有点类似并查集
  for (int i = 1; i <= n; ++i)
    fa[i] = i, son[i] = i;

  for (int i = 2; i <= n; ++i) {
    int k, p;
    scanf("%d %d", &k, &p);
    if (p == 0) {
      if (son[k] == k) {
        fa[i] = k;
        son[k] = i;
      } else {
        fa[son[k]] = i;
        son[i] = son[k];
        fa[i] = k;
        son[k] = i;
      }
    } else if (p == 1) {
      if (fa[k] == k) {
        fa[k] = i;
        son[i] = k;
      } else {
        fa[i] = fa[k];
        son[fa[k]] = i; 
        son[i] = k;
        fa[k] = i;
      }
    }
  }
  // 找到双向链表的头
  int head;
  for (int i = 1; i <= n; ++i) {
    if (son[i] == i) {
      head = i;
      break;
    }
  }

  std::vector<int> ans;
  for (int i = head; ;i = fa[i]) {
    ans.push_back(i);
    if (fa[i] == i) break;
  }
  
  std::set<int> st;
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    st.insert(x); 
  }
  for (int i = 0; i < ans.size(); ++i) {
    if (st.count(ans[i])) continue;
    else printf("%d ", ans[i]);
  }
  return 0;
}
