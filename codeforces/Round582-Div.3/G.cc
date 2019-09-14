//
// Created by OFShare on 2019-09-11
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
int n, m;
struct node {
    int u, v, value;
    bool operator<(const node &rhs) const {
        return value < rhs.value;
    }
}A[maxn];

int query[maxn];
int fa[maxn];
int find_union(int x) {
    return fa[x] == x? x: (fa[x] = find_union(fa[x]));
}
// block_sum[i]记录以i为根的并查集联通快的元素个数
long long block_sum[maxn];
// ans[i]记录不超过权重为i的简单路径数量
long long ans[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n-1; ++i) {
        scanf("%d %d %d", &A[i].u, &A[i].v, &A[i].value);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &query[i]);
    }

    // 并查集初始化
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
        block_sum[i] = 1;
    }
    // 边的权重按从小到大考虑
    std::sort(A+1, A+1+n-1);
    for(int i = 1; i <= n-1; ++i) {
        int x = find_union(A[i].u);
        int y = find_union(A[i].v);
        // 合并, 因为是树，所以x和y肯定不等，树是不会构成环的
        assert(x != y);
        fa[x] = y;
        // 是+=, 不是=, 要考虑边的权重相等的情况，也会有贡献
        ans[A[i].value] += block_sum[x] * block_sum[y];
        block_sum[y] = block_sum[x] + block_sum[y];
    }
    // 前缀和
    for(int i = 1; i <= maxn-5; ++i) {
        ans[i] += ans[i-1];
    }
    for(int i = 1; i <= m; ++i) {
        printf("%lld ", ans[query[i]]);
    }
    return 0;
}
