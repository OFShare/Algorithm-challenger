//
// Created by OFShare on 2019-10-01
//

#include <cstdio>
#include <queue>
#include <cstring>

const int maxn = 2 * 2e6 + 5;
const int INF = 1e9;
// dis[i]: 表示从源点到结点i的最短距离
long long t, n, s, dis[maxn], cnt;
// vis[i]: 表示结点i是否已被标记(访问)过
bool vis[maxn];
long long head[maxn];
struct edge {
    long long v, w, next;
}A[maxn];

void addEdge(long long u, long long v, long long w) {
    A[++cnt].v = v;
    A[cnt].w = w;
    A[cnt].next = head[u];
    head[u] = cnt;
}

void Dijkstra(long long start_) {
    dis[start_] = 0;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long> >, std::greater<std::pair<long long, long long> > > que;
    que.push({dis[start_], start_});
    while (!que.empty()) {
        long long d = que.top().first, u = que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = A[i].next) {
            long long v = A[i].v, w = A[i].w;
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
    scanf("%lld %lld", &t, &n);
    for (int i = 1; i <= t; ++i) {
        long long u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    Dijkstra(n);
    printf("%lld\n", dis[1]);
    return 0;
}
