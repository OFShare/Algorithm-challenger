//
// Created by OFShare on 2019-10-01
//

#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 2e2 + 5;
int n;
// dis[i][j]: 表示只使用1~k个点, 从i结点到j结点的最小必要跳跃距离, 第一维k被压缩掉了
double dis[maxn][maxn];

struct point {
    double x, y;
}A[maxn];

double l2distance(int i, int j) {
    double tmp = (A[i].x - A[j].x) * (A[i].x - A[j].x) + (A[i].y - A[j].y) * (A[i].y - A[j].y);
    return std::sqrt(tmp);
}

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 更新
                if (dis[i][k] < dis[i][j] && dis[k][j] < dis[i][j]) {
                    dis[i][j] = std::min(dis[i][j], std::max(dis[i][k], dis[k][j]));
                }
            }
        }
    }
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &A[i].x, &A[i].y);
        }
        // 初始化
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = l2distance(i, j);
            }
        }
        Floyd();
        printf("Scenario #%d\n", ++kase);
        printf("Frog Distance = %.3lf\n\n", dis[1][2]);
    }
    return 0;
}
