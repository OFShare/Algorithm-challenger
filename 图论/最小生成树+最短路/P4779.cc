//
// Created by OFShare on 2019-09-26
//

#include <bits/stdc++.h>

const int maxn = 2 * 2e5 + 5;
// dis[i]: 表示从源点到结点i的最短距离
int n, m, s, dis[maxn], cnt;
// vis[i]: 表示结点i是否已被标记(访问)过
bool vis[maxn];
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

void Dijkstra(int start_) {
    dis[start_] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
    que.push({dis[start_], start_});
    while (!que.empty()) {
        int d = que.top().first, u = que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = A[i].next) {
            int v = A[i].v, w = A[i].w;
            // 尝试更新没有标记的结点
            if (!vis[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                que.push({dis[v], v});
            }
        }
    }
}

int main() {
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(head, -1, sizeof head);
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    Dijkstra(s);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}
