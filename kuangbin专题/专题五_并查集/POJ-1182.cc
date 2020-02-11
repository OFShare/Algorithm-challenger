/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-11 19:26:45 PM
 * File Name     : POJ-1182.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MOD = 3;
const int N = 5e4 + 5;
int n, k;

// 带权并查集, 里面的各种等式都是通过向量加法来思考的, 因为这是一个有向图.
// 对于有向图, 只需要知道相邻两个结点的权值, 就可以推出任意两个结点的权值, 当然前提在同一个联通块里面.
// 对于有向图的权值, 常常维护的就是题目的某种关系.

// 假设x的父亲结点是y, 那么relation[x]就是x指向y这条有向边的权值. 搞清楚这点非常重要, 大多数Blog会把relation[x]当作x指向根结点的权值, 这是不对的.
// find_union函数, 返回的是根结点的编号
int fa[N], relation[N];
int find_union(int x) {
  if (x == fa[x]) return x;
  int rt = find_union(fa[x]);
  relation[x] = (relation[x] + relation[fa[x]] + MOD) % MOD;
  return fa[x] = rt;
}

// 本题x的父亲结点为y, 那么我们定义
// relation[x] = 0, 表示x和y同类(谁也不能吃谁)
// relation[x] = 1, 表示x吃y
// relation[x] = 2, 表示x被y吃

int main() {
  scanf("%d %d", &n, &k);
  // 带权并查集初始化
  for (int i = 1; i <= n; ++i)
    fa[i] = i, relation[i] = 0;
  
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    int d, x, y;
    scanf("%d %d %d", &d, &x, &y);
    if ((d == 2 && x == y) || (x > n || y > n)) {
      ++ans;
      continue;
    }
    // 因为路径被压缩了, x和rt1一定是直接相连的, 同理y和rt2也一定是直接相连的
    int rt1 = find_union(x);
    int rt2 = find_union(y);
    if (rt1 != rt2) {
      fa[rt1] = rt2;
      relation[rt1] = -relation[x] + (d - 1) + relation[y];
      relation[rt1] = (relation[rt1] + MOD) % MOD;
    } else {
      if ((d - 1 + relation[y] + MOD) % MOD!= relation[x])
        ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
