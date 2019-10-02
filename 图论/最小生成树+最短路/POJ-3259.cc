//
// Created by OFShare on 2019-10-02
//

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int maxn = 5e2 + 5;
int F, n, m, w;
// dis[i][j]: 从结点i走到结点j的最短距离
int dis[maxn][maxn];

// 快读
inline int read() {
    int X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}

bool Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                //dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
            if (dis[i][i] < 0) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    F = read();
    while (F--) {
        n = read(); m = read(); w = read();
        // 初始化
        std::memset(dis, 0x3f3f3f, sizeof dis);
        for (int i = 1; i <= n; ++i) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, weight;
            u = read(); v = read(); weight = read();
            // 因为两个结点可能由一个以上的路径来连接
            // 比如1--->3, 有边权5, 有边权8, 那么应该保留边权5
            //dis[u][v] = std::min(dis[u][v], weight);
            //dis[v][u] = std::min(dis[v][u], weight);
            if (weight < dis[u][v])
                dis[u][v] = dis[v][u] = weight;
        }
        for (int i = 1; i <= w; ++i) {
            int u, v, weight;
            u = read(); v = read(); weight = read();
            // 用负数表示
            dis[u][v] = -weight;
        }
        bool flag = Floyd();
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
