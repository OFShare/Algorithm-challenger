//
// created by OFShare on 2019-08-17
//

#include <bits/stdc++.h>

const int maxn = 500 + 5;
int n;
double x[maxn], y[maxn], dist[maxn][maxn], d[maxn][maxn];

// dfs(i,j):表示两人同时从第一个点出发，第一个人走到i这个点，第二人走到j这个点，
// 且1到std::max(i,j)都被两人中的一个人走过且只被一个人走过，从这个状态出发的最短距离。
double dfs(int i, int j){
    // 记忆化,原先被访问过的话，就直接返回
    if(d[i][j] != -1)
        return d[i][j];
    // 如果其中一个人走到终点，另外一个人就直接走到终点即可
    if(i == n){
        return d[i][j] = dist[j][n];
    }
    if(j == n){
        return d[i][j] = dist[i][n];
    }
    // 两人可以走的下一个点,状态转移为第1个人走到下一个点，或者第2个人走到下一个点
    int next_node = std::max(i,j) + 1;
    return d[i][j] = std::min(dfs(next_node,j) + dist[i][next_node], dfs(i,next_node) + dist[j][next_node]);
}

int main() {
    while(scanf("%d", &n) == 1) {
        // 初始化
        for(int i=0;i<=maxn-5;++i){
            for(int j=0;j<=maxn-5;++j){
                d[i][j] = -1;
            }
        }
        for(int i = 1; i <= n; i++)
            scanf("%lf %lf", &x[i], &y[i]);

        // 任意两点之间的距离
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = std::sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])),
                dist[j][i] = dist[i][j];

        printf("%.2lf\n", dfs(1,1));
    }
    return 0;
}
