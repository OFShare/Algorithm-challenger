//
// Created by OFShare on 2019-09-10
//

#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
int n, k;
int A[maxn];
// canNumber[i]记录可以变成i这个数，的个数
int canNumber[maxn];
// cntNumber[i][j]记录变成i时需要j次操作，的个数
int cntNumber[maxn][30];

void preprocess(int x) {
    int cnt = 0;
    while(x){
        canNumber[x]++;
        cntNumber[x][cnt]++;
        x /= 2;
        cnt++;
    }
    canNumber[0]++;
    cntNumber[x][cnt]++;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &A[i]);
        preprocess(A[i]);
    }
    int ans = 1e9;
    // 枚举最后k个相等的数为i时
    for(int i = 0; i <= 2e5; ++i) {
        if(canNumber[i] >= k) {
            int sum = 0, number = 0;
            for(int j = 0; j <= 30; ++j) {
                // 一个一个的贡献
                while(cntNumber[i][j] > 0 && number < k) {
                    cntNumber[i][j]--;
                    number++;
                    sum += j;
                }
                if(number == k) break;
            }
            ans = std::min(ans, sum);
        }
    }
    printf("%d", ans);
    return 0;
}
