//
// Created by OFShare 2019-09-25
//

#include <bits/stdc++.h>

const int maxn = 4e5 + 5;
int n, m;
struct edge {
    int u, v, w;
    bool operator<(const edge &rhs) const {
        return w < rhs.w;
    }
}A[maxn];

// 并查集
int fa[maxn];
int find_union(int x) {
    return fa[x] == x? x: fa[x] = find_union(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &A[i].u, &A[i].v, &A[i].w);
    }
    // 初始化并查集
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    std::sort(A + 1, A + 1 + m);
    int number_ = 0, sum_ = 0;
    for (int i = 1; i <= m; ++i) {
        int u = A[i].u, v = A[i].v, w = A[i].w;
        u = find_union(u);
        v = find_union(v);
        if (u != v) {
            number_ += 1;
            sum_ += w;
            fa[u] = v;
        }
        // 已经找到n - 1条边了
        if (number_ == n -1)
            break;
    }
    if (number_ == n -1)
        printf("%d\n", sum_);
    else
        printf("orz\n");
    return 0;
}
