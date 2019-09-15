//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n;
// 二维矩阵前缀和
// sum[i][j]记录的是, 矩阵左上角(1, 1)到右下角(i, j)的和
int sum[maxn][maxn];
// A[i][j]记录的是每一行的前缀和,即第i行前j个元素的和
int A[maxn][maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &A[i][j]);
            A[i][j] += A[i][j - 1];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i - 1][j];
            sum[i][j] += A[i][j];
        }
    }

    int ans = -1e9;
    // 枚举矩阵的左上角点，以及宽度和高度
    for(int x = 1; x <= n; ++x) {
        for(int y = 1; y <= n; ++y) {
            for(int width = 0; x + width <= n; ++width) {
                for(int height = 0; y + height <= n; ++height) {
                    ans = std::max(ans, sum[x + width][y + height] - sum[x + width][y - 1] - sum[x - 1][y + height] + sum[x - 1][y - 1]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
