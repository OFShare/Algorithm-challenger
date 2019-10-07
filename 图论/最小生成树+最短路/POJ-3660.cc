//
// Created by OFShare on 2019-10-03
//

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 100 + 5;
int n, m;
// dis[i][j]: 表示结点i和结点j能否直接或者间接的联通, 即确定题目所说的谁的能力更强
int dis[maxn][maxn];

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 更新
                dis[i][j] = (dis[i][j] | (dis[i][k] && dis[k][j]));
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        // v -- > u 为1, 即建边是指向胜者的
        dis[v][u] = 1;
    }
    Floyd();
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int j = 1; j <= n; ++j) {
            if (i != j && !(dis[i][j] == 1 || dis[j][i] == 1)) {
                flag = false;
            }
        }
        if (flag)
            ++sum;
    }
    printf("%d\n", sum);
    return 0;
}
