//
// Created by OFShare on 2019-10-01
//

#include <cstdio>
#include <queue>
#include <cstring>

const int maxn = 5 * 5e5 + 5;
const int INF = 1e9;
// dis[i]: 表示从源点到结点i的路径中的边权最小值中的最大值, 即题目所要求的
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
    // 初始化
    dis[start_] = INF;
    // 优先队列是std::less, 而不是std::greater. dis[]大的优先出队列, 因为题目是求所有最小中最大的, 最大的.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::less<std::pair<int, int> > > que;
    que.push({dis[start_], start_});
    while (!que.empty()) {
        int d = que.top().first, u = que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = A[i].next) {
            int v = A[i].v, w = A[i].w;
            // 尝试更新没有标记的结点
            if (!vis[v] && std::min(dis[u], w) > dis[v]) {
                dis[v] = std::min(dis[u], w);
                que.push({dis[v], v});
            }
        }
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while (t--) {
        std::memset(dis, 0, sizeof dis);
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
        Dijkstra(1);
        printf("Scenario #%d:\n", ++kase);
        printf("%d\n\n", dis[n]);

    }
    return 0;
}
