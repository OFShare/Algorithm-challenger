/*
 * Created by OFShare on 2019-10-29
 *
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>

const int INF = 1e9;
const int maxn = 20 + 5;
int w, h;
int start_x, start_y;
int end_x, end_y;
int mp[maxn][maxn];
int ans;

// 从源点走到(x, y)需要的最少的移动次数
void dfs(int x, int y, int distance) {
    // 递归边界, 剪枝
    if (distance > 10)
        return ;
    if (x == end_x && y == end_y)
        ans = std::min(ans, distance);
    for (int i = 1; i <= 4; ++i) {
        // 能不能往一个方向走的标志
        bool can_move = false;
        switch(i) {
            // 向下
            case 1:
                for (int k = x + 1; k <= h; ++k) {
                    if (mp[k][y] == 3) {
                        assert(k == end_x && y == end_y);
                        ans = std::min(ans, distance + 1);
                        return ;
                    } else if (mp[k][y] == 0 || mp[k][y] == 2) {
                        // 从边界走出去了
                        if (k == h) {
                            break ;
                        }
                        can_move = true;
                        continue;
                    } else if (mp[k][y] == 1 && can_move) {
                        // 碰到了block, 将它变为0, 在递归搜索下去
                        mp[k][y] = 0;
                        dfs(k - 1, y, distance + 1);
                        // 回溯
                        mp[k][y] = 1;
                        break;
                    } else
                        break;
                }
                break;
            // 向上
            case 2:
                for (int k = x - 1; k >= 1; --k) {
                    if (mp[k][y] == 3) {
                        assert(k == end_x && y == end_y);
                        ans = std::min(ans, distance + 1);
                        return ;
                    } else if (mp[k][y] == 0 || mp[k][y] == 2) {
                        // 从边界走出去了
                        if (k == h) {
                            break ;
                        }
                        can_move = true;
                        continue;
                    } else if (mp[k][y] == 1 && can_move) {
                        // 碰到了block, 将它变为0, 在递归搜索下去
                        mp[k][y] = 0;
                        dfs(k + 1, y, distance + 1);
                        // 回溯
                        mp[k][y] = 1;
                        break;
                    } else
                        break;
                }
                break;
            // 向左
            case 3:
                for (int u = y - 1; u >= 1; --u) {
                    if (mp[x][u] == 3) {
                        assert(x == end_x && u == end_y);
                        ans = std::min(ans, distance + 1);
                        return ;
                    } else if (mp[x][u] == 0 || mp[x][u] == 2) {
                        // 从边界走出去了
                        if (u == 1) {
                            break ;
                        }
                        can_move = true;
                        continue;
                    } else if (mp[x][u] == 1 && can_move) {
                        // 碰到了block, 将它变为0, 在递归搜索下去
                        mp[x][u] = 0;
                        dfs(x, u + 1, distance + 1);
                        // 回溯
                        mp[x][u] = 1;
                        break;
                    } else
                        break;
                }
                break;
            // 向右
            case 4:
                for (int u = y + 1; u <= w; ++u) {
                    if (mp[x][u] == 3) {
                        assert(x == end_x && u == end_y);
                        ans = std::min(ans, distance + 1);
                        return ;
                    } else if (mp[x][u] == 0 || mp[x][u] == 2) {
                        // 从边界走出去了
                        if (u == w) {
                            break ;
                        }
                        can_move = true;
                        continue;
                    } else if (mp[x][u] == 1 && can_move) {
                        // 碰到了block, 将它变为0, 在递归搜索下去
                        mp[x][u] = 0;
                        dfs(x, u - 1, distance + 1);
                        // 回溯
                        mp[x][u] = 1;
                        break;
                    } else
                        break;
                }
                break;
        }
    }
}

int main() {
#ifdef Acui
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    while (scanf("%d %d", &w, &h) && (w + h)) {
        ans = INF;
        // 输入以及记录起点, 终点坐标
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                scanf("%d", &mp[i][j]);
                if (mp[i][j] == 2) {
                    start_x = i;
                    start_y = j;
                }
                if (mp[i][j] == 3) {
                    end_x = i;
                    end_y = j;
                }
            }
        }
        //printf("start_x: %d, start_y: %d\n", start_x, start_y);
        //printf("end_x: %d, end_y: %d\n", end_x, end_y);
        dfs(start_x, start_y, 0);
        if (ans <= 10) {
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
