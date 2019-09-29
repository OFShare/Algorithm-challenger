//
// Created by OFShare on 2019-09-28
//

#include <bits/stdc++.h>

const int maxn = 2 * 2e6 + 5;
const int INF = 1e9;
// dis[i]: 表示从源点到结点i的最短距离
long long n, m, s, dis[maxn], cnt;
// vis[i]: 表示结点i是否已被标记(访问)过
bool vis[maxn];
int head[maxn];
struct edge {
    long long v, w, next;
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

// 存边
struct node {
    long long u, v, w;
};
std::vector<node> vec;

int main() {
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(head, -1, sizeof head);
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; ++i) {
        long long u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        addEdge(u, v, w);
        vec.push_back({u, v, w});
    }
    Dijkstra(1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dis[i];
    }
    // 反向边建图
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(vis, 0, sizeof vis);
    std::memset(head, -1, sizeof head);
    cnt = 0;
    for (int i = 0; i < vec.size(); ++i) {
        long long u = vec[i].u, v = vec[i].v, w = vec[i].w;
        addEdge(v, u, w);
    }
    Dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        ans += dis[i];
    }
    printf("%lld\n", ans);
    return 0;
}
