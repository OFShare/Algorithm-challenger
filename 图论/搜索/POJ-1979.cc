/*
 * Created by OFShare on 2019-10-28
 *
 */

#include <cstdio>
#include <cstring>

const int maxn = 20 + 5;
// 向下为x轴正方向, 向右为y轴正方向
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int w, h;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int dp[maxn][maxn];

// 从(x, y)出发能够遍历的最多的black tile.
int dfs(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    vis[x][y] = true;
    int sum = 1;
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i], new_y = y + dy[i];
        // 不能越界, 没有访问过且是a black tile
        if (new_x >= 1 && new_x <= h && new_y >=1 && new_y <= w && !vis[new_x][new_y] && mp[new_x][new_y] == '.') {
            sum += dfs(new_x, new_y);
        }
    }
    return dp[x][y] = sum;
}

int main() {
    while (scanf("%d %d", &w, &h) && (w + h)) {
        // 初始化
        std::memset(dp, -1, sizeof dp);
        std::memset(vis, 0, sizeof vis);
        for (int i = 1; i <= h; ++i) {
            scanf("%s", mp[i] + 1);
        }
        int start_x, start_y;
        // 找到起点, 横着是y, 竖着是x
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (mp[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
        }
        dfs(start_x, start_y);
        printf("%d\n", dp[start_x][start_y]);
    }
    return 0;
}
