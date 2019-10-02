//
// Created by OFShare on 2019-10-02
//

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 2 * 3e3 + 5;
const int INF = 1e9;
int F, n, m, w, cnt;
int dis[maxn];
int head[maxn];

struct edge {
    int v, w, next;
}A[maxn];

void addEdge(int u, int v, int w) {
    A[++cnt].v = v;
    A[cnt].w = w;
    A[cnt].next = head[u];
    head[u] = cnt;
}

int Bellman_Ford(int start_) {
    // 记录while循环执行的次数, 如果没有负环最多执行(顶点个数 - 1)次, 当是一条链的时候
    int number = 0;
    dis[start_] = 0;
    while (true) {
        bool update = false;
        // 枚举所有边
        for (int u = 1; u <= n; ++u) {
            for (int i = head[u]; i != -1; i = A[i].next) {
                int v = A[i].v, w = A[i].w;
                if (dis[u] < INF && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    update = true;
                }
            }
        }
        if (!update) break;
        ++number;
        if (number > n) break;
    }
    // 没有负环
    if (number <= n -1) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    scanf("%d", &F);
    while (F--) {
        // 初始化
        cnt = 0;
        std::memset(head, -1, sizeof head);
        std::memset(dis, 0x3f3f3f, sizeof dis);
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 1; i <= m; ++i) {
            int u, v, weight;
            scanf("%d %d %d", &u, &v, &weight);
            addEdge(u, v, weight);
            addEdge(v, u, weight);
        }
        for (int i = 1; i <= w; ++i) {
            int u, v, weight;
            scanf("%d %d %d", &u, &v, &weight);
            // 负数
            addEdge(u, v, -weight);
        }
        // 因为图是联通的, 从任意结点出发都可以, 这里选从1出发
        int ret = Bellman_Ford(1);
        if (ret == 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
