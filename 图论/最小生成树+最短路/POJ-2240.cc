//
// Created by OFShare on 2019-10-03
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

const int maxn = 2 * 30 + 5;
const int INF = 1e9;
int t, n, m, cnt, start_;
double init_money;
// dis[i]: 表示从源点到结点i的最大能获得的货币价值
double dis[maxn];
int head[maxn];
std::string name[maxn];
std::map<std::string, int > mp;

// 边
struct edge {
    int v;
    double w;
    int next;
}A[maxn * maxn];

void addEdge(int u, int v, double w) {
    A[++cnt].v = v;
    A[cnt].w = w;
    A[cnt].next = head[u];
    head[u] = cnt;
}

int Bellman_Ford(int start_) {
    // 记录while循环执行的次数, 如果没有正权回路最多执行(顶点个数 - 1)次, 当是一条链的时候
    int number = 0;
    dis[start_] = init_money;
    while (true) {
        bool update = false;
        // 枚举所有边
        for (int u = 1; u <= n; ++u) {
            for (int i = head[u]; i != -1; i = A[i].next) {
                int v = A[i].v;
                double w = A[i].w;
                // 求的是最大能获得的资本, 大于才更新
                if (dis[u] * w > dis[v]) {
                    dis[v] = dis[u] * w;
                    update = true;
                }
            }
        }
        if (!update) break;
        ++number;
        if (number > n) break;
    }
    // 没有
    if (number <= n -1) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) && n) {
        // 初始化
        cnt = 0;
        // 自己随意定的, 不影响答案
        init_money = 100.0;
        std::memset(head, -1, sizeof head);
        std::fill(dis, dis + maxn, 0);
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            char tmp_name[101];
            scanf("%s", tmp_name);
            std::string tmp(tmp_name);
            mp.insert(std::make_pair(tmp, i));
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            char tmp1[101], tmp2[101];
            double w;
            //std::cin >> start_ >> w >> end_;
            scanf("%s %lf %s", tmp1, &w, tmp2);
            std::string start_(tmp1), end_(tmp2);
            addEdge(mp[start_], mp[end_], w);
        }
        // 源点
        start_ = 1;
        int ret = Bellman_Ford(start_);
        if (ret == 0) {
            printf("Case %d: No\n", ++kase);
        } else {
            printf("Case %d: Yes\n", ++kase);
        }
    }
    return 0;
}
