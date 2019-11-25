/*
 * Created by OFShare on 2019-10-16
 *
 */

#include <bits/stdc++.h>

const int maxn = 1500 + 5;
int n, m;
// (dx[i], dy[i])代表往一个方向移动时, 走的单位坐标
// 比如你在(5, 5)这个坐标往右走一个单位, 即(5, 5) + (dx[0], dy[0]) = (6, 5)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
// vis[i][j]: 记录这个点是否被访问过
bool vis[maxn][maxn];
char A[maxn][maxn];

// mp保存的是映射的点(x, y)即(0 <= x <= n - 1, 0 <= y <= m - 1) ----> 这个点(x, y)可以从那些实际的点走过来
// 例如mp[{0, 0}] = {-3, -3}; 表示(0, 0)这个点可以走到(-3, -3), (-3, -3)对应的映射坐标为(0, 0)
// 即你在其中一个迷宫走到了(x,y)(例子中的(0, 0))这个点，在另一个迷宫也走到了(x,y)(例子中的(-3, -3))这个点
//std::map<std::pair<int, int>, std::pair<int, int> > mp;
std::pair<int, int> mp[maxn][maxn];

bool bfs(int start_x, int start_y) {
    // std::memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vis[i][j] = false;
        }
    }
    // mp.clear();
    // 队列
    std::queue<std::pair<int, int> > que;
    que.push({start_x, start_y});
    vis[start_x][start_y] = true;
    mp[start_x][start_y] = {start_x, start_y};

    // 注意队列里保存的都是实际在图上的坐标的点
    // 比如一个点(0, 0)往上走5个单位, 就变为(0, -5)了
    while (!que.empty()) {
        // 出队列
        int x = que.front().first, y = que.front().second;
        que.pop();
        // 枚举可能走的4个方向
        for (int i = 0; i < 4; ++i) {
            // (newx, newy)是映射之后的点
            // (newx_real, newy_real)是实际在图上的坐标的点
            int newx = (x + dx[i] + 100 * n ) % n, newy = (y + dy[i] + 100 * m) % m;
            int newx_real = (x + dx[i] ), newy_real = (y + dy[i]);
            // 如果这个点是道路, 且没有被访问过
            if (A[newx][newy] == '.' && !vis[newx][newy]) {
                que.push({newx_real, newy_real});
                vis[newx][newy] = true;
                mp[newx][newy] = {newx_real, newy_real};
            }
            // 如果这个点是二次访问, 且来自不同的实际的坐标, 就可以走出去了
            else if (vis[newx][newy]) {
                auto tmp = mp[newx][newy];
                if (tmp.first != newx_real || tmp.second != newy_real)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        // 记录起点坐标
        int start_x, start_y;
        for (int i = 0; i < n; ++i) {
            scanf("%s", A[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
        }
        if (bfs(start_x, start_y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
