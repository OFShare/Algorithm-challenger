//
// Created by OFShare on 2019-09-28
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

const int maxn = 2 * 2e6 + 5;
const int mod = 100003;
// dis[i]: 表示从源点到结点i的最短距离
int n, m, s, dis[maxn], cnt;
// dis2[i]: 表示从源点到结点i的次短距离
int dis2[maxn];
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
    // 队列里, 最短路, 次短路都入队列里
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
    que.push({dis[start_], start_});
    while (!que.empty()) {
        int d = que.top().first, u = que.top().second;
        que.pop();
        // if (vis[u]) continue;
        // vis[u] = true;
        for (int i = head[u]; i != -1; i = A[i].next) {
            int v = A[i].v, w = A[i].w;
            // 尝试更新最短路结点
            if (d + w <= dis[v]) {
                // 原来的最短路就变成次短路了
                dis2[v] = dis[v];
                dis[v] = d + w;
                que.push({dis[v], v});
                que.push({dis2[v], v});
                continue;
            }
            // 尝试次短路结点
            if (d + w > dis[v] && d + w < dis2[v]) {
                dis2[v] = d + w;
                que.push({dis2[v], v});
            }
        }
    }
}

int main() {
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(dis2, 0x3f3f3f, sizeof dis2);
    std::memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    Dijkstra(1);
    printf("%d\n", dis2[n]);
    return 0;
}
