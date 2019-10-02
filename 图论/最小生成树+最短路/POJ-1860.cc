//
// Created by OFShare on 2019-10-01
//

#include <cstdio>
#include <cstring>

const int maxn = 2 * 3e5 + 5;
const int INF = 1e9;
int t, n, m, cnt, start_;
double init_money;
// dis[i]: 表示从源点到结点i的最大能获得的资本
double dis[maxn];
int head[maxn];

// 边
struct edge {
    int v;
    double exchange_rate, cut;
    int next;
}A[maxn];

void addEdge(int u, int v, double exchange_rate, double cut) {
    A[++cnt].v = v;
    A[cnt].exchange_rate = exchange_rate;
    A[cnt].cut = cut;
    A[cnt].next = head[u];
    head[u] = cnt;
}

int Bellman_Ford(int start_) {
    // 记录while循环执行的次数, 如果没有正权回路最多执行(顶点个数 - 1)次, 当是一条链的时候
    int number = 0;
    dis[start_] = init_money;
    while (true) {
        bool update = false;
        // 枚举所有边
        for (int u = 1; u <= n; ++u) {
            for (int i = head[u]; i != -1; i = A[i].next) {
                int v = A[i].v;
                double exchange_rate = A[i].exchange_rate;
                double cut = A[i].cut;
                //printf("%d---->%d, exchange_rate: %lf, cut: %lf\n", u, v, exchange_rate, cut);
                // 求的是最大能获得的资本, 大于才更新
                if ((dis[u]- cut) * exchange_rate > dis[v]) {
                    dis[v] = (dis[u]- cut) * exchange_rate;
                    update = true;
                }
            }
        }
        if (!update) break;
        ++number;
        if (number > n) break;
    }
    // 没有
    if (number <= n -1) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    // 初始化
    cnt = 0;
    std::memset(head, -1, sizeof head);
    std::memset(dis, 0, sizeof dis);
    scanf("%d %d %d %lf", &n, &m, &start_, &init_money);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        double exchange_rate1, exchange_rate2, cut1, cut2;
        scanf("%d %d %lf %lf %lf %lf", &u, &v, &exchange_rate1, &cut1, &exchange_rate2, &cut2);
        addEdge(u, v, exchange_rate1, cut1);
        addEdge(v, u, exchange_rate2, cut2);
    }
    int ret = Bellman_Ford(start_);
    if (ret == 0) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
