//
// Created by OFShare on 2019-09-28
//

#include <bits/stdc++.h>

const int maxn = 2 * 2e6 + 5;
const int INF = 1e9;
// dis[i]: 表示从源点到结点i的最短距离
int n, m, s, dis[maxn], cnt;
// vis[i]: 表示结点i是否已被标记(访问)过
bool vis[maxn];
int head[maxn];
// ans[i]: 表示从源点到结点i最短路的条数
int ans[maxn];
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
    ans[start_] = 1;
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
                ans[v] = ans[u];
            } else if (dis[u] + w == dis[v]) {
                ans[v] = (ans[v] + ans[u]);
            }
        }
    }
}


// 用std::set判断是否有重边, 超时, 直接用is_exist数组判断即可
bool is_exist[2005][2005][15];
struct node {
    int u, v, w;
    bool operator<(const node &lhs) const {
        return std::vector<int>{u, v, w} < std::vector<int>{lhs.u, lhs.v, lhs.w};
    }
};
std::set<node> st;

int main() {
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout2.txt", "w", stdout);
#endif

    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // 去除重复的边
        // if (st.count({u, v, w}) == 0) {
        //     st.insert({u, v, w});
        //     addEdge(u, v, w);
        // }
        if (!is_exist[u][v][w]) {
            is_exist[u][v][w] = true;
            addEdge(u, v, w);
        }
    }
    Dijkstra(1);
    if (dis[n] < INF)
        printf("%d %d\n",dis[n], ans[n]);
    else
        printf("No answer\n");
    return 0;
}
