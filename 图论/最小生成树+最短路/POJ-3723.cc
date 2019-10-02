//
// Created by OFShare on 2019-10-01
//

#include <cstdio>
#include <vector>
#include <algorithm>

const int maxn = 2 * 5e4 + 5;
int t, n, m, r;

// 并查集
int fa[maxn];
int find_union(int x) {
    return x == fa[x]? x: fa[x] = find_union(fa[x]);
}

// 边
struct node {
    int u, v, w;
    bool operator<(const node &rhs) const {
        return w > rhs.w;
    }
};
std::vector<node> vec;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &r);
        // 初始化
        vec.clear();
        for (int i = 1; i <= n + m; ++i) {
            fa[i] = i;
        }
        for (int i = 1; i <= r; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            // 编号从1开始
            ++u, ++v;
            // 处理男兵的编号, 使得男女的编号不同
            v += n;
            vec.push_back({u,  v, w});
            vec.push_back({v,  u, w});
        }
        // 按边权从大到小排序
        std::sort(vec.begin(), vec.end());
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int u = vec[i].u, v = vec[i].v, w = vec[i].w;
            int x = find_union(u), y = find_union(v);
            // 不属于同一个联通块
            if (x != y) {
                sum += w;
                fa[x] = y;
            }
        }
        printf("%d\n", 10000 * (n + m) - sum);
    }
    return 0;
}
