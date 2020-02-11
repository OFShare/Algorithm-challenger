/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-10 21:37:57 PM
 * File Name     : HDU-1213.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <set>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int T, n, m;
int fa[N];
int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
std::set<int> st;

int main() {
  scanf("%d", &T);
  while (T--) {
    st.clear();
    scanf("%d %d", &n, &m);
    // 并查集初始化
    for (int i = 1; i <= n; ++i) 
      fa[i] = i;

    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      int rt1 = find_union(u);
      int rt2 = find_union(v);
      if (rt1 != rt2)
        fa[rt1] = rt2;
    }
    for (int i = 1; i <= n; ++i) {
      int rt = find_union(i);
      st.insert(rt);
    }
    printf("%d\n", st.size());
  }
  return 0;
}
