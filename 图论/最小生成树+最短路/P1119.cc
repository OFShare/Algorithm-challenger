//
// Created by OFShare on 2019-09-28
//

#include <bits/stdc++.h>

const int maxn = 2 * 2e2 + 5;
const int INF = 1e9;
int n, m, q;
int t[maxn], dis[maxn][maxn];

void floyd(int k) {
    // printf("###k: %d", k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dis[i][k] < INF && dis[j][k] < INF)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    std::memset(dis, 0x3f3f3f, sizeof dis);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        ++u, ++v;
        dis[u][v] = w;
        dis[v][u] = w;
    }
    scanf("%d", &q);
    // 记录已被重新修建完成的结点
    int current = 1;
    for (int i = 1; i <= q; ++i) {
        int x_, y_, t_;
        scanf("%d %d %d", &x_, &y_, &t_);
        ++x_, ++y_;
        while (current <= n && t[current] <= t_) {
            floyd(current);
            ++current;
        }
        // 如果结点x_, y_重新修建完成时间大于t_, 则肯定不能到达
        if (t[x_] > t_ || t[y_] > t_) {
            printf("-1\n");
            continue;
        }
        if (dis[x_][y_] < INF)
            printf("%d\n", dis[x_][y_]);
        else
            printf("-1\n");
    }
    return 0;
}
