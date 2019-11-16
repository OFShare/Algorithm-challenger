/*
 * Created by OFShare on 2019-10-31
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e2 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int h, w;
bool vis[maxn][maxn];
char mp[maxn][maxn];

// 从(x, y)遍历和它一样的区域, 并把它标志为vis[x][y] = true;
void dfs(int x, int y) {
    vis[x][y] = true;
    // 枚举4个方向
    for (int i = 0; i < 4; ++i) {
        int newx = x + dx[i], newy = y + dy[i];
        // 不能越界, 没有访问过, 是一样的
        if (newx >= 1 && newx <= h && newy >= 1 && newy <= w && !vis[newx][newy] && mp[newx][newy] == mp[x][y]) {
            dfs(newx, newy);
        }
    }
}
int main() {
    while (scanf("%d %d", &h, &w) && (h + w)) {
        // 初始化
        std::memset(vis, 0, sizeof vis);
        int cnt = 0;

        for (int i = 1; i <= h; ++i) {
            scanf("%s", mp[i] + 1);
        }
        // dfs的次数便是答案
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (!vis[i][j]) {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
