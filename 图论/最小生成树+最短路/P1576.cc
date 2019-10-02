//
// Created by OFShare on 2019-10-01
//

#include <bits/stdc++.h>

const int maxn = 5 * 5e5 + 5;
const int INF = 1e9;
// dis[i]: 表示从源点到结点i的最少费用
double dis[maxn];
int n, m, s, cnt;
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
    // 初始化
    dis[start_] = 100.0;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int> >, std::greater<std::pair<double, int> > > que;
    que.push({dis[start_], start_});
    while (!que.empty()) {
        double d = que.top().first;
        int u = que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = A[i].next) {
            int v = A[i].v, w = A[i].w;
            // 尝试更新没有标记的结点
            if (!vis[v] && dis[u] * 1.0 / (1 - w * 0.01) < dis[v]) {
                dis[v] = dis[u] * 1.0 / (1 - w * 0.01);
                que.push({dis[v], v});
            }
        }
    }
}

int main() {
    std::fill(dis, dis + maxn, INF);
    std::memset(head, -1, sizeof head);
    std::memset(vis, 0, sizeof vis);
    cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int start_, end_;
    scanf("%d %d", &start_, &end_);
    Dijkstra(start_);
    printf("%.8lf\n", dis[end_]);
    return 0;
}
