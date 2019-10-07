//
// Created by OFShare on 2019-10-04
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>

const int maxn = 3e2 + 5;
const int INF = 1e9;
// double 不要用std::memset初始化为无穷大, 可以改用std::fill
double dis[maxn][maxn];
int row = 1, n;
// 存放所有点 坐标: 图中编号
std::map<std::pair<int, int>, int> mp;
// 存放每一行
std::vector<std::pair<int, int> > G[maxn];

double l2distance(const std::pair<int, int> &src, const std::pair<int, int> &des) {
    double tmp = (src.first - des.first) * (src.first - des.first) + (src.second - des.second) * (src.second - des.second);
    return std::sqrt(tmp);
}

// 建图
void preprocess() {
    // 结点的编号
    int cnt = 1;
    for (int i = 1; i <= row; ++i) {
        for (int j = 0; j < G[i].size() - 1; ++j) {
            std::pair<int, int> u_ = G[i][j];
            std::pair<int, int> v_ = G[i][j + 1];
            int u = mp[u_], v = mp[v_];
            dis[u][v] = dis[v][u] = l2distance(u_, v_) * 1.0 / 40000.0;
        }
    }
    for (std::map<std::pair<int, int>, int>::iterator i = mp.begin(); i != mp.end(); ++i) {
        for (std::map<std::pair<int, int>, int>::iterator j = mp.begin(); j != mp.end(); ++j) {
            int u = i->second, v = j->second;
            if (dis[u][v] > INF || dis[v][u] > INF) {
                dis[u][v] = dis[v][u] = l2distance(i -> first, j -> first) * 1.0 / 10000.0;
            }
        }
    }
}

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
#ifdef OFShare
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    for (int i = 0; i < maxn; ++i) {
        std::fill(dis[i], dis[i] + maxn, INF + 5);
    }
    // 起点和终点
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    mp.insert({{x1, y1}, 1});
    mp.insert({{x2, y2}, 2});

    int x, y, cnt = 2;
    while (scanf("%d %d", &x, &y) != EOF) {
        if (x == -1 && y == -1) {
            ++row;
            continue;
        }
        G[row].push_back({x, y});
        if (mp.count({x, y}) == 0)
            mp.insert({{x, y}, ++cnt});
    }
    row -= 1;
    // 总的结点个数
    n = cnt;
    preprocess();
    Floyd();
    // 因为答案要的是分钟, 所以乘以60.0
    printf("%d\n", (int)(dis[1][2]* 60.0 + 0.5));
    return 0;
}
