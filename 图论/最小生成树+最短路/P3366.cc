//
// Created by OFShare on 2019-09-23
//

#include <bits/stdc++.h>

const int maxn = 4e5 + 5;
// n个顶点, m条边
int n, m;
// 边的编号
int cnt = 0;
// head[i]: 记录是的i这个点，最后连接的一条边的编号
int head[maxn];
// 判断这个点是否已经被更新过啦
bool vis[maxn];
// dis[i]: 结点i到已访问标记的点集合的最短距离
int dis[maxn];
// 联通结点的个数
int number_union = 0;

// 邻接链表(或者叫链式前向星)
struct edge {
    int v, w, next;
}A[maxn];

void addEdge(int u, int v, int w) {
    A[++cnt].v = v;
    A[cnt].w = w;
    A[cnt].next = head[u];
    head[u] = cnt;
}

int prim(int start_) {
    int sum_ = 0;
    int number_ = 0;
    dis[start_] = 0;
    // 优先队列,保存的是(距离,点的坐标),这样取队列的top时，才是距离最短的点.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int > >, std::greater<std::pair<int, int> > > que;
    que.push({dis[start_], start_});
    while (!que.empty() && number_ != n) {
        int d = que.top().first, u = que.top().second;
        que.pop();
        // 因为一个点可能被多次入队, 如一个构成三角形的三个点
        if(vis[u]) continue;
        vis[u] = true;
        sum_ += d;
        number_ += 1;
        // 更新其他未被标记的点
        for (int i = head[u]; i != -1; i = A[i].next) {
            if (!vis[A[i].v] && A[i].w < dis[A[i].v]) {
                dis[A[i].v] = A[i].w;
                que.push({A[i].w, A[i].v});
            }
        }
    }
    number_union = number_;
    return sum_;
}

int main() {
    memset(head, -1, sizeof head);
    memset(dis, 0x3f3f3f, sizeof dis);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int ans = prim(1);
    if (number_union == n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += dis[i];
        }
        assert(ans == sum);
        printf("%d\n", sum);
    }
    else
        printf("orz\n");
    return 0;
}
