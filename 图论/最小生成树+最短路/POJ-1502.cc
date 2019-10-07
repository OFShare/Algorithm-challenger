//
// Created by OFShare on 2019-10-03
//

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

const int maxn = 2 * 2e3 + 5;
const int mod = 100003;
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

int convert(char *str, int len) {
    int sum = 0;
    int multi = 1;
    for (int i = len; i >= 1; --i) {
        if (i == len) {
            sum += (str[i] - '0');
            continue;
        } else {
            multi *= 10;
            sum += (str[i] - '0') * multi;
        }
    }
    return sum;
}

int main() {
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(head, -1, sizeof head);
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            char tmp[100];
            scanf("%s", tmp + 1);
            if (tmp[1] != 'x') {
                int w = convert(tmp, strlen(tmp + 1));
                addEdge(i, j, w);
                addEdge(j, i, w);
            }
        }
    }
    Dijkstra(1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, dis[i]);
    }
    printf("%d\n", ans);
    return 0;
}
