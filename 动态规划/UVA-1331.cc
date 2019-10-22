/*
 * Created by OFShare on 2019-10-20
 *
 */

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 50 + 5;
const double eps = 0.00001;
int n, m;
struct Point {
    int x, y;
    friend Point operator-(const Point &lhs, const Point &rhs) {
        return {rhs.x - lhs.x, rhs.y - lhs.y};
    }
    // 公式: a(x1, y1) * b(x2, y2) = x1 * y2 - x2 * y1;
    friend double operator*(const Point &lhs, const Point &rhs) {
        return std::abs(lhs.x * rhs.y - lhs.y * rhs.x) * 1.0;
    }
}A[maxn];

// 判断顶点i, 顶点j, 顶点k, 组成的三角形是否合法(即内部没有其他顶点)
// 合法就返回面积, 非法返回0
// 判断是否合法:
//  判断是否有一个点在三角形内部, 如果一个点在内部, 三角形的三个端点连接内部这个点, 将面积分为了3部分,
//  判断这3部分相加是否等于原三角形面积. 相等说明有点在内部.

// 叉积算三角形的面积
double area(int i, int j, int k) {
    Point a = A[k] - A[i];
    Point b = A[k] - A[j];
    // 四边形面积除以2便是三角形的面积
    return a * b * 1.0 / 2;
}

double is_valid(int i, int j, int k) {
    for (int p = 1; p <= m; ++p) {
        if (!(p == i || p == j || p == k)) {
            double area_S = area(i, j, k);
            double area_1 = area(i, j, p);
            double area_2 = area(i, k, p);
            double area_3 = area(k, j, p);
            // 非法
            if (std::fabs(area_S - (area_1 + area_2 + area_3)) < eps)
                return 0;
        }
    }
    // 合法
    return area(i, j, k);
}

// dp[i][j]: 表示从i, i + 1, i + 2, ... , j,(看成一个圈, j的下一个元素为i, 即i和j相邻), 这些顶点中所剖分的三角形中, 最大三角形面积的最小值
double dp[maxn][maxn];
double dfs(int L, int R) {
    // 记忆化
    if (dp[L][R] != -1)
        return dp[L][R];
    // 递归的边界
    if (std::abs(R- L) <= 2)
        return dp[L][R] = area(L, L + 1, R);
    double ret = INF;
    for (int k = L + 1; k < R; ++k) {
        if (is_valid(L, R, k)) {
            ret = std::min(ret, std::max(dfs(L, k), std::max(area(L, R, k), dfs(k, R))));
        }
    }
    return dp[L][R] = ret;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        // 初始化
        for (int i = 0; i < maxn; ++i)
            std::fill(dp[i], dp[i] + maxn, -1);
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &A[i].x, &A[i].y);
        }
        printf("%.1lf\n", dfs(1, m));
    }
    return 0;
}
