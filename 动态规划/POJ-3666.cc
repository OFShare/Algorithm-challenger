//
// created by OFShare on 2019-08-03
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int INF = 1e9;
const int maxn = 2e3+10;
int n;
int A[maxn],B[maxn];
int dp[maxn][maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&A[i]);
        B[i] = A[i];
    }
    // 将数组Ａ复制到Ｂ，然后对Ｂ数组排序
    // poj的编译器不支持-std=c++11，所以用不了std::copy_n函数
    // std::copy_n(A+1,n,B+1);
    std::sort(B+1,B+1+n);

    for(int i=1;i<=n;++i){
        // min_ 记录的是上一层从１到ｊ的最小值
        int min_ = INF;
        for(int j=1;j<=n;++j){
            dp[i][j] = INF;
            min_ = std::min(min_,dp[i-1][j]);
            dp[i][j] = std::min(dp[i][j], min_ + std::abs(A[i]-B[j]));
        }
    }
    int ans = *std::min_element(dp[n]+1,dp[n]+1+n);
    printf("%d",ans);
    return 0;
}
